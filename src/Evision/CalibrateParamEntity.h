#pragma once

#include <QObject>
#include <core/mat.hpp>

class CalibrateParamEntity : public QObject
{
	Q_OBJECT

public:
	static CalibrateParamEntity *getInstance();
	~CalibrateParamEntity();
private:
	CalibrateParamEntity(QObject *parent = 0);

private:

#pragma region params
	int BoardWidth = 0;
	int BoardHeight = 0;
	int SquareSize = 0;
	bool showRectified = false;
	bool Bouguet = false;
	bool Hartley = false;
	cv::Mat imgLtoShow, imgRtoShow;
	QString msgBuffer="";
#pragma endregion 

#pragma region param_Changed_signals
signals:
	void paramChanged_BoardWidth();
	void paramChanged_BoardHeight();
	void paramChanged_SquareSize();
	void paramChanged_showRectified();
	void paramChanged_Bouguet();
	void paramChanged_Hartley();
	void paramChanged_ImageLtoShow();
	void paramChanged_ImageRtoShow();
	void paramChanged_msgBuffer();
#pragma endregion 

#pragma region getter And setter
public:
	int getBoardWidth();
	void setBoardWidth(int value);

	int getBoardHeight();
	void setBoardHeight(int value);

	int getSquareSize();
	void setSquareSize(int value);

	bool getshowRectified();
	void setshowRectified(bool value);

	bool getBouguet();
	void setBouguet(bool value);

	bool getHartley();
	void setHartley(bool value);

	cv::Mat getImageLtoShow();
	void setImageLtoShow(cv::Mat value);

	cv::Mat getImageRtoShow();
	void setImageRtoShow(cv::Mat value);

	QString getmsgBuffer();
	void setmsgBuffer(QString value);
#pragma endregion 
};
