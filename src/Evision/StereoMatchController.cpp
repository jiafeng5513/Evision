#include "StereoMatchController.h"
#include <QMessageBox>
#include <QFileDialog>
#include "StereoMatch.h"

StereoMatchController::StereoMatchController(QObject *parent)
	: QObject(parent)
{
	m_entity = StereoMatchParamEntity::getInstance();
}

StereoMatchController::~StereoMatchController()
{
}
//命令:匹配默认参数
void StereoMatchController::setDefaultMatchParamCommand()
{
	if (m_entity->getBM())
	{
		m_entity->setPrefilcap(31);
		m_entity->setSadWinsz(51);
		m_entity->setMinDisp(0);
		m_entity->setNumDisparities(144);
		m_entity->setUniradio(15);
		m_entity->setSpecwinsz(100);
		m_entity->setSpecrange(32);
		m_entity->setTextThread(10);
		m_entity->setMaxdifdisp12(1);
	}
	else if (m_entity->getSGBM())
	{
		m_entity->setMinDisp(0);
		m_entity->setUniradio(10);
		m_entity->setSpecwinsz(100);
		m_entity->setNumDisparities(144);
		m_entity->setSpecrange(32);
		m_entity->setPrefilcap(63);
		m_entity->setSadWinsz(25);
		m_entity->setMaxdifdisp12(1);
		m_entity->setMODE_HH(true);
	}
	else if (m_entity->getMODE_HH())
	{
		m_entity->setMinDisp(-64);
		m_entity->setNumDisparities(64);
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("没有选择匹配算法"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}
//命令:匹配
void StereoMatchController::MatchCommand()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片"));
	fileDialog->setNameFilter(QStringLiteral("图片文件(*.jpg *.png *.jpeg)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		ImageL = fileDialog->selectedFiles().at(0);
		fileDialog->setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片"));
		if (fileDialog->exec() == QDialog::Accepted)
		{
			ImageR = fileDialog->selectedFiles().at(0);
			if (!ImageL.isEmpty() && !ImageR.isEmpty())
			{
				//两侧图片文件正常
				QFileDialog * fileDialog2 = new QFileDialog();
				fileDialog2->setWindowTitle(QStringLiteral("请选择内参文件"));
				fileDialog2->setNameFilter(QStringLiteral("YML/XML文件(*.yml *.yaml *.xml)"));
				fileDialog2->setFileMode(QFileDialog::ExistingFile);
				if (fileDialog2->exec() == QDialog::Accepted)
				{
					insFile = fileDialog2->selectedFiles().at(0);
					fileDialog2->setWindowTitle(QStringLiteral("请选择外参文件"));
					if (fileDialog2->exec() == QDialog::Accepted)
					{
						extFile = fileDialog2->selectedFiles().at(0);
						if (!insFile.isEmpty() && !extFile.isEmpty())
						{
							//内外参数文件正常
							StereoMatch *_stereoMatch = new StereoMatch(ImageL.toStdString(),
								ImageR.toStdString(), insFile.toStdString(), extFile.toStdString());
							connect(_stereoMatch, SIGNAL(openMessageBox(QString, QString)), this, SLOT(onOpenMessageBox(QString, QString)));
							_stereoMatch->start();

						}
						else
						{
							QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的内外参文件!"));
							return;
						}
					}
				}
				else
				{
					return;
				}

			}
			else
			{
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的两侧图片!"));
				return;
			}

		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}
//命令:刷新视差图
void StereoMatchController::RefreshStereoMatchCommand()
{
	StereoMatch *_stereoMatch = new StereoMatch(ImageL.toStdString(),
		ImageR.toStdString(), insFile.toStdString(), extFile.toStdString());
	connect(_stereoMatch, SIGNAL(openMessageBox(QString, QString)), this, SLOT(onOpenMessageBox(QString, QString)));
	_stereoMatch->start();
}
//消息响应:弹出对话框
void StereoMatchController::onOpenMessageBox(QString title, QString msg)
{
	QMessageBox::information(NULL, title, msg);
}
