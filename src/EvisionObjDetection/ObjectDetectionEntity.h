#pragma once
#include <opencv2/opencv.hpp>
#include <QStringList>
#include <QObject>

class ObjectDetectionEntity : public QObject
{
	Q_OBJECT
public:
	static ObjectDetectionEntity* getInstance();
	~ObjectDetectionEntity();
private:
	ObjectDetectionEntity();
	cv::Mat DetectionPlayer;
	QString cfgFilename;
	QString weightsFilename;
	QString namesFilename;

	bool RunningState;
public:
	cv::Mat getDetectionPlayer();
	void setDetectionPlayer(cv::Mat value);

	QString getCfgFilename();
	void setCfgFilename(QString value);

	QString getweightsFilename();
	void setweightsFilename(QString value);

	QString getnamesFilename();
	void setnamesFilename(QString value);

	bool getRunningState();
	void setRunningState(bool value);
signals:
	void paramChanged_DetectionPlayer();
	void paramChanged_cfgFilename();
	void paramChanged_weightsFilename();
	void paramChanged_namesFilename();
	void paramChanged_RunningState();
};;

