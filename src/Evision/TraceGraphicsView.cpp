#include "TraceGraphicsView.h"
#include "QMouseEvent"
TraceGraphicsView::TraceGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
	setMouseTracking(true);
}

TraceGraphicsView::~TraceGraphicsView()
{
}

void TraceGraphicsView::mousePressEvent(QMouseEvent* event)
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

void TraceGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
	emit mouseMove(event->pos().x(), event->pos().y());
}
