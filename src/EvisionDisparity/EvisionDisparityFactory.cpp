#include "EvisionDisparityFactory.h"
#include "StereoMatchView.h"
EvisionDisparityFactory::EvisionDisparityFactory()
{
}

QWidget* EvisionDisparityFactory::CreateEvisionDisparity(QWidget* parent)
{
	StereoMatchView* _matchview = new StereoMatchView(parent);
	return _matchview;
}
