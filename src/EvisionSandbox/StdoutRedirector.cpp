/****************************************************************************
** Copyright (c) 2013 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
#include "StdoutRedirector.h"
#include <QUuid>
#include <QSocketNotifier>

#ifdef Q_OS_WIN
#include <qwindowspipereader_p.h>
#include <io.h>
#include <fcntl.h>
#else
#include <private/qringbuffer_p.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif

#ifdef Q_OS_WIN
static void createWinPipe(HANDLE &hRead, HANDLE &hWrite)
{
	QString pipeName = QString::fromLatin1("\\\\.\\pipe\\stdoutredirector-%1").arg(QUuid::createUuid().toString());
	SECURITY_ATTRIBUTES attributes = { sizeof(SECURITY_ATTRIBUTES), 0, false };
	hRead = ::CreateNamedPipe((wchar_t*)pipeName.utf16(), PIPE_ACCESS_INBOUND | FILE_FLAG_OVERLAPPED,
		PIPE_TYPE_BYTE | PIPE_WAIT, 1, 0, 1024 * 1024, 0, &attributes);

	SECURITY_ATTRIBUTES attributes2 = { sizeof(SECURITY_ATTRIBUTES), 0, true };
	hWrite = ::CreateFile((wchar_t*)pipeName.utf16(), GENERIC_WRITE,
		0, &attributes2, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

	::ConnectNamedPipe(hRead, NULL);
}
#endif

StdoutRedirector::StdoutRedirector(QObject *parent, ProcessChannels channels) :
	QObject(parent), m_channels(channels)
{
#ifdef Q_OS_WIN
	createWinPipe(hRead, hWrite);
	if (m_channels & StandardOutput)
		::SetStdHandle(STD_OUTPUT_HANDLE, hWrite);
	if (m_channels & StandardError)
		::SetStdHandle(STD_ERROR_HANDLE, hWrite);

	int fd = _open_osfhandle((intptr_t)hWrite, _O_WRONLY | _O_TEXT);
	if (m_channels & StandardOutput)
		_dup2(fd, 1);
	if (m_channels & StandardError)
		_dup2(fd, 2);
	_close(fd);

	pipeReader = new QWindowsPipeReader(this);
	pipeReader->setHandle(hRead);
	pipeReader->startAsyncRead();
	connect(pipeReader, SIGNAL(readyRead()), this, SIGNAL(readyRead()));
#else
	::pipe(pipeEnds);
	if (m_channels & StandardOutput)
		::dup2(pipeEnds[1], 1);
	if (m_channels & StandardError)
		::dup2(pipeEnds[1], 2);
	::close(pipeEnds[1]);

	buffer = new QRingBuffer();
	socketNotifier = new QSocketNotifier(pipeEnds[0], QSocketNotifier::Read, this);
	connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(onSocketActivated()));
#endif
}

StdoutRedirector::~StdoutRedirector()
{
#ifdef Q_OS_WIN
	pipeReader->stop();
	::DisconnectNamedPipe(hRead);
	//    ::CloseHandle(hWrite);
#else
	delete buffer;
#endif
}

qint64 StdoutRedirector::bytesAvailable() const
{
#ifdef Q_OS_WIN
	return pipeReader->bytesAvailable();
#else
	return buffer->size();
#endif
}

QByteArray StdoutRedirector::read(qint64 maxlen)
{
#ifdef Q_OS_WIN
	QByteArray result(int(maxlen), Qt::Uninitialized);
	qint64 readBytes = pipeReader->read(result.data(), result.size());
	if (readBytes <= 0)
		result.clear();
	else
		result.resize(int(readBytes));
	return result;
#else
	//return buffer->read(maxlen);
    buffer->read();
#endif
}

void StdoutRedirector::onSocketActivated()
{
#ifdef Q_OS_UNIX
	int bytesQueued;
	if (::ioctl(pipeEnds[0], FIONREAD, &bytesQueued) == -1)
		return;
	if (bytesQueued <= 0)
		return;
	char *writePtr = buffer->reserve(bytesQueued);
	int bytesRead = ::read(pipeEnds[0], writePtr, bytesQueued);
	if (bytesRead < bytesQueued)
		buffer->chop(bytesQueued - bytesRead);
	Q_EMIT readyRead();
#endif
}
