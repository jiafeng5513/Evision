#pragma once

#include <QGraphicsView>
#include <core/core.hpp>



class RFScene : public  QGraphicsView
{
	Q_OBJECT

public:
	explicit RFScene(QWidget  *parent = 0);
	~RFScene();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	//void paintEvent(QPaintEvent * event);
	//void keyPressEvent(QKeyEvent *event);
signals:
	void mouseMove(int x, int y);
	void mouseLDown(int x, int y);
	void mouseRDown(int x, int y);
public slots:
};
