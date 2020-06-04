#include "EvisionPolyTrackerFactory.h"
#include "EvisionPolyTracker.h"
#include <QGLFormat>
#include <iostream>
EvisionPolyTrackerFactory::EvisionPolyTrackerFactory()
{
}

QWidget* EvisionPolyTrackerFactory::CreateEvisionPolyTrackerViewer(QWidget* parent)
{
	if (!QGLFormat::hasOpenGL()) {
		std::cout << "This system has no OpenGL support" << std::endl;  //redirect to log view
		return NULL;
	}
	EvisionPolyTracker * tracker = new EvisionPolyTracker(parent);
	return tracker;
}
