#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>

#ifndef BUILD_STATIC
# if defined(REALSENSECAMERAFACTORY_LIB)
#  define  REALSENSECAMERAFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  REALSENSECAMERAFACTORY Q_DECL_IMPORT
# endif
#else
# define REALSENSECAMERAFACTORY_EXPORT
#endif
class REALSENSECAMERAFACTORY RealSenseCameraFactory
{
public:
	RealSenseCameraFactory();
	static QWidget* CreateRealSenseCameraView(QWidget* parent = Q_NULLPTR);
};