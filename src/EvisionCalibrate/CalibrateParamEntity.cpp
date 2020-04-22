#include "CalibrateParamEntity.h"

CalibrateParamEntity::CalibrateParamEntity(QObject *parent)
	: QObject(parent)
{
}

CalibrateParamEntity* CalibrateParamEntity::getInstance()
{
	static CalibrateParamEntity *m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new CalibrateParamEntity();
	return m_pInstance;
}

CalibrateParamEntity::~CalibrateParamEntity()
{
}

int CalibrateParamEntity::getBoardWidth()
{
	return BoardWidth;
}

void CalibrateParamEntity::setBoardWidth(int value)
{
	BoardWidth = value;
	//发出值更改事件
	emit paramChanged_BoardWidth();
}

int CalibrateParamEntity::getBoardHeight()
{
	return BoardHeight;
}

void CalibrateParamEntity::setBoardHeight(int value)
{
	BoardHeight = value;
	emit paramChanged_BoardHeight();
}

int CalibrateParamEntity::getSquareSize()
{
	return SquareSize;
}

void CalibrateParamEntity::setSquareSize(int value)
{
	SquareSize = value;
	emit paramChanged_SquareSize();
}

bool CalibrateParamEntity::getCALIB_FIX_PRINCIPAL_POINT()
{
	return CALIB_FIX_PRINCIPAL_POINT;
}

void CalibrateParamEntity::setCALIB_FIX_PRINCIPAL_POINT(bool value)
{
	CALIB_FIX_PRINCIPAL_POINT = value;
	emit paramChanged_CALIB_FIX_PRINCIPAL_POINT();
}

bool CalibrateParamEntity::getCALIB_FIX_ASPECT_RATIO()
{
	return CALIB_FIX_ASPECT_RATIO;
}

void CalibrateParamEntity::setCALIB_FIX_ASPECT_RATIO(bool value)
{
	CALIB_FIX_ASPECT_RATIO = value;
	emit paramChanged_CALIB_FIX_ASPECT_RATIO();
}

bool CalibrateParamEntity::getCALIB_ZERO_TANGENT_DIST()
{
	return CALIB_ZERO_TANGENT_DIST;
}

void CalibrateParamEntity::setCALIB_ZERO_TANGENT_DIST(bool value)
{
	CALIB_ZERO_TANGENT_DIST = value;
	emit paramChanged_CALIB_ZERO_TANGENT_DIST();
}

bool CalibrateParamEntity::getCALIB_SAME_FOCAL_LENGTH()
{
	return CALIB_SAME_FOCAL_LENGTH;
}

void CalibrateParamEntity::setCALIB_SAME_FOCAL_LENGTH(bool value)
{
	CALIB_SAME_FOCAL_LENGTH = value;
	emit paramChanged_CALIB_SAME_FOCAL_LENGTH();
}

bool CalibrateParamEntity::getCALIB_FIX_K1()
{
	return CALIB_FIX_K1;
}

void CalibrateParamEntity::setCALIB_FIX_K1(bool value)
{
	CALIB_FIX_K1 = value;
	emit paramChanged_CALIB_FIX_K1();
}

bool CalibrateParamEntity::getCALIB_FIX_K2()
{
	return CALIB_FIX_K2;
}

void CalibrateParamEntity::setCALIB_FIX_K2(bool value)
{
	CALIB_FIX_K2 = value;
	emit paramChanged_CALIB_FIX_K2();
}

bool CalibrateParamEntity::getCALIB_FIX_K3()
{
	return CALIB_FIX_K3;
}

void CalibrateParamEntity::setCALIB_FIX_K3(bool value)
{
	CALIB_FIX_K3 = value;
	emit paramChanged_CALIB_FIX_K3();
}

bool CalibrateParamEntity::getCALIB_FIX_K4()
{
	return CALIB_FIX_K4;
}

void CalibrateParamEntity::setCALIB_FIX_K4(bool value)
{
	CALIB_FIX_K4 = value;
	emit paramChanged_CALIB_FIX_K4();
}

bool CalibrateParamEntity::getCALIB_FIX_K5()
{
	return CALIB_FIX_K5;
}

void CalibrateParamEntity::setCALIB_FIX_K5(bool value)
{
	CALIB_FIX_K5 = value;
	emit paramChanged_CALIB_FIX_K5();
}

bool CalibrateParamEntity::getCALIB_FIX_K6()
{
	return CALIB_FIX_K6;
}

void CalibrateParamEntity::setCALIB_FIX_K6(bool value)
{
	CALIB_FIX_K6 = value;
	emit paramChanged_CALIB_FIX_K6();
}

bool CalibrateParamEntity::getCALIB_RATIONAL_MODEL()
{
	return CALIB_RATIONAL_MODEL;
}

void CalibrateParamEntity::setCALIB_RATIONAL_MODEL(bool value)
{
	CALIB_RATIONAL_MODEL = value;
	emit paramChanged_CALIB_RATIONAL_MODEL();
}

bool CalibrateParamEntity::getCALIB_THIN_PRISM_MODEL()
{
	return CALIB_THIN_PRISM_MODEL;
}

void CalibrateParamEntity::setCALIB_THIN_PRISM_MODEL(bool value)
{
	CALIB_THIN_PRISM_MODEL = value;
	emit paramChanged_CALIB_THIN_PRISM_MODEL();
}

bool CalibrateParamEntity::getCALIB_FIX_S1_S2_S3_S4()
{
	return CALIB_FIX_S1_S2_S3_S4 ;
}

void CalibrateParamEntity::setCALIB_FIX_S1_S2_S3_S4(bool value)
{
	CALIB_FIX_S1_S2_S3_S4 = value;
	emit paramChanged_CALIB_FIX_S1_S2_S3_S4();
}

bool CalibrateParamEntity::getCALIB_TILTED_MODEL()
{
	return CALIB_TILTED_MODEL;
}

void CalibrateParamEntity::setCALIB_TILTED_MODEL(bool value)
{
	CALIB_TILTED_MODEL = value;
	emit paramChanged_CALIB_TILTED_MODEL();
}

bool CalibrateParamEntity::getCALIB_FIX_TAUX_TAUY()
{
	return CALIB_FIX_TAUX_TAUY;
}

void CalibrateParamEntity::setCALIB_FIX_TAUX_TAUY(bool value)
{
	CALIB_FIX_TAUX_TAUY = value;
	emit paramChanged_CALIB_FIX_TAUX_TAUY();
}

std::map<QString, cv::Mat>& CalibrateParamEntity::getItemMap()
{
	return itemMap;
}

void CalibrateParamEntity::insertItem(cv::Mat value)
{
	index++;
	itemMap.insert(std::pair<QString,cv::Mat >(QString::fromStdString(std::to_string(index)),value.clone()));
	emit paramChanged_InsertToItemMap();
}

void CalibrateParamEntity::clearItemMap()
{
	itemMap.clear();
	index = 0;
	emit paramChanged_ClearItemMap();
}

int CalibrateParamEntity::getIndex()
{
	return index;
}


