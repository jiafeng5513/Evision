#include "EvisionMonocularCalibFactory.h"
#include "MonocularCalibraterView.h"

EvisionMonocularCalibFactory::EvisionMonocularCalibFactory()
{
}

QWidget* EvisionMonocularCalibFactory::CreateEvisionMonocularCalibViewer(QWidget* parent)
{
	MonocularCalibraterView* m_MonocularCalibrate = new MonocularCalibraterView(parent);
	return m_MonocularCalibrate;
}
