#pragma once

#include <QWidget>
#include "ui_WatchImage.h"
#include "QGraphicsView"
class MyGraphicsView:public QGraphicsView
{
	Q_OBJECT
public:
	void wheelEvent(QWheelEvent * event) override;
signals:
	void mouseWheelZoom(int delta);
};
class WatchImage : public QWidget
{
	Q_OBJECT

public:
	WatchImage(QWidget *parent = Q_NULLPTR);
	WatchImage(QString filename, QWidget *parent = Q_NULLPTR);
	~WatchImage();

private:
	Ui::WatchImage ui;
	QImage *image;
	MyGraphicsView *m_GraphicsView;
	float scaleFactor = 30;
public slots:
	void onMouseWheelZoom(int delta);
};
