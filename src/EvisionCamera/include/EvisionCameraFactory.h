#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
#ifndef BUILD_STATIC
# if defined(EVISIONCAMERAFACTORY_LIB)
#  define  EVISIONCAMERAFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONCAMERAFACTORY_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISIONCAMERAFACTORY_EXPORT
#endif
class EVISIONCAMERAFACTORY_EXPORT EvisionCameraFactory
{
public:
	EvisionCameraFactory();
	static QWidget* CreateCameraView(QWidget* parent = Q_NULLPTR);
	static QWidget* CreateStereoCameraView(QWidget* parent = Q_NULLPTR);
};