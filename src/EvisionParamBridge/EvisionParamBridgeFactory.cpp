#include "EvisionParamBridgeFactory.h"
#include "CreateCameraParamFile.h"
EvisionParamBridgeFactory::EvisionParamBridgeFactory()
{
}

QWidget* EvisionParamBridgeFactory::CreateEvisionParamBridgeView(QWidget* parent)
{
	CreateCameraParamFile* m_createparams = new CreateCameraParamFile(parent);
	return m_createparams;
}
