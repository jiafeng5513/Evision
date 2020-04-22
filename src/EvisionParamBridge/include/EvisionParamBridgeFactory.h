#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONPARAMBRIDGEFACTORY_LIB ParamBridge
#ifndef BUILD_STATIC
# if defined(EVISIONPARAMBRIDGEFACTORY_LIB)
#  define  EVISIONPARAMBRIDGEFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONPARAMBRIDGEFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONPARAMBRIDGEFACTORY_EXPORT
#endif
class EVISIONPARAMBRIDGEFACTORY EvisionParamBridgeFactory
{
public:
	EvisionParamBridgeFactory();
	static QWidget* CreateEvisionParamBridgeView(QWidget* parent = Q_NULLPTR);
};