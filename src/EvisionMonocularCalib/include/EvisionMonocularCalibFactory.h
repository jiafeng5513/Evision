#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
//EVISIONCALIBRATEFACTORY_LIB
//EvisionMonocularCalib
//EVISIONMONOCULARCALIB FACTORY_LIB
#ifndef BUILD_STATIC
# if defined(EVISIONMONOCULARCALIBFACTORY_LIB)
#  define  EVISIONMONOCULARCALIBFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONMONOCULARCALIBFACTORY Q_DECL_IMPORT
# endif
#else
# define EVISIONMONOCULARCALIBFACTORY_EXPORT
#endif
class EVISIONMONOCULARCALIBFACTORY EvisionMonocularCalibFactory
{
public:
	EvisionMonocularCalibFactory();
	static QWidget* CreateEvisionMonocularCalibViewer(QWidget* parent = Q_NULLPTR);
};