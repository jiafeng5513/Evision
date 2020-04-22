#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONTRACEFACTORY_LIB Trace
#ifndef BUILD_STATIC
# if defined(EVISIONTRACEFACTORY_LIB)
#  define  EVISIONTRACEFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONTRACEFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONTRACEFACTORY_EXPORT
#endif
class EVISIONTRACEFACTORY EvisionTraceFactory
{
public:
	EvisionTraceFactory();
	static QWidget* CreateEvisionTraceView(QWidget* parent = Q_NULLPTR);
};