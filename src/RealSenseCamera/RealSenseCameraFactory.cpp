#include "include/RealSenseCameraFactory.h"
#include "CameraView.h"

RealSenseCameraFactory::RealSenseCameraFactory()
{
}

QWidget* RealSenseCameraFactory::CreateRealSenseCameraView(QWidget* parent)
{
	CameraView* m_Camera = new CameraView(parent);
	return m_Camera;
}