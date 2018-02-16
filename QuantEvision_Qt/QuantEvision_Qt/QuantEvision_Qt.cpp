#include "QuantEvision_Qt.h"
#include "Calibration.h"
#include "Match.h"
#include "Reconstruction.h"
#include "Measurement.h"

QuantEvision_Qt::QuantEvision_Qt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//默认隐藏测距向导
	ui.dockWidget_RangeGuide->setHidden(true);
}
//启动/关闭测距向导
void QuantEvision_Qt::RangeGuide()
{
	if (ui.dockWidget_RangeGuide->isHidden())
	{
		ui.dockWidget_RangeGuide->setHidden(false);
		//测距向导已经显示,初始化测距功能
	}
	else
	{
		ui.dockWidget_RangeGuide->setHidden(true);
		//测距向导已经隐藏,注销测距功能
	}
}
//启动标定界面
void QuantEvision_Qt::ShowCalibrate()
{
	Calibration * _Calibration = new Calibration();
	ui.mdiArea->addSubWindow(_Calibration);
	_Calibration->show();
}
//启动匹配界面
void QuantEvision_Qt::ShowMatch()
{
	Match * _Match = new Match();
	ui.mdiArea->addSubWindow(_Match);
	_Match->show();
}
//启动三维重建界面
void QuantEvision_Qt::ShowReconstruct()
{
	Reconstruction * _Reconstruction = new Reconstruction();
	ui.mdiArea->addSubWindow(_Reconstruction);
	_Reconstruction->show();
}
//启动测距界面
void QuantEvision_Qt::ShowRange()
{
	Measurement * _Measurement = new Measurement();
	ui.mdiArea->addSubWindow(_Measurement);
	_Measurement->show();
}
