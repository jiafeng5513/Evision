#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONCAMERAFACTORY_LIB Camera
#ifndef BUILD_STATIC
# if defined(EVISIONCAMERAFACTORY_LIB)
#  define  EVISIONCAMERAFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONCAMERAFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONCAMERAFACTORY_EXPORT
#endif
class EVISIONCAMERAFACTORY EvisionCameraFactory
{
public:
	EvisionCameraFactory();
	static QWidget* CreateCameraView(QWidget* parent = Q_NULLPTR);
	static QWidget* CreateStereoCameraView(QWidget* parent = Q_NULLPTR);
};