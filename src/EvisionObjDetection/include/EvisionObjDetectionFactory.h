#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONOBJDETECTIONFACTORY_LIB
#ifndef BUILD_STATIC
# if defined(EVISIONOBJDETECTIONFACTORY_LIB)
#  define  EVISIONOBJDETECTIONFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONOBJDETECTIONFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONOBJDETECTIONFACTORY_EXPORT
#endif
class EVISIONOBJDETECTIONFACTORY EvisionObjDetectionFactory
{
public:
	EvisionObjDetectionFactory();
	static QWidget* CreateEvisionEvisionCloudViewer(QWidget* parent = Q_NULLPTR);
};
