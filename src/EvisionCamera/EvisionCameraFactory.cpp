#include "include/EvisionCameraFactory.h"
#include "CameraView.h"
#include "StereoCameraView.h"

EvisionCameraFactory::EvisionCameraFactory()
{
}

QWidget* EvisionCameraFactory::CreateCameraView(QWidget* parent)
{
	CameraView* m_Camera = new CameraView(parent);
	return m_Camera;
}

QWidget* EvisionCameraFactory::CreateStereoCameraView(QWidget* parent)
{
	StereoCameraView* m_Camera = new StereoCameraView(parent);
	return m_Camera;
}