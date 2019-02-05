#pragma once

#include <QWidget>
#include "ui_WatchImageView.h"
#include "QGraphicsView"
class MyGraphicsView:public QGraphicsView
{
	Q_OBJECT
public:
	void wheelEvent(QWheelEvent * event) override;
signals:
	void mouseWheelZoom(int delta);
};
class WatchImageView : public QWidget
{
	Q_OBJECT

public:
	WatchImageView(QWidget *parent = Q_NULLPTR);
	WatchImageView(QString filename, QWidget *parent = Q_NULLPTR);
	~WatchImageView();

private:
	Ui::WatchImageView ui;
	QImage *image;
	MyGraphicsView *m_GraphicsView;
	float scaleFactor = 30;
public slots:
	void onMouseWheelZoom(int delta);
};
