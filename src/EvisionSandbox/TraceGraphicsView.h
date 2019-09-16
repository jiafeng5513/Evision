#pragma once

#include <QGraphicsView>

class TraceGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	TraceGraphicsView(QWidget *parent = Q_NULLPTR);
	~TraceGraphicsView();
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
signals:
	void mouseMove(int x, int y);
	void mouseLDown(int x, int y);
	void mouseRDown(int x, int y);
};
