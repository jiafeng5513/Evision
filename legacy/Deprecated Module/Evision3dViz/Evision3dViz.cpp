#include "Evision3dViz.h"
#include <QMessageBox>
#include <QFileDialog>
#include <qcolordialog.h>
#include <QAction>
#include <QMenu>
#include <QPoint>
#include <QDebug>
#include <vtkOutputWindow.h>
#include <vtkObject.h>
//构造函数
Evision3dViz::Evision3dViz(QWidget *parent)
	: QWidget(parent)
{
	//vtkOutputWindow::SetGlobalWarningDisplay(false);
	//vtkMapper::SetGlobalWarningDisplay(false);
	//vtkRenderWindow::SetGlobalWarningDisplay(false);
	//vtkObject::GlobalWarningDisplayOff();
	ui.setupUi(this);
	vtkObject::GlobalWarningDisplayOff();

	initial();// Initialization
	//vtkSmartPointer<vtkOutputWindow> myOutputWindow = vtkSmartPointer<vtkOutputWindow>::New();
	//myOutputWindow->PromptUserOff();
	//myOutputWindow->SetGlobalWarningDisplay(false);
	//vtkOutputWindow::SetInstance(myOutputWindow);
}

//打开
void Evision3dViz::onPushButton_Open()
{
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open point cloud file"), QString::fromLocal8Bit(mycloud.dirname.c_str()), tr("Point cloud data(*.pcd *.ply *.obj);;All file(*.*)"));
	//Return if filenames is empty
	if (filenames.isEmpty())
		return;

	// Clear cache
	mycloud_vec.clear();
	total_points = 0;
	ui.dataTree->clear();
	viewer->removeAllPointClouds();

	// Open point cloud one by one
	for (int i = 0; i != filenames.size(); i++) {
		// time start
		timeStart();
		mycloud.cloud.reset(new PointCloudT); // Reset cloud
		QString filename = filenames[i];
		std::string file_name = filename.toStdString();
		std::string subname = getFileName(file_name);  //提取全路径中的文件名（带后缀）

		//更新状态栏
		//ui.statusBar->showMessage(QString::fromLocal8Bit(subname.c_str()) + ": " + QString::number(i) + "/" + QString::number(filenames.size()) + " point cloud loading...");

		int status = -1;
		if (filename.endsWith(".pcd", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPCDFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".ply", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPLYFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".obj", Qt::CaseInsensitive))
		{
			status = pcl::io::loadOBJFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else
		{
			//提示：无法读取除了.ply .pcd .obj以外的文件
			QMessageBox::information(this, tr("File format error"),
				tr("Can't open files except .ply .pcd .obj"));
			return;
		}
		//提示：后缀没问题，但文件内容无法读取
		if (status != 0)
		{
			QMessageBox::critical(this, tr("Reading file error"), tr("We can not open the file"));
			return;
		}
		setA(255);  //设置点云为不透明
		// 最后导入的点云的信息
		mycloud.filename = file_name;
		mycloud.subname = subname;
		mycloud.dirname = file_name.substr(0, file_name.size() - subname.size());
		mycloud_vec.push_back(mycloud);  //将点云导入点云容器


		// time off
		time_cost = timeOff();
		// 输出窗口
		consoleLog("Open", QString::fromLocal8Bit(mycloud.subname.c_str()), QString::fromLocal8Bit(mycloud.filename.c_str()), "Time cost: " + time_cost + " s, Points: " + QString::number(mycloud.cloud->points.size()));

		//更新资源管理树
		QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList()
			<< QString::fromLocal8Bit(subname.c_str()));
		cloudName->setIcon(0, QIcon(":/Resources/images/icon.png"));
		ui.dataTree->addTopLevelItem(cloudName);

		//setWindowTitle(filename + " - CloudViewer"); //更新标题

		total_points += mycloud.cloud->points.size();
	}
	//ui.statusBar->showMessage("");
	showPointcloudAdd();  //更新视图窗口
	setPropertyTable();
}
//添加
void Evision3dViz::onPushButton_Add()
{
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open point cloud file"), QString::fromLocal8Bit(mycloud.dirname.c_str()), tr("Point cloud data(*.pcd *.ply *.obj);;All file(*.*)"));
	if (filenames.isEmpty())
		return;
	for (int i = 0; i != filenames.size(); i++) {
		// time start
		timeStart();
		mycloud.cloud.reset(new PointCloudT);
		QString filename = filenames[i];
		std::string file_name = filename.toStdString();
		std::string subname = getFileName(file_name);

		// 更新状态栏
		//ui.statusBar->showMessage(QString::fromLocal8Bit(subname.c_str()) + ": " + QString::number(i) + "/" + QString::number(filenames.size()) + " point cloud loading...");

		int status = -1;
		if (filename.endsWith(".pcd", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPCDFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".ply", Qt::CaseInsensitive))
		{
			status = pcl::io::loadPLYFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else if (filename.endsWith(".obj", Qt::CaseInsensitive))
		{
			status = pcl::io::loadOBJFile(file_name, *(mycloud.cloud));
			if (mycloud.cloud->points[0].r == 0 && mycloud.cloud->points[0].g == 0 && mycloud.cloud->points[0].b == 0)
			{
				setCloudColor(255, 255, 255);
			}
		}
		else
		{
			//提示：无法读取除了.ply .pcd .obj以外的文件
			QMessageBox::information(this, tr("File format error"), tr("Can't open files except .ply .pcd .obj"));
			return;
		}
		//提示：后缀没问题，但文件内容无法读取
		if (status != 0)
		{
			QMessageBox::critical(this, tr("Reading file error"), tr("We can not open the file"));
			return;
		}
		setA(255);  //设置点云为不透明
		mycloud.filename = file_name;
		mycloud.subname = subname;
		mycloud.dirname = file_name.substr(0, file_name.size() - subname.size());
		mycloud_vec.push_back(mycloud);  //将点云导入点云容器

		// time of
		time_cost = timeOff();
		//输出窗口
		consoleLog("Add", QString::fromLocal8Bit(mycloud.subname.c_str()), QString::fromLocal8Bit(mycloud.filename.c_str()), "Time cost: " + time_cost + " s, Points: " + QString::number(mycloud.cloud->points.size()));

		//设置资源管理器
		QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(subname.c_str()));
		cloudName->setIcon(0, QIcon(":/Resources/images/icon.png"));
		ui.dataTree->addTopLevelItem(cloudName);

		//setWindowTitle("CloudViewer");
		total_points += mycloud.cloud->points.size();
	}
	//ui.statusBar->showMessage("");
	showPointcloudAdd();
	setPropertyTable();
}
//清除
void Evision3dViz::onPushButton_Clean()
{
	mycloud_vec.clear();  //从点云容器中移除所有点云
	viewer->removeAllPointClouds();  //从viewer中移除所有点云
	viewer->removeAllShapes(); //这个remove更彻底
	ui.dataTree->clear();  //将dataTree清空

	ui.propertyTable->clear();  //清空属性窗口propertyTable
	QStringList header;
	header << "Property" << "Value";
	ui.propertyTable->setHorizontalHeaderLabels(header);

	//输出窗口
	consoleLog("Clear", "All point clouds", "", "");

	setWindowTitle("CloudViewer");  //更新窗口标题
	showPointcloud();  //更新显示
}
//保存
void Evision3dViz::onPushButton_Save()
{
	save_filename = QFileDialog::getSaveFileName(this, tr("Save point cloud"),
		QString::fromLocal8Bit(mycloud.dirname.c_str()), tr("Point cloud data(*.pcd *.ply);;Allfile(*.*)"));
	std::string file_name = save_filename.toStdString();
	std::string subname = getFileName(file_name);
	//文件名为空直接返回
	if (save_filename.isEmpty())
		return;

	if (mycloud_vec.size() > 1)
	{
		savemulti();
		return;
	}

	int status = -1;
	if (save_filename.endsWith(".pcd", Qt::CaseInsensitive))
	{
		status = pcl::io::savePCDFile(file_name, *(mycloud.cloud));
	}
	else if (save_filename.endsWith(".ply", Qt::CaseInsensitive))
	{
		status = pcl::io::savePLYFile(file_name, *(mycloud.cloud));
	}
	else //提示：无法保存为除了.ply .pcd以外的文件
	{
		QMessageBox::information(this, tr("File format error"),
			tr("Can't save files except .ply .pcd"));
		return;
	}
	//提示：后缀没问题，但是无法保存
	if (status != 0)
	{
		QMessageBox::critical(this, tr("Saving file error"),
			tr("We can not save the file"));
		return;
	}

	//输出窗口
	consoleLog("Save", QString::fromLocal8Bit(subname.c_str()), save_filename, "Single save");

	setWindowTitle(save_filename + " - CloudViewer");
	QMessageBox::information(this, tr("save point cloud file"),
		QString::fromLocal8Bit(("Save " + subname + " successfully!").c_str()));
}
//另存为
void Evision3dViz::onPushButton_SaveAs()
{
	save_filename = QFileDialog::getSaveFileName(this, tr("Save point cloud as binary file"),
		QString::fromLocal8Bit(mycloud.dirname.c_str()), tr("Point cloud data(*.pcd *.ply);;Allfile(*.*)"));
	std::string file_name = save_filename.toStdString();
	std::string subname = getFileName(file_name);
	//文件名为空直接返回
	if (save_filename.isEmpty())
		return;

	if (mycloud_vec.size() > 1)
	{
		savemulti();
		return;
	}

	int status = -1;
	if (save_filename.endsWith(".pcd", Qt::CaseInsensitive))
	{
		status = pcl::io::savePCDFileBinary(file_name, *(mycloud.cloud));
	}
	else if (save_filename.endsWith(".ply", Qt::CaseInsensitive))
	{
		status = pcl::io::savePLYFileBinary(file_name, *(mycloud.cloud));
	}
	else //提示：无法保存为除了.ply .pcd以外的文件
	{
		QMessageBox::information(this, tr("File format error"),
			tr("Can't save files except .ply .pcd"));
		return;
	}
	//提示：后缀没问题，但是无法保存
	if (status != 0)
	{
		QMessageBox::critical(this, tr("Saving file error"),
			tr("We can not save the file"));
		return;
	}

	//输出窗口
	consoleLog("Save as binary", QString::fromLocal8Bit(subname.c_str()), save_filename, "Single save (binary)");

	setWindowTitle(save_filename + " - CloudViewer");
	QMessageBox::information(this, tr("save point cloud file"),
		QString::fromLocal8Bit(("Save " + subname + " successfully!").c_str()));
}
//更改(格式转换)
void Evision3dViz::onPushButton_Change()
{
	//TODO::点云格式转换
}
//退出
void Evision3dViz::onPushButton_Exit()
{
	this->close();
}
//点云颜色
void Evision3dViz::onPushButton_PointColor()
{
	QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");

	if (color.isValid()) //判断所选的颜色是否有效
	{
		//QAction* action = dynamic_cast<QAction*>(sender());
		//if (action != ui.pointcolorAction) //改变颜色的信号来自于 dataTree
		QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
		int selected_item_count = ui.dataTree->selectedItems().size();
		if (selected_item_count == 0) {
			for (int i = 0; i != mycloud_vec.size(); i++) {
				for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++) {
					mycloud_vec[i].cloud->points[j].r = color.red();
					mycloud_vec[i].cloud->points[j].g = color.green();
					mycloud_vec[i].cloud->points[j].b = color.blue();
				}
			}
			// 输出窗口
			consoleLog("Change cloud color", "All point clouds", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		}
		else {
			for (int i = 0; i != selected_item_count; i++) {
				int cloud_id = ui.dataTree->indexOfTopLevelItem(itemList[i]);
				for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++) {
					mycloud_vec[cloud_id].cloud->points[j].r = color.red();
					mycloud_vec[cloud_id].cloud->points[j].g = color.green();
					mycloud_vec[cloud_id].cloud->points[j].b = color.blue();
				}
			}
			// 输出窗口
			consoleLog("Change cloud color", "Point clouds selected", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		}
		//颜色的改变同步至RGB停靠窗口
		ui.rSlider->setValue(color.red());
		ui.gSlider->setValue(color.green());
		ui.bSlider->setValue(color.blue());

		showPointcloud();
	}
}
//背景颜色
void Evision3dViz::onPushButton_BackgroundColor()
{
	QColor color = QColorDialog::getColor(Qt::white, this,
		"Select color for point cloud");
	if (color.isValid())
	{
		viewer->setBackgroundColor(color.red() / 255.0,
			color.green() / 255.0, color.blue() / 255.0);
		// 输出窗口
		consoleLog("Change bg color", "Background", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		showPointcloud();
	}
}
//主视图
void Evision3dViz::onPushButton_MainView()
{
	viewer->setCameraPosition(0, -1, 0, 0.5, 0.5, 0.5, 0, 0, 1);
	ui.screen->update();
}
//左视图
void Evision3dViz::onPushButton_LeftView()
{
	viewer->setCameraPosition(-1, 0, 0, 0, 0, 0, 0, 0, 1);
	ui.screen->update();
}
//俯视图
void Evision3dViz::onPushButton_TopViewe()
{
	viewer->setCameraPosition(0, 0, 1, 0, 0, 0, 0, 1, 0);
	ui.screen->update();
}
//生成cube
void Evision3dViz::onPushButton_GenCube()
{
	mycloud.cloud.reset(new PointCloudT);
	total_points = 0;
	ui.dataTree->clear();  //清空资源管理器的item
	viewer->removeAllPointClouds();  //从viewer中移除所有点云
	mycloud_vec.clear();  //清空点云容器

	mycloud.cloud->width = 50000;         // 设置点云宽
	mycloud.cloud->height = 1;            // 设置点云高，高为1，说明为无组织点云
	mycloud.cloud->is_dense = false;
	mycloud.cloud->resize(mycloud.cloud->width * mycloud.cloud->height);     // 重置点云大小
	for (int i = 0; i != mycloud.cloud->size(); ++i)
	{
		mycloud.cloud->points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud.cloud->points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud.cloud->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud.cloud->points[i].r = red;
		mycloud.cloud->points[i].g = green;
		mycloud.cloud->points[i].b = blue;
	}
	//设置资源管理器
	QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit("cube"));
	cloudName->setIcon(0, QIcon(":/Resources/images/icon.png"));
	ui.dataTree->addTopLevelItem(cloudName);

	// 输出窗口
	consoleLog("Generate cube", "cube", "cube", "");

	mycloud_vec.push_back(mycloud);
	showPointcloudAdd();
}
//生成sphere
void Evision3dViz::onPushButton_GenSphere()
{
	mycloud.cloud.reset(new PointCloudT);
	ui.dataTree->clear();  //清空资源管理器的item
	viewer->removeAllShapes();
	mycloud_vec.clear();  //清空点云容器

	pcl::PointXYZ p;
	p.x = 0; p.y = 0; p.z = 0;
	viewer->addSphere(p, 100, "sphere1");

	viewer->resetCamera();
	ui.screen->update();

	// 输出窗口
	consoleLog("Create sphere", "Sphere", "", "Succeeded");
}
//生成Cylinder
void Evision3dViz::onPushButton_GenCylinder()
{
	mycloud.cloud.reset(new PointCloudT);
	ui.dataTree->clear();  //清空资源管理器的item
	viewer->removeAllShapes();
	mycloud_vec.clear();  //清空点云容器

	viewer->addCylinder(*(new pcl::ModelCoefficients()), "cylinder");

	viewer->resetCamera();
	ui.screen->update();

	// 输出窗口
	consoleLog("Create cylinder", "Cylinder", "", "Failed");
}
//MeshSurface法线估计、曲面重建、网格面片显示
void Evision3dViz::onPushButton_MeshSurface()
{
	/* 问题
	好像该方法只能处理PointXYZ的点云，用PointXZYRGBA的点云编译会报错
	调用boost::this_thread::sleep好像也会编译出错
	*/
	pcl::PointXYZ point;
	cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
	for (int i = 0; i < mycloud.cloud->size(); i++)
	{
		point.x = mycloud.cloud->points[i].x;
		point.y = mycloud.cloud->points[i].y;
		point.z = mycloud.cloud->points[i].z;
		cloud_xyz->push_back(point);
	}
	if (!cloud_xyz)
	{
		return;//失败退出
	}

	/****** 法向估计模块 ******/
	//创建法线估计对象 n
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
	//创建法向数据指针 normals
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
	//创建 kdtree 用于法向计算时近邻搜索
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
	tree->setInputCloud(cloud_xyz); //为 kdtree 输入点云
	n.setInputCloud(cloud_xyz); //为法向估计对象输入点云
	n.setSearchMethod(tree);  //设置法向估计时所采取的搜索方式为kdtree
	n.setKSearch(20); //设置法向估计时，k近邻搜索的点数
	n.compute(*normals); //进行法向估计

	QMessageBox::information(this, "information", "Normal estimation finished");

	/****** 点云数据与法向数据拼接 ******/
	//从这之后出现问题

	//创建同时包含点和法线的数据结构的指针
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);

	//将已获得的点数据和法向数据拼接
	pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals); //这里编译出错，与cloud的类型有关？改成PointXYZ的点云就没有报错了

	//创建另一个kdtree用于重建
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointNormal>);
	//为kdtree输入点云数据，该点云数据类型为点和法向
	tree2->setInputCloud(cloud_with_normals);

	/****** 曲面重建模块 ******/
	//创建贪婪三角形投影重建对象
	pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
	//创建多边形网格对象，用来存储重建结果
	pcl::PolygonMesh triangles;
	//设置参数
	gp3.setSearchRadius(25); //设置连接点之间最大距离，用于确定k近邻的球半径
	gp3.setMu(2.5); //设置最近邻距离的乘子，以得到每个点的最终搜索半径
	gp3.setMaximumNearestNeighbors(100); //设置搜索的最近邻点的最大数量
	gp3.setMaximumSurfaceAngle(M_PI / 2); //45度 最大平面角
	gp3.setMinimumAngle(M_PI / 18); //10度 每个三角的最大角度？
	gp3.setMaximumAngle(2 * M_PI / 3); //120度
	gp3.setNormalConsistency(false); //若法向量一致，设为true
	//设置点云数据和搜索方式
	gp3.setInputCloud(cloud_with_normals);
	gp3.setSearchMethod(tree2);
	// 开始重建
	gp3.reconstruct(triangles);
	QMessageBox::information(this, "informaiton", "Reconstruction finished");

	//将重建结果保存到硬盘文件中，重建结果以VTK格式存储
	pcl::io::saveVTKFile("mymesh.vtk", triangles);

	/*
	//Additional vertex information
	std::vector<int> parts = gp3.getPartIDs();
	std::vector<int> states = gp3.getPointStates();
	fstream fs;
	fs.open("partsID.txt", ios::out);
	if (!fs)
	{
	return -2;
	}
	fs << "number of point clouds:" << parts.size() << "\n";
	for (int i = 0; i < parts.size(); i++)
	{
	if (parts[i] != 0)
	{
	fs << parts[i] << "\n";
	}
	}
	*/

	/****** 图形显示模块 ******/
	QMessageBox::information(this, "informaiton", "Start to show");
	viewer->addPolygonMesh(triangles, "my"); //设置要显示的网格对象
	//设置网格模型显示模式
	viewer->setRepresentationToSurfaceForAllActors(); //网格模型以面片形式显示
	//viewer->setRepresentationToPointsForAllActors(); //网格模型以点形式显示
	//viewer->setRepresentationToWireframeForAllActors(); //网格模型以线框图模式显示

	// 输出窗口
	consoleLog("Convert surface", "", "", "");

	viewer->removeAllShapes();
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		//boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
	return;
}
//Wireframe
void Evision3dViz::onPushButton_Wireframe()
{
	/* 问题
好像该方法只能处理PointXYZ的点云，用PointXZYRGBA的点云编译会报错
调用boost::this_thread::sleep好像也会编译出错
*/
	pcl::PointXYZ point;
	cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
	for (int i = 0; i < mycloud.cloud->size(); i++)
	{
		point.x = mycloud.cloud->points[i].x;
		point.y = mycloud.cloud->points[i].y;
		point.z = mycloud.cloud->points[i].z;
		cloud_xyz->push_back(point);
	}
	if (!cloud_xyz)
	{
		return;
	}


	/****** 法向估计模块 ******/
	//创建法线估计对象 n
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
	//创建法向数据指针 normals
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
	//创建 kdtree 用于法向计算时近邻搜索
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
	tree->setInputCloud(cloud_xyz); //为 kdtree 输入点云
	n.setInputCloud(cloud_xyz); //为法向估计对象输入点云
	n.setSearchMethod(tree);  //设置法向估计时所采取的搜索方式为kdtree
	n.setKSearch(20); //设置法向估计时，k近邻搜索的点数
	n.compute(*normals); //进行法向估计

	QMessageBox::information(this, "information", "Normal estimation finished");

	/****** 点云数据与法向数据拼接 ******/
	//从这之后出现问题

	//创建同时包含点和法线的数据结构的指针
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);

	//将已获得的点数据和法向数据拼接
	pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals); //这里编译出错，与cloud的类型有关？改成PointXYZ的点云就没有报错了

	//创建另一个kdtree用于重建
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointNormal>);
	//为kdtree输入点云数据，该点云数据类型为点和法向
	tree2->setInputCloud(cloud_with_normals);



	/****** 曲面重建模块 ******/
	//创建贪婪三角形投影重建对象
	pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
	//创建多边形网格对象，用来存储重建结果
	pcl::PolygonMesh triangles;
	//设置参数
	gp3.setSearchRadius(25); //设置连接点之间最大距离，用于确定k近邻的球半径
	gp3.setMu(2.5); //设置最近邻距离的乘子，以得到每个点的最终搜索半径
	gp3.setMaximumNearestNeighbors(100); //设置搜索的最近邻点的最大数量
	gp3.setMaximumSurfaceAngle(M_PI / 2); //45度 最大平面角
	gp3.setMinimumAngle(M_PI / 18); //10度 每个三角的最大角度？
	gp3.setMaximumAngle(2 * M_PI / 3); //120度
	gp3.setNormalConsistency(false); //若法向量一致，设为true
	//设置点云数据和搜索方式
	gp3.setInputCloud(cloud_with_normals);
	gp3.setSearchMethod(tree2);
	// 开始重建
	gp3.reconstruct(triangles);
	QMessageBox::information(this, "informaiton", "Reconstruction finished");

	//将重建结果保存到硬盘文件中，重建结果以VTK格式存储
	pcl::io::saveVTKFile("mymesh.vtk", triangles);

	/*
	//Additional vertex information
	std::vector<int> parts = gp3.getPartIDs();
	std::vector<int> states = gp3.getPointStates();
	fstream fs;
	fs.open("partsID.txt", ios::out);
	if (!fs)
	{
	return -2;
	}
	fs << "number of point clouds:" << parts.size() << "\n";
	for (int i = 0; i < parts.size(); i++)
	{
	if (parts[i] != 0)
	{
	fs << parts[i] << "\n";
	}
	}
	*/

	/****** 图形显示模块 ******/
	QMessageBox::information(this, "informaiton", "Start to show");
	viewer->addPolygonMesh(triangles, "my"); //设置要显示的网格对象
	//设置网格模型显示模式
	//viewer->setRepresentationToSurfaceForAllActors(); //网格模型以面片形式显示
	//viewer->setRepresentationToPointsForAllActors(); //网格模型以点形式显示
	viewer->setRepresentationToWireframeForAllActors(); //网格模型以线框图模式显示

	// 输出窗口
	consoleLog("Convert wireframe", "", "", "");

	viewer->removeAllShapes();
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		//boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
	return;
}
//随机颜色
void Evision3dViz::onPushButton_RandomColor()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
	if (selected_item_count == 0) {
		for (int i = 0; i != mycloud_vec.size(); i++) {
			for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++) {
				mycloud_vec[i].cloud->points[j].r = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
				mycloud_vec[i].cloud->points[j].g = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
				mycloud_vec[i].cloud->points[j].b = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
			}
		}

		// 输出窗口
		consoleLog("Random color", "All point clous", "", "");

	}
	else {
		for (int i = 0; i != selected_item_count; i++) {
			int cloud_id = ui.dataTree->indexOfTopLevelItem(itemList[i]);
			for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++) {
				mycloud_vec[cloud_id].cloud->points[j].r = red;
				mycloud_vec[cloud_id].cloud->points[j].g = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
				mycloud_vec[cloud_id].cloud->points[j].b = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
			}
		}

		// 输出窗口
		consoleLog("Random color", "Point clouds selected", "", "");
	}
	showPointcloud();
}
//R Slider 值更改
void Evision3dViz::onValueChanged_r_Slider(int value)
{
	red = value;
	ui.rLCD->display(value);
}
//G Slider 值更改
void Evision3dViz::onValueChanged_g_Slider(int value)
{
	green = value;
	ui.gLCD->display(value);
}
//B Slider 值更改
void Evision3dViz::onValueChanged_b_Slider(int value)
{
	blue = value;
	ui.bLCD->display(value);
}
//P Slider 值更改
void Evision3dViz::onValueChanged_p_Slider(int value)
{
	p = value;
	ui.sizeLCD->display(value);
}
//RGB Slider 释放
void Evision3dViz::onReleased_rgb_Slider()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
	if (selected_item_count == 0) {
		for (int i = 0; i != mycloud_vec.size(); i++) {
			for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++) {
				mycloud_vec[i].cloud->points[j].r = red;
				mycloud_vec[i].cloud->points[j].g = green;
				mycloud_vec[i].cloud->points[j].b = blue;
			}
		}

		// 输出窗口
		consoleLog("Change cloud color", "All point clouds", QString::number(red) + " " + QString::number(green) + " " + QString::number(blue), "");
	}
	else {
		for (int i = 0; i != selected_item_count; i++) {
			int cloud_id = ui.dataTree->indexOfTopLevelItem(itemList[i]);
			for (int j = 0; j != mycloud_vec[cloud_id].cloud->size(); j++) {
				mycloud_vec[cloud_id].cloud->points[j].r = red;
				mycloud_vec[cloud_id].cloud->points[j].g = green;
				mycloud_vec[cloud_id].cloud->points[j].b = blue;
			}
		}
		// 输出窗口
		consoleLog("Change cloud color", "Point clouds selected", QString::number(red) + " " + QString::number(green) + " " + QString::number(blue), "");
	}
	showPointcloud();
}
//P Slider 释放
void Evision3dViz::onReleased_p_Slider()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	if (selected_item_count == 0) {
		for (int i = 0; i != mycloud_vec.size(); i++) {
			viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
				p, "cloud" + QString::number(i).toStdString());
		}
		// 输出窗口
		consoleLog("Change cloud size", "All point clouds", "Size: " + QString::number(p), "");
	}
	else {
		for (int i = 0; i != selected_item_count; i++) {
			int cloud_id = ui.dataTree->indexOfTopLevelItem(itemList[i]);
			viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
				p, "cloud" + QString::number(cloud_id).toStdString());
		}
		// 输出窗口
		consoleLog("Change cloud size", "Point clouds selected", "Size: " + QString::number(p), "");
	}
	ui.screen->update();
}
//checkbox Coordinate 状态更改
void Evision3dViz::onCheckboxStateChanged_Coordinate(int value)
{
	switch (value)
	{
	case 0:
		viewer->removeCoordinateSystem();  //移除坐标系
		// 输出窗口
		consoleLog("Remove coordinate system", "Remove", "", "");
		break;
	case 2:
		viewer->addCoordinateSystem();  //添加坐标系
		// 输出窗口
		consoleLog("Add coordinate system", "Add", "", "");
		break;
	}
	//viewer->updatePointCloud(cloud, "cloud");
	ui.screen->update();
}
//checkbox DarkLight 状态更改
void Evision3dViz::onCheckboxStateChanged_DarkLight(int value)
{
	switch (value)
	{
	case 0:
		viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
		// 输出窗口
		consoleLog("Change bg color", "Background", "30 30 30", "");
		break;
	case 2:
		//！注意：setBackgroundColor()接收的是0-1的double型参数
		viewer->setBackgroundColor(240 / 255.0, 240 / 255.0, 240 / 255.0);
		// 输出窗口
		consoleLog("Change bg color", "Background", "240 240 240", "");
		break;
	}
	//viewer->updatePointCloud(cloud, "cloud");
	ui.screen->update();
}
//点云对象被选中
void Evision3dViz::itemSelected(QTreeWidgetItem* item, int count)
{
	count = ui.dataTree->indexOfTopLevelItem(item);  //获取item的行号

	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud" + QString::number(i).toStdString());
	}

	//提取当前点云的RGB,点云数量等信息
	int cloud_size = mycloud_vec[count].cloud->points.size();
	unsigned int cloud_r = mycloud_vec[count].cloud->points[0].r;
	unsigned int cloud_g = mycloud_vec[count].cloud->points[0].g;
	unsigned int cloud_b = mycloud_vec[count].cloud->points[0].b;
	bool multi_color = true;
	if (mycloud_vec[count].cloud->points.begin()->r == (mycloud_vec[count].cloud->points.end() - 1)->r) //判断点云单色多色的条件（不是很严谨）
		multi_color = false;

	ui.propertyTable->setItem(0, 1, new QTableWidgetItem(QString::number(mycloud_vec.size())));
	ui.propertyTable->setItem(1, 1, new QTableWidgetItem(QString::number(cloud_size)));
	ui.propertyTable->setItem(2, 1, new QTableWidgetItem(QString::number(total_points)));
	ui.propertyTable->setItem(3, 1, new QTableWidgetItem(multi_color ? "Multi Color" : (QString::number(cloud_r) + " " + QString::number(cloud_g) + " " + QString::number(cloud_b))));

	//选中item所对应的点云尺寸变大
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	for (int i = 0; i != selected_item_count; i++) {
		int cloud_id = ui.dataTree->indexOfTopLevelItem(itemList[i]);
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
			2, "cloud" + QString::number(cloud_id).toStdString());
	}
	//mycloud = mycloud_vec[count];
	ui.screen->update();
}
//弹出右键菜单
void Evision3dViz::popMenu(const QPoint& point)
{
	QTreeWidgetItem* curItem = ui.dataTree->currentItem(); //获取当前被点击的节点
	if (curItem == NULL)return;           //这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
	QString name = curItem->text(0);
	int id = ui.dataTree->indexOfTopLevelItem(curItem);
	std::string cloud_id = "cloud" + QString::number(id).toStdString();

	QAction hideItemAction("Hide", this);
	QAction showItemAction("Show", this);
	QAction deleteItemAction("Delete", this);
	QAction changeColorAction("Change color", this);

	connect(&hideItemAction, &QAction::triggered, this, &Evision3dViz::hideItem);
	connect(&showItemAction, &QAction::triggered, this, &Evision3dViz::showItem);
	connect(&deleteItemAction, &QAction::triggered, this, &Evision3dViz::deleteItem);
	connect(&changeColorAction, &QAction::triggered, this, &Evision3dViz::onPushButton_PointColor);

	QPoint pos;
	QMenu menu(ui.dataTree);
	menu.addAction(&hideItemAction);
	menu.addAction(&showItemAction);
	menu.addAction(&deleteItemAction);
	menu.addAction(&changeColorAction);

	if (mycloud_vec[id].visible == true) {
		menu.actions()[1]->setVisible(false);
		menu.actions()[0]->setVisible(true);
	}
	else {
		menu.actions()[1]->setVisible(true);
		menu.actions()[0]->setVisible(false);
	}


	menu.exec(QCursor::pos()); //在当前鼠标位置显示
}
//右键菜单:隐藏
void Evision3dViz::hideItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	for (int i = 0; i != ui.dataTree->selectedItems().size(); i++) {
		//TODO hide之后，item变成灰色，再次右击item时，“hideItem” 选项变成 “showItem”
		//QTreeWidgetItem* curItem = ui.dataTree->currentItem();
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		int id = ui.dataTree->indexOfTopLevelItem(curItem);
		std::string cloud_id = "cloud" + QString::number(id).toStdString();
		//QMessageBox::information(this, "cloud_id", QString::fromLocal8Bit(cloud_id.c_str()));
		// 将cloud_id所对应的点云设置成透明
		viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 0.0, cloud_id, 0);
		QColor item_color = QColor(112, 122, 132, 255);
		curItem->setTextColor(0, item_color);
		mycloud_vec[id].visible = false;
	}

	// 输出窗口
	consoleLog("Hide point clouds", "Point clouds selected", "", "");

	ui.screen->update(); //刷新视图窗口，不能省略
}
//右键菜单:显示
void Evision3dViz::showItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	for (int i = 0; i != ui.dataTree->selectedItems().size(); i++) {
		//QTreeWidgetItem* curItem = ui.dataTree->currentItem();
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		int id = ui.dataTree->indexOfTopLevelItem(curItem);
		std::string cloud_id = "cloud" + QString::number(id).toStdString();
		// 将cloud_id所对应的点云设置成透明
		viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 1.0, cloud_id, 0);
		QColor item_color;
		if (theme_id == 0) {
			item_color = QColor(0, 0, 0, 255);
		}
		else {
			item_color = QColor(241, 241, 241, 255);
		}
		curItem->setTextColor(0, item_color);
		mycloud_vec[id].visible = true;
	}

	// 输出窗口
	consoleLog("Show point clouds", "Point clouds selected", "", "");

	ui.screen->update(); //刷新视图窗口，不能省略
}
//右键菜单:删除
void Evision3dViz::deleteItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	// ui.dataTree->selectedItems().size() 随着迭代次数而改变，因此循环条件要设置为固定大小的 selected_item_count
	int selected_item_count = ui.dataTree->selectedItems().size();
	for (int i = 0; i != selected_item_count; i++) {
		//QTreeWidgetItem* curItem = ui.dataTree->currentItem();
		//QMessageBox::information(this, "itemList's size", QString::number(ui.dataTree->selectedItems().size()));
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		int id = ui.dataTree->indexOfTopLevelItem(curItem);
		//QMessageBox::information(this, "information", "curItem: " + name + " " + QString::number(id));
		auto it = mycloud_vec.begin() + ui.dataTree->indexOfTopLevelItem(curItem);
		// 删除点云之前，将其点的数目保存
		int delete_points = (*it).cloud->points.size();
		it = mycloud_vec.erase(it);
		//QMessageBox::information(this, "information", QString::number(delete_points) + " " + QString::number(mycloud_vec.size()));

		total_points -= delete_points;
		setPropertyTable();

		ui.dataTree->takeTopLevelItem(ui.dataTree->indexOfTopLevelItem(curItem));
	}

	// 移除之后再添加，避免 id 和资源管理树行号不一致的情况
	viewer->removeAllPointClouds();
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->addPointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
	}

	// 输出窗口
	consoleLog("Delete point clouds", "Point clouds selected", "", "");

	ui.screen->update();
}

//初始化
void Evision3dViz::initial()
{
	//界面初始化
	setWindowIcon(QIcon(tr(":/Resources/images/icon.png")));
	setWindowTitle(tr("CloudViewer"));

	//点云初始化
	mycloud.cloud.reset(new PointCloudT);
	mycloud.cloud->resize(1);
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	//viewer->addPointCloud(cloud, "cloud");

	ui.screen->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.screen->GetInteractor(), ui.screen->GetRenderWindow());
	ui.screen->update();

	ui.propertyTable->setSelectionMode(QAbstractItemView::NoSelection); // 禁止点击属性管理器的 item
	//ui.consoleTable->setSelectionMode(QAbstractItemView::NoSelection);  // 禁止点击输出窗口的 item
	ui.dataTree->setSelectionMode(QAbstractItemView::ExtendedSelection); // 允许 dataTree 进行多选

	// 设置默认主题
	//QString qss = darcula_qss;
	//qApp->setStyleSheet(qss);

	setPropertyTable();
	//setConsoleTable();

	// 输出窗口
	consoleLog("Software start", "CloudViewer", "Welcome to use CloudViewer", "Nightn");


	// 设置背景颜色为 dark
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);
}
//设置点云颜色
void Evision3dViz::setCloudColor(unsigned r, unsigned g, unsigned b)
{
	// Set the new color
	for (int i = 0; i < mycloud.cloud->size(); i++)
	{
		mycloud.cloud->points[i].r = r;
		mycloud.cloud->points[i].g = g;
		mycloud.cloud->points[i].b = b;
		mycloud.cloud->points[i].a = 255;
	}
}
//设置透明度
void Evision3dViz::setA(unsigned a)
{
	for (int i = 0; i < mycloud.cloud->size(); i++)
	{
		mycloud.cloud->points[i].a = a;
	}
}
//添加点云到viewer,并显示点云
void Evision3dViz::showPointcloudAdd()
{
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->addPointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
	}
	viewer->resetCamera();
	ui.screen->update();
}
//设置属性管理窗口
void Evision3dViz::setPropertyTable()
{
	QStringList header;
	header << "Property" << "Value";
	ui.propertyTable->setHorizontalHeaderLabels(header);
	ui.propertyTable->setItem(0, 0, new QTableWidgetItem("Clouds"));
	ui.propertyTable->setItem(1, 0, new QTableWidgetItem("Points"));
	ui.propertyTable->setItem(2, 0, new QTableWidgetItem("Total points"));
	ui.propertyTable->setItem(3, 0, new QTableWidgetItem("RGB"));


	ui.propertyTable->setItem(0, 1, new QTableWidgetItem(QString::number(mycloud_vec.size())));
	ui.propertyTable->setItem(1, 1, new QTableWidgetItem(""));
	ui.propertyTable->setItem(2, 1, new QTableWidgetItem(QString::number(total_points)));
	ui.propertyTable->setItem(4, 1, new QTableWidgetItem(""));
}
//显示点云，不重置相机角度
void Evision3dViz::showPointcloud()
{
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		viewer->updatePointCloud(mycloud_vec[i].cloud, "cloud" + QString::number(i).toStdString());
	}
	//viewer->resetCamera();
	ui.screen->update();
}
// Save multi point cloud
void Evision3dViz::savemulti()
{
	std::string subname = getFileName(save_filename.toStdString());
	PointCloudT::Ptr multi_cloud;
	multi_cloud.reset(new PointCloudT);
	multi_cloud->height = 1;
	int sum = 0;
	for (auto c : mycloud_vec)
	{
		sum += c.cloud->points.size();
	}
	multi_cloud->width = sum;
	multi_cloud->resize(multi_cloud->height * multi_cloud->width);
	int k = 0;
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		for (int j = 0; j != mycloud_vec[i].cloud->points.size(); j++)          //注意cloudvec[i]->points.size()和cloudvec[i]->size()的区别
		{
			multi_cloud->points[k].x = mycloud_vec[i].cloud->points[j].x;
			multi_cloud->points[k].y = mycloud_vec[i].cloud->points[j].y;
			multi_cloud->points[k].z = mycloud_vec[i].cloud->points[j].z;
			multi_cloud->points[k].r = mycloud_vec[i].cloud->points[j].r;
			multi_cloud->points[k].g = mycloud_vec[i].cloud->points[j].g;
			multi_cloud->points[k].b = mycloud_vec[i].cloud->points[j].b;
			k++;
		}
	}
	//保存multi_cloud
	int status = -1;
	if (save_filename.endsWith(".pcd", Qt::CaseInsensitive))
	{
		if (save_as_binary) {
			status = pcl::io::savePCDFileBinary(save_filename.toStdString(), *multi_cloud);
		}
		else {
			status = pcl::io::savePCDFile(save_filename.toStdString(), *multi_cloud);
		}

	}
	else if (save_filename.endsWith(".ply", Qt::CaseInsensitive))
	{
		if (save_as_binary) {
			status = pcl::io::savePLYFileBinary(save_filename.toStdString(), *multi_cloud);
		}
		else {
			status = pcl::io::savePLYFile(save_filename.toStdString(), *multi_cloud);
		}
	}
	else //提示：无法保存为除了.ply .pcd以外的文件
	{
		QMessageBox::information(this, tr("File format error"), tr("Can't save files except .ply .pcd"));
		return;
	}

	//提示：后缀没问题，但是无法保存
	if (status != 0)
	{
		QMessageBox::critical(this, tr("Saving file error"), tr("We can not save the file"));
		return;
	}

	// 输出窗口
	if (save_as_binary) {
		consoleLog("Save as binary", QString::fromLocal8Bit(subname.c_str()), save_filename, "Multi save (binary)");
	}
	else {
		consoleLog("Save", QString::fromLocal8Bit(subname.c_str()), save_filename, "Multi save");
	}


	save_as_binary = false;
	//将保存后的 multi_cloud 设置为当前 mycloud,以便保存之后直接进行操作
	mycloud.cloud = multi_cloud;
	mycloud.filename = save_filename.toStdString();
	mycloud.subname = subname;

	setWindowTitle(save_filename + " - CloudViewer");
	QMessageBox::information(this, tr("save point cloud file"), QString::fromLocal8Bit(("Save " + subname + " successfully!").c_str()));
}
//输出运行日志
void Evision3dViz::consoleLog(QString operation, QString subname, QString filename, QString note)
{
	qDebug() << operation << subname << filename << note;
}
//提取全路径中的文件名（带后缀）
std::string Evision3dViz::getFileName(std::string file_name)
{
	std::string subname;
	for (auto i = file_name.end() - 1; *i != '/'; i--)
	{
		subname.insert(subname.begin(), *i);
	}
	return subname;
}
//计时开始
void Evision3dViz::timeStart()
{
	time.start();
}
//计时结束
QString Evision3dViz::timeOff()
{
	int timediff = time.elapsed();   //返回从上次start()或restart()开始以来的时间差，单位ms
	float f = timediff / 1000.0;
	QString tr_timediff = QString("%1").arg(f);  //float->QString
	return tr_timediff;
}
