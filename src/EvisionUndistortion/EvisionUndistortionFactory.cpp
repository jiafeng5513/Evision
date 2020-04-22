#include "EvisionUndistortionFactory.h"
#include "EvisionRectifyView.h"

EvisionUndistortionFactory::EvisionUndistortionFactory()
{
}

QWidget* EvisionUndistortionFactory::CreateEvisionUndistortionView(QWidget* parent)
{
	EvisionRectifyView* m_Rectify = new EvisionRectifyView(parent);
	return m_Rectify;
}
