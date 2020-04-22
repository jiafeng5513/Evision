#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONCALIBRATEFACTORY_LIB
#ifndef BUILD_STATIC
# if defined(EVISIONCALIBRATEFACTORY_LIB)
#  define  EVISIONCALIBRATEFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONCALIBRATEFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONCALIBRATEFACTORY_EXPORT
#endif
class EVISIONCALIBRATEFACTORY EvisionCalibrateFactory
{
public:
	EvisionCalibrateFactory();
	static QWidget* CreateEvisionCalibrateViewer(QWidget* parent = Q_NULLPTR);
};