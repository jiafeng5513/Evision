#include "EvisionCalibrateFactory.h"
#include "CalibraterView.h"

EvisionCalibrateFactory::EvisionCalibrateFactory()
{
}

QWidget* EvisionCalibrateFactory::CreateEvisionCalibrateViewer(QWidget* parent)
{
	CalibraterView* m_calibrate = new CalibraterView(parent);
	return m_calibrate;
}
