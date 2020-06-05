#include "MonocularCalibrateParamEntity.h"

MonocularCalibrateParamEntity::MonocularCalibrateParamEntity(QObject *parent)
	: QObject(parent)
{
}

MonocularCalibrateParamEntity* MonocularCalibrateParamEntity::getInstance()
{
	static MonocularCalibrateParamEntity *m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new MonocularCalibrateParamEntity();
	return m_pInstance;
}

MonocularCalibrateParamEntity::~MonocularCalibrateParamEntity()
{
}

int MonocularCalibrateParamEntity::getBoardWidth()
{
	return BoardWidth;
}

void MonocularCalibrateParamEntity::setBoardWidth(int value)
{
	BoardWidth = value;
	//发出值更改事件
	emit paramChanged_BoardWidth();
}

int MonocularCalibrateParamEntity::getBoardHeight()
{
	return BoardHeight;
}

void MonocularCalibrateParamEntity::setBoardHeight(int value)
{
	BoardHeight = value;
	emit paramChanged_BoardHeight();
}

int MonocularCalibrateParamEntity::getSquareSize()
{
	return SquareSize;
}

void MonocularCalibrateParamEntity::setSquareSize(int value)
{
	SquareSize = value;
	emit paramChanged_SquareSize();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_PRINCIPAL_POINT()
{
	return CALIB_FIX_PRINCIPAL_POINT;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_PRINCIPAL_POINT(bool value)
{
	CALIB_FIX_PRINCIPAL_POINT = value;
	emit paramChanged_CALIB_FIX_PRINCIPAL_POINT();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_ASPECT_RATIO()
{
	return CALIB_FIX_ASPECT_RATIO;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_ASPECT_RATIO(bool value)
{
	CALIB_FIX_ASPECT_RATIO = value;
	emit paramChanged_CALIB_FIX_ASPECT_RATIO();
}

bool MonocularCalibrateParamEntity::getCALIB_ZERO_TANGENT_DIST()
{
	return CALIB_ZERO_TANGENT_DIST;
}

void MonocularCalibrateParamEntity::setCALIB_ZERO_TANGENT_DIST(bool value)
{
	CALIB_ZERO_TANGENT_DIST = value;
	emit paramChanged_CALIB_ZERO_TANGENT_DIST();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K1()
{
	return CALIB_FIX_K1;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K1(bool value)
{
	CALIB_FIX_K1 = value;
	emit paramChanged_CALIB_FIX_K1();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K2()
{
	return CALIB_FIX_K2;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K2(bool value)
{
	CALIB_FIX_K2 = value;
	emit paramChanged_CALIB_FIX_K2();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K3()
{
	return CALIB_FIX_K3;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K3(bool value)
{
	CALIB_FIX_K3 = value;
	emit paramChanged_CALIB_FIX_K3();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K4()
{
	return CALIB_FIX_K4;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K4(bool value)
{
	CALIB_FIX_K4 = value;
	emit paramChanged_CALIB_FIX_K4();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K5()
{
	return CALIB_FIX_K5;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K5(bool value)
{
	CALIB_FIX_K5 = value;
	emit paramChanged_CALIB_FIX_K5();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_K6()
{
	return CALIB_FIX_K6;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_K6(bool value)
{
	CALIB_FIX_K6 = value;
	emit paramChanged_CALIB_FIX_K6();
}

bool MonocularCalibrateParamEntity::getCALIB_RATIONAL_MODEL()
{
	return CALIB_RATIONAL_MODEL;
}

void MonocularCalibrateParamEntity::setCALIB_RATIONAL_MODEL(bool value)
{
	CALIB_RATIONAL_MODEL = value;
	emit paramChanged_CALIB_RATIONAL_MODEL();
}

bool MonocularCalibrateParamEntity::getCALIB_THIN_PRISM_MODEL()
{
	return CALIB_THIN_PRISM_MODEL;
}

void MonocularCalibrateParamEntity::setCALIB_THIN_PRISM_MODEL(bool value)
{
	CALIB_THIN_PRISM_MODEL = value;
	emit paramChanged_CALIB_THIN_PRISM_MODEL();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_S1_S2_S3_S4()
{
	return CALIB_FIX_S1_S2_S3_S4 ;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_S1_S2_S3_S4(bool value)
{
	CALIB_FIX_S1_S2_S3_S4 = value;
	emit paramChanged_CALIB_FIX_S1_S2_S3_S4();
}

bool MonocularCalibrateParamEntity::getCALIB_TILTED_MODEL()
{
	return CALIB_TILTED_MODEL;
}

void MonocularCalibrateParamEntity::setCALIB_TILTED_MODEL(bool value)
{
	CALIB_TILTED_MODEL = value;
	emit paramChanged_CALIB_TILTED_MODEL();
}

bool MonocularCalibrateParamEntity::getCALIB_FIX_TAUX_TAUY()
{
	return CALIB_FIX_TAUX_TAUY;
}

void MonocularCalibrateParamEntity::setCALIB_FIX_TAUX_TAUY(bool value)
{
	CALIB_FIX_TAUX_TAUY = value;
	emit paramChanged_CALIB_FIX_TAUX_TAUY();
}

std::map<QString, cv::Mat>& MonocularCalibrateParamEntity::getItemMap()
{
	return itemMap;
}

void MonocularCalibrateParamEntity::insertItem(cv::Mat value)
{
	index++;
	itemMap.insert(std::pair<QString,cv::Mat >(QString::fromStdString(std::to_string(index)),value.clone()));
	emit paramChanged_InsertToItemMap();
}

void MonocularCalibrateParamEntity::clearItemMap()
{
	itemMap.clear();
	index = 0;
	emit paramChanged_ClearItemMap();
}

int MonocularCalibrateParamEntity::getIndex()
{
	return index;
}


