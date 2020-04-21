#include "EvisionObjDetectionFactory.h"
#include <ObjectDetectionView.h>

EvisionObjDetectionFactory::EvisionObjDetectionFactory()
{
}

QWidget* EvisionObjDetectionFactory::CreateEvisionEvisionCloudViewer(QWidget* parent)
{
	ObjectDetectionView* _ObjectDetectionView = new ObjectDetectionView(parent);
	return _ObjectDetectionView;
}
