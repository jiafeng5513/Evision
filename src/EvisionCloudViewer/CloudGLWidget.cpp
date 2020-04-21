#include <QtGui>
#include <QtOpenGL>
#include <cmath>
#include <iostream>              
#include <string> 
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif

#include "CloudGLWidget.h"
#include "CloudAnalyzer.h"
#include <pcl/common/time.h>

/*
 * 1. 求解外包围盒
 * 2. 求解合适的缩放
 * 3. 通过型心求平移变换,把型心放到中间
 * 4. 着色
 *
 * 我需要显示的有:
 * 操作提示
 * 点数计数
 *
 *
 */
 //构造
CloudGLWidget::CloudGLWidget(std::string filename, QWidget *parent)
	: QGLWidget(parent)
{
	//调用setFormat（）使OpenGL的显示描述表支持饭走样。
	setFormat(QGLFormat(QGL::SampleBuffers));

	//初始化私有变量
	rotationX = -38.0;
	rotationY = -58.0;
	rotationZ = 0.0;
	scaling = 1.0;
	//平移控制
	transX = 0;
	transY = 0;
	transZ = -10;
	numofPoints = 0;
	this->filename = filename;
	//设置填充背景的QRadialGradient
	createGradient();
	//创建OpenGL对象
	createGLObject();

	setAutoBufferSwap(false);
	setAutoFillBackground(false);

	//this->numofPoints = 0;
	

}
//析构
CloudGLWidget::~CloudGLWidget()
{
	makeCurrent();
	//删除构造函数创建的OpenGL立方体对象
	glDeleteLists(glObject, 1);
}

//绘制,在paintEvent()中创建一个QPainter,在进行纯OpenGL操作时
//保存和恢复其状态。
//QPainter的构造函数(或者QPainter::begin())自动调用glClear
//除非预先调用窗口部件的setAutoFillBackground(false)
//QPainter的析构函数（或者QPainter::end()）自动调用QGLWidget::swapBuffers()
//切换可见缓存和离屏缓存，除非预先调用setAutoBufferSwap(false).
//当QPainter被激活，我们可以交叉使用纯OpenGL命令，只要在执行纯OpenGL命令之前保存OpenGL状态，之后恢复OpenGL状态
void CloudGLWidget::paintEvent(QPaintEvent * /* event */)
{
	QPainter painter(this);
	//绘制背景
	drawBackground(&painter);
	//背景绘制结束
	painter.end();
	//绘制立方体
	drawItem();
	//绘制开始
	painter.begin(this);
	//使用HTML文字设置QTextDocument对象
	drawLegend(&painter);
	painter.end();
	swapBuffers();
}

//鼠标按下事件:记录鼠标的位置
void CloudGLWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}

//鼠标移动事件:用于控制平移和旋转
void CloudGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
	GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();

	if (event->buttons() & Qt::LeftButton) {//左键
		rotationX -= 180 * dy;
		rotationY -= 180 * dx;
		update();
	}
	else if (event->buttons() & Qt::RightButton) {//右键
		transX += dx;
		transY -= dy;
		//rotationX += 180 * dy;
		//rotationZ += 180 * dx;
		update();
	}
	else if (event->buttons() & Qt::MiddleButton)//中键
	{
		//transZ += (5 / scaling)*std::min(dx,dy);
		////rotationX += 180 * dy;
		////rotationZ += 180 * dx;
		//update();
	}
	lastPos = event->pos();
}

//鼠标滚动的事件:用于控制缩放
void CloudGLWidget::wheelEvent(QWheelEvent *event)
{
	double numDegrees = -event->delta() / 8.0;
	double numSteps = numDegrees / 15.0;
	scaling *= std::pow(1.125, numSteps);
	update();
}

//使用蓝色渐变色设置QRadialGradient
void CloudGLWidget::createGradient()
{
	//确保指定的中心和焦点坐标根据窗口部件大小进行调整
	gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
	//位置用0和1之间的浮点数表示，0对应焦点坐标，1对应圆的边缘
	gradient.setCenter(0.45, 0.50);
	gradient.setFocalPoint(0.40, 0.45);
	gradient.setColorAt(0.0, QColor(105, 146, 182));
	gradient.setColorAt(0.4, QColor(81, 113, 150));
	gradient.setColorAt(0.8, QColor(16, 56, 121));
}

//创建待绘制的目标
void CloudGLWidget::createGLObject()
{
	makeCurrent();

	glShadeModel(GL_FLAT);

	glObject = glGenLists(1);
	glNewList(glObject, GL_COMPILE);
	qglColor(QColor(255, 239, 191));
	glLineWidth(1.0);

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	//打开点云文件"F:\\pcl\\test\\car6.pcd""C:\\Users\\Anna\\Desktop\\test.pcd"0_cloud
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(this->filename, *cloud) == -1)
	{
		PCL_ERROR("Couldn't read file,the file name is :\n");
		PCL_ERROR(this->filename.c_str());
		return;
	}


	glBegin(GL_POINTS);
	this->numofPoints = cloud->points.size();
	for (size_t i = 0; i < cloud->points.size(); ++i)
	{
		glVertex3f(cloud->points[i].x, cloud->points[i].y, cloud->points[i].z);
	}
	glEnd();

	CloudAnalyzer ca;
	this->bbox = ca.bbox(cloud);//得到外包围盒

	//	    V4 ---------- V6
	//        |\        |\
	//        | \_______|_\ V7
	//        | V5      | |
	//      V0|_|_ _ _ _|V2
	//        \ |       \ |
	//         \|________\|
	//         V1         V3

	//scaling = getScalingFactor(bbox);//获取缩放
	getTranslationV(bbox);//计算平移
	GLint index_list[][2] = { {0, 1},{2, 3},{4, 5},{6, 7},{0, 2},{1, 3},
							{4, 6},{5, 7},{0, 4},{1, 5},{7, 3},{2, 6} };
	glBegin(GL_LINES);
	for (int i = 0; i < 12; ++i) // 12 条线段
	{
		for (int j = 0; j < 2; ++j) // 每条线段 2个顶点
		{
			glVertex3f(bbox[index_list[i][j]][0], bbox[index_list[i][j]][1], bbox[index_list[i][j]][2]);
		}
	}
	glEnd();

	glEndList();
}

//背景的绘制
void CloudGLWidget::drawBackground(QPainter *painter)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(gradient);
	painter->drawRect(rect());
}

//绘制主体
void CloudGLWidget::drawItem()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	GLfloat x = 3.0 * GLfloat(width()) / height();
	//glOrtho(-x, +x, -3.0, +3.0, 4.0, 15.0);

	/*
	 * min_px bbox[0][0]
	 * min_py bbox[0][1]
	 * min_pz bbox[0][2]
	 * max_px bbox[1][0]
	 * max_py bbox[2][1]
	 * max_pz bbox[4][2]
	 */
	GLfloat min_i = std::min(std::min(bbox[0][0] - bbox[1][0], bbox[0][1] - bbox[2][1]), bbox[0][2] - bbox[4][2]);
	GLfloat max_i = std::max(std::max(bbox[1][0] - bbox[0][0], bbox[2][1] - bbox[0][1]), bbox[4][2] - bbox[0][2]);

	glOrtho(min_i, max_i, min_i, max_i, min_i, max_i);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glRotatef(rotationX, 1.0, 0.0, 0.0);//旋转
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);
	glScalef(scaling, scaling, scaling);//缩放
	glTranslatef(transX, transY, transZ);//平移

	//设置反走样
	glEnable(GL_MULTISAMPLE);

	//绘制立方体
	glCallList(glObject);

	//设置文字颜色和字体
	setFont(QFont("Times", 18));
	qglColor(QColor(255, 223, 127));

	//绘制字符，renderText使文字不变形
	for (int i = 0; i < 8; ++i)
	{
		renderText(bbox[i][0], bbox[i][1], bbox[i][2], QChar(i + 48));
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glPopAttrib();
}


//使用HTML文字设置QTextDocument对象，在半透明的蓝色矩形上绘制它们
void CloudGLWidget::drawLegend(QPainter *painter)
{
	const int Margin = 11;
	const int Padding = 6;

    QString text;
    text = QString().sprintf("<h4 align=\"center\">Point Cloud Viewer</h4>"
                             "<p align=\"center\"><table width=\"100%\">"
                             "<tr><td>numbers:<td>%d<td>"
                             "</table>", numofPoints);

	QTextDocument textDocument;
	textDocument.setDefaultStyleSheet("* { color: #FFEFEF }");
	textDocument.setHtml(text);
	textDocument.setTextWidth(textDocument.size().width());

	QRect rect(QPoint(0, 0), textDocument.size().toSize()
		+ QSize(2 * Padding, 2 * Padding));
	painter->translate(width() - rect.width() - Margin,
		height() - rect.height() - Margin);
	painter->setPen(QColor(255, 239, 239));
	painter->setBrush(QColor(255, 0, 0, 31));
	painter->drawRect(rect);

	painter->translate(Padding, Padding);
	textDocument.drawContents(painter);
}

GLfloat CloudGLWidget::getScalingFactor(std::vector<std::vector<float>> bbox)
{
	//1. 取窗口大小
	std::cout << width() << " , " << height() << std::endl;

	GLfloat target = std::sqrt(std::pow(width(), 2) + std::pow(height(), 2));
	//
//                
//	    V4 ---------- V6
//        |\        |\
//        | \_______|_\ V7
//        | V5      | |
//      V0|_|_ _ _ _|V2
//        \ |       \ |
//         \|________\|
//         V1         V3

	//2. 计算v0和v7的距离
	GLfloat dis = std::sqrt(std::pow(bbox[0][0] - bbox[7][0], 2) + std::pow(bbox[0][1] - bbox[7][1], 2)/*+ std::pow(bbox[0][2] - bbox[7][2], 2)*/);

	//3. some magic

	return 0.25*(target / dis);
}

void CloudGLWidget::getTranslationV(std::vector<std::vector<float>> bbox)
{
	//1. 计算几何中心
	GLfloat x = (bbox[0][0] + bbox[7][0]) / 2;
	GLfloat y = (bbox[0][1] + bbox[7][1]) / 2;
	GLfloat z = (bbox[0][2] + bbox[7][2]) / 2;
	//Eigen::Vector3f c1 = 0.5f*(min_p.getVector3fMap() + max_p.getVector3fMap());//几何中心
	//2. 计算平移向量
	this->transX = -x;
	this->transY = -y;
	this->transZ = -z;
}