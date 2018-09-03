#include "CustomGraphicsView.h"
#include "QMouseEvent"
CustomGraphicsView::CustomGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
}
//鼠标击键事件
void CustomGraphicsView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::LeftButton)
	{
		emit mouseLDown(event->pos().x(), event->pos().y());
	}
	if (event->button() == Qt::MouseButton::RightButton)
	{
		emit mouseRDown(event->pos().x(), event->pos().y());
	}
}
//鼠标移动事件
void CustomGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
	emit mouseMove(event->pos().x(), event->pos().y());
}
