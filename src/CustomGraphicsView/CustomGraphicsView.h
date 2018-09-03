#pragma once

#include <QtWidgets/QGraphicsView>
#include <QtUiPlugin/QDesignerExportWidget>
/*
 * 自定义的Designer插件,使用release版本编译成果后,会在脚本控制下自动完成注入
 * 注入脚本在解决方案文件夹/Scripts中
 * 使用debug编译,不会触发注入
 * 注意:注入脚本正确执行的前提是QtDesigner已经关闭
 * 
 * 信号槽的绑定可以在Desinger中完成
 * 
 * QDESIGNER_WIDGET_EXPORT这个宏的作用是把代码输出到lib中,如果不加这个,lib中就没有这个自定义类
 * 那样虽然也能在designer中使用插件,在代码中引用也正常,但是却无法链接.
 * 症状是在链接到达自定义类的构造函数时,会发生外部符号错误,link error 2019
 */

class QDESIGNER_WIDGET_EXPORT CustomGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	CustomGraphicsView(QWidget *parent = Q_NULLPTR);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
signals:
	void mouseMove(int x, int y);
	void mouseLDown(int x, int y);
	void mouseRDown(int x, int y);
};
