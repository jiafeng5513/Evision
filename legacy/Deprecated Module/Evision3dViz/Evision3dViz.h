#pragma once
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QWidget>
#include <QTreeWidgetItem>
#include <QTime>
#include "ui_Evision3dViz.h"

#include <vtkRenderWindow.h>
#include "QVTKWidget.h"
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/features/normal_3d.h>
#include <pcl/search/kdtree.h>
#include <pcl/surface/gp3.h>



typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class Evision3dViz : public QWidget
{
	Q_OBJECT
public:
	Evision3dViz(QWidget *parent = Q_NULLPTR);
	
private:
	struct MyCloud
	{
		PointCloudT::Ptr cloud;  
		std::string filename;  
		std::string subname;  
		std::string dirname = "";
		bool visible = true;  
	};

	Ui::Evision3dVizClass ui;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz;
	MyCloud mycloud;
	std::vector<MyCloud> mycloud_vec;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

	QString save_filename;
	long total_points = 0; //Total amount of points in the viewer

	unsigned int red = 255;
	unsigned int green = 255;
	unsigned int blue = 255;
	unsigned int p = 2;
	std::vector<int> pointcolor;
	std::vector<int> bgcolor;

	QVBoxLayout *layout;
	QTime time;
	int theme_id = 1; // 0: Windows theme, 1: Darcula theme
	bool enable_console = true; // console �Ŀ���״̬
	bool save_as_binary = false;
	QString time_cost = "0";  // ��¼ĳ������ִ�е�ʱ��
	QString windows_qss = "QWidget{ 	 	background-color: rgb(240, 240, 240); }  QDockWidget{ 	color: rgb(0, 0, 0);	 	background-color: rgb(240, 240, 240);  	border-color: rgb(63, 63, 70); 	border-top-color: rgb(0, 0, 0);	 	font: 10pt \"Microsoft YaHei UI\"; }  QTableWidget{	 	background-color: rgb(255, 255 ,255);	 	border-color: rgb(130, 135, 140); 	color: rgb(0, 0, 0); 	alternate-background-color: rgb(218, 218, 218); 	font: 9pt \"Microsoft YaHei UI\"; }  QTreeWidget{ 	background-color: rgb(255, 255 ,255);	 	border-color: rgb(130, 135, 140); 	color: rgb(0, 0, 0); 	alternate-background-color: rgb(218, 218, 218); 	font: 9pt \"Microsoft YaHei UI\"; }   QToolBar{ 	background-color: rgb(240, 240, 240); 	border-bottom: 1px solid #828790; }  QStatusBar{ 	color: rgb(0, 0, 0); 	font: 9pt \"Microsoft YaHei UI\"; }  QMenuBar{ 	background-color: rgb(240, 240, 240); 	color: rgb(0, 0, 0); 	font: 9pt \"Microsoft YaHei UI\"; 	border-bottom: 1px solid #828790; }  QMenuBar::item:selected{ 	background-color: rgb(205, 233, 255); 	 }  QMenu{ 	font: 9pt \"Microsoft YaHei UI\";	 	color: rgb(0, 0, 0); 	background-color: rgb(241, 241, 241); }  QMenu::item:selected{ 	background-color: rgb(145, 201, 247); }  QLabel{ 	color: rgb(0, 0, 0); 	font: 10pt \"Microsoft YaHei UI\"; }  QCheckBox{ 	color: rgb(0, 0, 0); 	font: 10pt \"Microsoft YaHei UI\"; }  QLCDNumber{ 	color: rgb(0, 0, 0); 	font: 10pt \"Microsoft YaHei UI\"; }  QPushButton{ 	color: rgb(0, 0, 0); 	 	background-color: rgb(226, 230, 234); } ";
	QString darcula_qss = "QWidget{ 	 	background-color: rgb(60, 63, 65); }  QDockWidget{ 	color: rgb(208, 208, 208);	 	background-color: rgb(60, 63, 65);  	border-color: rgb(63, 63, 70); 	border-top-color: rgb(255, 255, 255);	 	font: 10pt \"Microsoft YaHei UI\"; }  QTableWidget{	 	background-color: rgb(43, 43, 43);	 	border-color: rgb(63, 63, 70); 	color: rgb(241, 241, 241); 	alternate-background-color: rgb(85, 85, 85); 	font: 9pt \"Microsoft YaHei UI\"; }  QTreeWidget{ 	background-color: rgb(43, 43, 43);	 	border-color: rgb(63, 63, 70); 	color: rgb(241, 241, 241); 	alternate-background-color: rgb(85, 85, 85); 	font: 9pt \"Microsoft YaHei UI\"; }   QHeaderView::section{ 	background-color: rgb(53, 53, 53); 	color: rgb(241, 241, 241); 	border:0px solid #E0DDDC; 	border-bottom:1px solid #262626; 	height: 30px; }   QToolBar{ 	background-color: rgb(60, 63, 65); 	border-bottom: 1px solid #262626; }  QStatusBar{ 	color: rgb(241, 241, 241); 	font: 9pt \"Microsoft YaHei UI\"; }  QMenuBar{ 	background-color: rgb(60, 63, 65); 	color: rgb(241, 241, 241); 	font: 9pt \"Microsoft YaHei UI\"; 	border-bottom: 1px solid #262626; }  QMenuBar::item:selected{ 	background-color: rgb(75, 110, 175); }  QMenu{ 	font: 9pt \"Microsoft YaHei UI\";	 	color: rgb(241, 241, 241); 	background-color: rgb(60, 63, 65); }  QMenu::item:selected{ 	background-color: rgb(75, 110, 175); }   QLabel{ 	color: rgb(241, 241, 241); 	font: 10pt \"Microsoft YaHei UI\"; }  QCheckBox{ 	color: rgb(241, 241, 241); 	font: 10pt \"Microsoft YaHei UI\"; }  QLCDNumber{ 	color: rgb(241, 241, 241); 	font: 10pt \"Microsoft YaHei UI\"; }  QPushButton{ 	color: rgb(241, 241, 241); 	 	background-color: rgb(73, 78, 80); } ";
public slots:
	void onPushButton_Open();
	void onPushButton_Add();
	void onPushButton_Clean();
	void onPushButton_Save();
	void onPushButton_SaveAs();
	void onPushButton_Change();
	void onPushButton_Exit();
	void onPushButton_PointColor();
	void onPushButton_BackgroundColor();
	void onPushButton_MainView();
	void onPushButton_LeftView();
	void onPushButton_TopViewe();
	void onPushButton_GenCube();
	void onPushButton_GenSphere();
	void onPushButton_GenCylinder();
	void onPushButton_MeshSurface();
	void onPushButton_Wireframe();
	void onPushButton_RandomColor();
	void onValueChanged_r_Slider(int value);
	void onValueChanged_g_Slider(int value);
	void onValueChanged_b_Slider(int value);
	void onValueChanged_p_Slider(int value);
	void onReleased_rgb_Slider();
	void onReleased_p_Slider();
	void onCheckboxStateChanged_Coordinate(int value);
	void onCheckboxStateChanged_DarkLight(int value);
	void itemSelected(QTreeWidgetItem*item, int count);
	void popMenu(const QPoint&point);
	void hideItem();
	void showItem();
	void deleteItem();
private:
	void initial();
	void setCloudColor(unsigned int r, unsigned int g, unsigned int b);
	void setA(unsigned int a);
	void showPointcloudAdd();
	void setPropertyTable();
	void showPointcloud();
	void savemulti();
	void consoleLog(QString operation, QString subname, QString filename, QString note);
	std::string getFileName(std::string file_name);
	void timeStart();
	QString timeOff();
};
