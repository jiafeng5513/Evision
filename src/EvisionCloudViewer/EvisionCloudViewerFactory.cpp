#include "EvisionCloudViewerFactory.h"
#include "CloudGLWidget.h"
#include <iostream>

EvisionCloudViewerFactory::EvisionCloudViewerFactory()
{
}

QWidget* EvisionCloudViewerFactory::CreateEvisionEvisionCloudViewer(std::string filename, QWidget* parent)
{
	if (!QGLFormat::hasOpenGL()) {
		std::cerr << "This system has no OpenGL support" << std::endl;
		return NULL;
	}

	CloudGLWidget *cube=new CloudGLWidget(filename,parent);
	cube->setWindowTitle(QObject::tr("Vowel Cube"));
	cube->setMinimumSize(200, 200);
	cube->resize(450, 450);
	return cube;
}
