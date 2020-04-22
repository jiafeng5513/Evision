#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONUNDISTORTIONFACTORY_LIB Undistortion
#ifndef BUILD_STATIC
# if defined(EVISIONUNDISTORTIONFACTORY_LIB)
#  define  EVISIONUNDISTORTIONFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONUNDISTORTIONFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONUNDISTORTIONFACTORY_EXPORT
#endif
class EVISIONUNDISTORTIONFACTORY EvisionUndistortionFactory
{
public:
	EvisionUndistortionFactory();
	static QWidget* CreateEvisionUndistortionView(QWidget* parent = Q_NULLPTR);
};