#include "EvisionView.h"
#include "QDebug"
#include "QMessageBox"
#include "EvisionUtils.h"
#include <qevent.h>
#include <qmimedata.h>
#include <QFileDialog>
#include "WatchImageView.h"

#ifdef WITH_CUDA
#include "EvisionObjDetectionFactory.h"
#endif

#if (defined WITH_PCL) 
#include "EvisionCloudViewerFactory.h"
#endif

#include "EvisionUndistortionFactory.h"
#include "EvisionCalibrateFactory.h"
#include "EvisionDisparityFactory.h"
#include "EvisionTraceFactory.h"
#include "EvisionCameraFactory.h"
#include "EvisionParamBridgeFactory.h"
#include "EvisionPolyTrackerFactory.h"
#include "EvisionMonocularCalibFactory.h"
// 浮点数判等
// ulp: units in the last place.
//template <typename T>
//typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
//IsAlmostEqual(T x, T y, int ulp = 2)
//{
//	// the machine epsilon has to be scaled to the magnitude of the values used
//	// and multiplied by the desired precision in ULPs (units in the last place)
//	return std::abs(x - y) < std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
//		// unless the result is subnormal
//		|| std::abs(x - y) < std::numeric_limits<T>::min();
//}

//构造函数
EvisionView::EvisionView(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);
	msgLabel = new QLabel;
	msgLabel->setMinimumSize(msgLabel->sizeHint());
	msgLabel->setAlignment(Qt::AlignHCenter);
	msgLabel->setText(QStringLiteral("就绪"));
	statusBar()->addWidget(msgLabel);
	statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

	m_entity = EvisionParamEntity::getInstance();
	//m_controller = new EvisionController();


	connect(m_entity, SIGNAL(paramChanged_StatusBar()), this, SLOT(onParamChanged_StatusBarText()), Qt::QueuedConnection);


	on_action_LogViewSwitch();//Logview的准备

	std::cout << "Qt Detected:" << QT_VERSION_MAJOR << "." << QT_VERSION_MINOR << "." << QT_VERSION_PATCH << std::endl;
#ifdef _DEBUG
	std::cout << "Evision is in debug mode and running slowly!" << std::endl;
	std::cout << "Evision正处于调试模式,运行速度受限." << std::endl;

#else
	std::cout << "Evision is in release mode and running at full speed!" << std::endl;
	std::cout << "Evision正处于部署模式,全速运行." << std::endl;
#endif
}
//显示单目相机视图
void EvisionView::onCamera()
{
	auto _camera = EvisionCameraFactory::CreateCameraView(this);
	ui.mdiArea->addSubWindow(_camera);
	_camera->show();
}
//显示双目相机视图
void EvisionView::onStereoCamera()
{
	auto _stereoCamera = EvisionCameraFactory::CreateStereoCameraView(this);
	ui.mdiArea->addSubWindow(_stereoCamera);
	_stereoCamera->show();
}
//显示点云
void EvisionView::onShowPointCloud()
{
#if (defined WITH_PCL) 
	//QWidget  * evision3dViz = Evision3dVizFactory::CreateEvision3dViz();
	//ui.mdiArea->addSubWindow(evision3dViz);
	//evision3dViz->show();
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog->setWindowTitle(QStringLiteral("请选择点云文件"));
	fileDialog->setNameFilter(QStringLiteral("pcl点云文件(*.pcd)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		QWidget* evisionCloudViewer =
			EvisionCloudViewerFactory::CreateEvisionEvisionCloudViewer(fileDialog->selectedFiles().at(0).toStdString(), this);
		ui.mdiArea->addSubWindow(evisionCloudViewer);
		evisionCloudViewer->showMaximized();
		evisionCloudViewer->show();
	}

#else
	QMessageBox::information(this, QStringLiteral("该功能未启用!"),
		QStringLiteral("请在项目属性/C++/预处理器中添加\"WITH_PCL\",配置好PCL和VTK依赖,并确认Evision3dViz模块正常工作!"));
#endif
}
//显示标定视图
void EvisionView::on_action_calibrate_view()
{
	auto m_calibrate = EvisionCalibrateFactory::CreateEvisionCalibrateViewer(this);
	ui.mdiArea->addSubWindow(m_calibrate);
	m_calibrate->show();
}
//显示矫正视图
void EvisionView::on_action_rectify()
{
	auto m_Rectify = EvisionUndistortionFactory::CreateEvisionUndistortionView(this);
	ui.mdiArea->addSubWindow(m_Rectify);
	m_Rectify->show();
}
//显示立体匹配视图
void EvisionView::on_action_stereoMatch_view()
{
	auto m_matcher = EvisionDisparityFactory::CreateEvisionDisparity(this);
	ui.mdiArea->addSubWindow(m_matcher);
	m_matcher->show();
}
//显示交互式测距视图
void EvisionView::on_action_Measure_view()
{
	auto _Rfinterface = EvisionTraceFactory::CreateEvisionTraceView(this);
	ui.mdiArea->addSubWindow(_Rfinterface);
	_Rfinterface->show();
}
//启动目标检测视图
void EvisionView::on_action_ObjectDetection_view()
{
#ifdef WITH_CUDA
	auto _ObjectDetectionView = EvisionObjDetectionFactory::CreateEvisionEvisionCloudViewer(this);
	ui.mdiArea->addSubWindow(_ObjectDetectionView);
	_ObjectDetectionView->show();
#else
	QMessageBox::information(this, QStringLiteral("该功能未启用!"),
		QStringLiteral("请在项目属性/C++/预处理器中添加\"WITH_CUDA\"并确保EvisionObjDetection模块正常工作"));
#endif
}
//启动几何体追踪
void EvisionView::on_action_PolyTracker_view()
{
	auto tracker = EvisionPolyTrackerFactory::CreateEvisionPolyTrackerViewer(this);
	ui.mdiArea->addSubWindow(tracker);
	tracker->show();
}
//LogView
void EvisionView::on_action_LogViewSwitch()
{
	logView = LogView::getInstance();
	logView->show();

	old_pos = this->pos();
	old_size = this->size();
	logView->move(*new QPoint(old_pos.x() + 10 + this->frameGeometry().width(), old_pos.y()));
}
//视差转点云
void EvisionView::on_action_disp_to_pcd()
{
#ifdef WITH_PCL
	//1.选择视差
	cv::Mat RawDisp, img, Q;
	bool ok = false;
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	QString dispFilename;
	fileDialog->setWindowTitle(QStringLiteral("请选择原始视差文件"));
	fileDialog->setNameFilter(QStringLiteral("序列化(*.xml)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		try
		{
			dispFilename = fileDialog->selectedFiles().at(0);
			cv::FileStorage fStorage(dispFilename.toStdString(), cv::FileStorage::READ);
			fStorage["disp"] >> RawDisp;
			fStorage.release();
			ok = true;
		}
		catch (cv::Exception e)
		{
			std::cout << "原始视差数据读取失败!" << e.err << std::endl;
		}
	}
	else
	{
		return;
	}
	if (ok)
	{
		ok = false;
		fileDialog->setWindowTitle(QStringLiteral("请选择参与生成所选视差图的左视图或右视图"));
		fileDialog->setNameFilter(QStringLiteral("图片文件(*.jpg *.png *.jpeg *.bmp)"));
		fileDialog->setFileMode(QFileDialog::ExistingFile);
		if (fileDialog->exec() == QDialog::Accepted)
		{
			try
			{
				img = cv::imread(fileDialog->selectedFiles().at(0).toStdString());
				ok = true;
			}
			catch (cv::Exception e)
			{
				std::cout << "原图读取失败!" << e.err << std::endl;
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	if (ok)
	{
		ok = false;
		fileDialog->setWindowTitle(QStringLiteral("请选择相机参数文件"));
		fileDialog->setNameFilter(QStringLiteral("序列化文件(*.xml *.yml)"));
		fileDialog->setFileMode(QFileDialog::ExistingFile);
		if (fileDialog->exec() == QDialog::Accepted)
		{
			try
			{
				cv::FileStorage fStorage(fileDialog->selectedFiles().at(0).toStdString(), cv::FileStorage::READ);
				fStorage["Q"] >> Q;
				fStorage.release();
				ok = true;
			}
			catch (cv::Exception e)
			{
				std::cout << "相机参数读取失败!" << e.err << std::endl;
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	if (ok)
	{
		QFileInfo* _fileInfo = new QFileInfo(dispFilename);//path like F:/test/123.xml
		std::string filename = _fileInfo->absolutePath().toStdString().//F:/test
			append("/").												   //F:/test/
			append(_fileInfo->baseName().toStdString()).				   //F:/test/123
			append(".pcd");												   //F:/test/123.pcd
		EvisionCloudViewerFactory::createAndSavePointCloud(RawDisp, img, Q, filename);
	}
#else
	QMessageBox::information(this, QStringLiteral("该功能未启用!"), QStringLiteral("请在项目属性/C++/预处理器中添加\"WITH_PCL\"并配置好PCL依赖"));
#endif
}
//创建相机参数文件
void EvisionView::on_action_create_param()
{
	auto _createCameraParamFile = EvisionParamBridgeFactory::CreateEvisionParamBridgeView(this);
	ui.mdiArea->addSubWindow(_createCameraParamFile);
	_createCameraParamFile->show();
}
//打开单目标定视图
void EvisionView::on_action_MonocularCalib_view()
{
	auto _monocularCalibView = EvisionMonocularCalibFactory::CreateEvisionMonocularCalibViewer(this);
	ui.mdiArea->addSubWindow(_monocularCalibView);
	_monocularCalibView->show();
}
//状态栏更新
void EvisionView::onParamChanged_StatusBarText()
{
	msgLabel->setText(m_entity->getStatusBarText());
}
//文件被拖到窗口区域上
void EvisionView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
	{
		event->acceptProposedAction();
		//QMessageBox::information(NULL, QStringLiteral("消息"), QStringLiteral("文件被拖上来"));
		m_entity->setStatusBarText("Drop the file for open!");
	}
}
//文件在窗口区域上被放下
void EvisionView::dropEvent(QDropEvent* event)
{
	m_entity->setStatusBarText(QStringLiteral("就绪"));
	//QMessageBox::information(NULL, QStringLiteral("消息"), QStringLiteral("文件被释放在窗口上"));
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
	{
		return;
	}
	else if (urls.size() > 1)
	{
		//QMessageBox::information(NULL, QStringLiteral("消息"), QStringLiteral("多于一个文件"));
	}
	else if (urls.size() == 1)
	{
		//QMessageBox::information(NULL, QStringLiteral("消息"), QStringLiteral("一个文件"));
		//文件分类识别和打开
		QString file_name = urls[0].toLocalFile();
		QFileInfo fileinfo(file_name);
		if (!fileinfo.isFile())//不是文件
		{
			return;
		}
		else
		{
			if (fileinfo.suffix() == "png" || fileinfo.suffix() == "jpg" ||
				fileinfo.suffix() == "jpeg")
			{
				WatchImageView* m_WatchImage = new WatchImageView(file_name);
				ui.mdiArea->addSubWindow(m_WatchImage);
				m_WatchImage->show();
			}
		}
	}

}
//鼠标释放事件
void EvisionView::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_entity->setStatusBarText(QStringLiteral("就绪"));
	}
}
//窗口移动事件
void EvisionView::moveEvent(QMoveEvent* event)
{
	//QWidget::moveEvent(event);
	QPoint delta = this->pos() - old_pos;
	//算出主窗口的移动量
	//子窗口进行等量移动
	logView->move(delta + *new QPoint(old_pos.x() + 10 + this->frameGeometry().width(), old_pos.y()));
	old_pos = this->pos();
}

void EvisionView::resizeEvent(QResizeEvent* event)
{
	if (this->size().width() != old_size.width())
	{
		logView->move(*new QPoint(old_pos.x() + 10 + this->frameGeometry().width(), old_pos.y()));
		old_size = this->size();
	}
}

void EvisionView::changeEvent(QEvent* event)
{
	if (event->type() != QEvent::WindowStateChange) return;
	if (this->windowState() == Qt::WindowMaximized)//最大化
	{
		//logView->setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint);
	}
	if (this->windowState() == Qt::WindowMinimized)//最小化
	{
		//logView->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

	}
}

void EvisionView::closeEvent(QCloseEvent* event)
{
	logView->close();
}
