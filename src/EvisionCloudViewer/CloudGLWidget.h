#ifndef VOWELCUBE_H
#define VOWELCUBE_H

#include <QGLWidget>
#include <QRadialGradient>
//使用OpenGL绘制立方体，使用QPainter绘制背景
//的渐变，接着使用renderText（）绘制立方体角上的8个
//元音字母，最后使用QPainter和QTextDocument绘制图例。
//用户可以单击并拖动鼠标来旋转立方体，并且可以使用鼠标滚轮进行放大或缩小
class CloudGLWidget : public QGLWidget
{
	Q_OBJECT

public:
	CloudGLWidget(std::string filename,QWidget *parent = 0);
	~CloudGLWidget();

protected:
	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;

private:
	void createGradient();
	void createGLObject();
	void drawBackground(QPainter *painter);
	void drawItem();
	void drawLegend(QPainter *painter);
	std::vector<std::vector<float>> getPointCloud(std::string filename);

	GLfloat getScalingFactor(std::vector<std::vector<float>> bbox);
	void getTranslationV(std::vector<std::vector<float>> bbox);
	void analyzeCloud();

	std::vector<std::vector<float>> bbox;
	std::string filename;
	GLfloat transX;
	GLuint glObject{};
	QRadialGradient gradient;
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;
	GLfloat transY;
	GLfloat transZ;
	GLfloat scaling;
	QPoint lastPos;
	int numofPoints{};
};

#endif