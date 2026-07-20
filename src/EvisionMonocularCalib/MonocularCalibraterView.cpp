#include "MonocularCalibraterView.h"
#include "EvisionUtils.h"

MonocularCalibraterView::MonocularCalibraterView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_calib_entity = MonocularCalibrateParamEntity::getInstance();
	m_calib_controller = new MonocularCalibrateController();
	m_MainScene = new QGraphicsScene();
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_BoardWidth, this, &MonocularCalibraterView::onParamChanged_BoardWidth);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_BoardHeight, this, &MonocularCalibraterView::onParamChanged_BoardHeight);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_SquareSize, this, &MonocularCalibraterView::onParamChanged_SquareSize);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_PRINCIPAL_POINT, this, &MonocularCalibraterView::onParamChanged_FIX_PRINCIPAL_POINT);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_ASPECT_RATIO, this, &MonocularCalibraterView::onParamChanged_FIX_ASPECT_RATIO);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_ZERO_TANGENT_DIST, this, &MonocularCalibraterView::onParamChanged_ZERO_TANGENT_DIST);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K1, this, &MonocularCalibraterView::onParamChanged_FIX_K1);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K2, this, &MonocularCalibraterView::onParamChanged_FIX_K2);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K3, this, &MonocularCalibraterView::onParamChanged_FIX_K3);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K4, this, &MonocularCalibraterView::onParamChanged_FIX_K4);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K5, this, &MonocularCalibraterView::onParamChanged_FIX_K5);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_K6, this, &MonocularCalibraterView::onParamChanged_FIX_K6);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_RATIONAL_MODEL, this, &MonocularCalibraterView::onParamChanged_RATIONAL_MODEL);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_THIN_PRISM_MODEL, this, &MonocularCalibraterView::onParamChanged_THIN_PRISM_MODEL);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_S1_S2_S3_S4, this, &MonocularCalibraterView::onParamChanged_FIX_S1_S2_S3_S4);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_TILTED_MODEL, this, &MonocularCalibraterView::onParamChanged_TILTED_MODEL);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_CALIB_FIX_TAUX_TAUY, this, &MonocularCalibraterView::onParamChanged_FIX_TAUX_TAUY);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_BoardTypeIndex, this, &MonocularCalibraterView::onParamChanged_BoardTypeIndex);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_MarkerSize, this, &MonocularCalibraterView::onParamChanged_MarkerSize);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::calibReportReady, this, &MonocularCalibraterView::onCalibReportReady);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_InsertToItemMap, this, &MonocularCalibraterView::onParamChanged_NewToItemMap, Qt::BlockingQueuedConnection);
	connect(m_calib_entity, &MonocularCalibrateParamEntity::paramChanged_ClearItemMap, this, &MonocularCalibraterView::onParamChanged_ClearItemMap);

	connect(ui.comboBox_BoardType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MonocularCalibraterView::onValueChanged_BoardTypeIndex);
	connect(ui.doubleSpinBox_MarkerSize, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MonocularCalibraterView::onValueChanged_MarkerSize);

	onParamChanged_BoardTypeIndex();
	onParamChanged_MarkerSize();
}

MonocularCalibraterView::~MonocularCalibraterView()
{
}
//默认标定参数
void MonocularCalibraterView::setDefaultCalibParam()
{
	m_calib_controller->setDefaultCalibParamCommand();
}
//标定
void MonocularCalibraterView::doCalib()
{
	m_calib_controller->CalibrateCommand();
}

void MonocularCalibraterView::onValueChanged_BoardWidth(QString value)
{
	m_calib_entity->setBoardWidth(value.toInt());
}
void MonocularCalibraterView::onParamChanged_BoardWidth() const
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardWidth()));
	if (tmp != ui.lineEdit_BoardWidth->text())
	{
		ui.lineEdit_BoardWidth->setText(tmp);
	}
}

void MonocularCalibraterView::onValueChanged_BoardHeight(QString value)
{
	m_calib_entity->setBoardHeight(value.toInt());
}
void MonocularCalibraterView::onParamChanged_BoardHeight()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardHeight()));
	if (tmp != ui.lineEdit_BoardHeight->text())
	{
		ui.lineEdit_BoardHeight->setText(tmp);
	}
}

void MonocularCalibraterView::onValueChanged_SquareSize(QString value)
{
	m_calib_entity->setSquareSize(value.toInt());
}

void MonocularCalibraterView::onParamChanged_SquareSize()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getSquareSize()));
	if (tmp != ui.lineEdit_SquareSize->text())
	{
		ui.lineEdit_SquareSize->setText(tmp);
	}
}

void MonocularCalibraterView::onValueChanged_FIX_PRINCIPAL_POINT(bool value)
{
	m_calib_entity->setCALIB_FIX_PRINCIPAL_POINT(value);
}

void MonocularCalibraterView::onParamChanged_FIX_PRINCIPAL_POINT()
{
	if(ui.checkBox_CALIB_FIX_PRINCIPAL_POINT->isChecked()!=m_calib_entity->getCALIB_FIX_PRINCIPAL_POINT())
	{
		ui.checkBox_CALIB_FIX_PRINCIPAL_POINT->setChecked(m_calib_entity->getCALIB_FIX_PRINCIPAL_POINT());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_ASPECT_RATIO(bool value)
{
	m_calib_entity->setCALIB_FIX_ASPECT_RATIO(value);
}

void MonocularCalibraterView::onParamChanged_FIX_ASPECT_RATIO()
{
	if(ui.checkBox_CALIB_FIX_ASPECT_RATIO->isChecked()!=m_calib_entity->getCALIB_FIX_ASPECT_RATIO())
	{
		ui.checkBox_CALIB_FIX_ASPECT_RATIO->setChecked(m_calib_entity->getCALIB_FIX_ASPECT_RATIO());
	}
}

void MonocularCalibraterView::onValueChanged_ZERO_TANGENT_DIST(bool value)
{
	m_calib_entity->setCALIB_ZERO_TANGENT_DIST(value);
}

void MonocularCalibraterView::onParamChanged_ZERO_TANGENT_DIST()
{
	if(ui.checkBox_CALIB_ZERO_TANGENT_DIST->isChecked()!=m_calib_entity->getCALIB_ZERO_TANGENT_DIST())
	{
		ui.checkBox_CALIB_ZERO_TANGENT_DIST->setChecked(m_calib_entity->getCALIB_ZERO_TANGENT_DIST());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_K1(bool value)
{
	m_calib_entity->setCALIB_FIX_K1(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K1()
{
	if(ui.checkBox_CALIB_FIX_K1->isChecked()!=m_calib_entity->getCALIB_FIX_K1())
	{
		ui.checkBox_CALIB_FIX_K1->setChecked(m_calib_entity->getCALIB_FIX_K1());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_K2(bool value)
{
	m_calib_entity->setCALIB_FIX_K2(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K2()
{
	if(ui.checkBox_CALIB_FIX_K2->isChecked()!=m_calib_entity->getCALIB_FIX_K2())
	{
		ui.checkBox_CALIB_FIX_K2->setChecked(m_calib_entity->getCALIB_FIX_K2());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_K3(bool value)
{
	m_calib_entity->setCALIB_FIX_K3(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K3()
{
	if(ui.checkBox_CALIB_FIX_K3->isChecked()!=m_calib_entity->getCALIB_FIX_K3())
	{
		ui.checkBox_CALIB_FIX_K3->setChecked(m_calib_entity->getCALIB_FIX_K3());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_K4(bool value)
{
	m_calib_entity->setCALIB_FIX_K4(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K4()
{
	if(ui.checkBox_CALIB_FIX_K4->isChecked()!=m_calib_entity->getCALIB_FIX_K4())
	{
		ui.checkBox_CALIB_FIX_K4->setChecked(m_calib_entity->getCALIB_FIX_K4());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_K5(bool value)
{
	m_calib_entity->setCALIB_FIX_K5(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K5()
{
	if(ui.checkBox_CALIB_FIX_K5->isChecked()!=m_calib_entity->getCALIB_FIX_K5())
	{
		ui.checkBox_CALIB_FIX_K5->setChecked(m_calib_entity->getCALIB_FIX_K5());
	}
}
void MonocularCalibraterView::onValueChanged_FIX_K6(bool value)
{
	m_calib_entity->setCALIB_FIX_K6(value);
}

void MonocularCalibraterView::onParamChanged_FIX_K6()
{
	if(ui.checkBox_CALIB_FIX_K6->isChecked()!=m_calib_entity->getCALIB_FIX_K6())
	{
		ui.checkBox_CALIB_FIX_K6->setChecked(m_calib_entity->getCALIB_FIX_K6());
	}
}

void MonocularCalibraterView::onValueChanged_RATIONAL_MODEL(bool value)
{
	m_calib_entity->setCALIB_RATIONAL_MODEL(value);
}

void MonocularCalibraterView::onParamChanged_RATIONAL_MODEL()
{
	if(ui.checkBox_CALIB_RATIONAL_MODEL->isChecked()!=m_calib_entity->getCALIB_RATIONAL_MODEL())
	{
		ui.checkBox_CALIB_RATIONAL_MODEL->setChecked(m_calib_entity->getCALIB_RATIONAL_MODEL());
	}
}

void MonocularCalibraterView::onValueChanged_THIN_PRISM_MODEL(bool value)
{
	m_calib_entity->setCALIB_THIN_PRISM_MODEL(value);
}

void MonocularCalibraterView::onParamChanged_THIN_PRISM_MODEL()
{
	if(ui.checkBox_CALIB_THIN_PRISM_MODEL->isChecked()!=m_calib_entity->getCALIB_THIN_PRISM_MODEL())
	{
		ui.checkBox_CALIB_THIN_PRISM_MODEL->setChecked(m_calib_entity->getCALIB_THIN_PRISM_MODEL());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_S1_S2_S3_S4(bool value)
{
	m_calib_entity->setCALIB_FIX_S1_S2_S3_S4(value);
}

void MonocularCalibraterView::onParamChanged_FIX_S1_S2_S3_S4()
{
	if(ui.checkBox_CALIB_FIX_S1_S2_S3_S4->isChecked()!=m_calib_entity->getCALIB_FIX_S1_S2_S3_S4())
	{
		ui.checkBox_CALIB_FIX_S1_S2_S3_S4->setChecked(m_calib_entity->getCALIB_FIX_S1_S2_S3_S4());
	}
}

void MonocularCalibraterView::onValueChanged_TILTED_MODEL(bool value)
{
	m_calib_entity->setCALIB_TILTED_MODEL(value);
}

void MonocularCalibraterView::onParamChanged_TILTED_MODEL()
{
	if(ui.checkBox_CALIB_TILTED_MODEL->isChecked()!=m_calib_entity->getCALIB_TILTED_MODEL())
	{
		ui.checkBox_CALIB_TILTED_MODEL->setChecked(m_calib_entity->getCALIB_TILTED_MODEL());
	}
}

void MonocularCalibraterView::onValueChanged_FIX_TAUX_TAUY(bool value)
{
	m_calib_entity->setCALIB_FIX_TAUX_TAUY(value);
}

void MonocularCalibraterView::onParamChanged_FIX_TAUX_TAUY()
{
	if(ui.checkBox_CALIB_FIX_TAUX_TAUY->isChecked()!=m_calib_entity->getCALIB_FIX_TAUX_TAUY())
	{
		ui.checkBox_CALIB_FIX_TAUX_TAUY->setChecked(m_calib_entity->getCALIB_FIX_TAUX_TAUY());
	}
}

void MonocularCalibraterView::onValueChanged_BoardTypeIndex(int value)
{
	m_calib_entity->setBoardTypeIndex(value);
}

void MonocularCalibraterView::onParamChanged_BoardTypeIndex()
{
	int index = m_calib_entity->getBoardTypeIndex();
	if (ui.comboBox_BoardType->currentIndex() != index)
	{
		ui.comboBox_BoardType->setCurrentIndex(index);
	}
	ui.doubleSpinBox_MarkerSize->setEnabled(index == 3);
}

void MonocularCalibraterView::onValueChanged_MarkerSize(double value)
{
	m_calib_entity->setMarkerSize(static_cast<float>(value));
}

void MonocularCalibraterView::onParamChanged_MarkerSize()
{
	float value = m_calib_entity->getMarkerSize();
	if (!qFuzzyCompare(ui.doubleSpinBox_MarkerSize->value(), static_cast<double>(value)))
	{
		ui.doubleSpinBox_MarkerSize->setValue(static_cast<double>(value));
	}
}

void MonocularCalibraterView::onCalibReportReady(QString report)
{
	ui.plainTextEdit_CalibReport->clear();
	ui.plainTextEdit_CalibReport->appendPlainText(report);
}

/*
 * 新图加入ListView
 */
void MonocularCalibraterView::onParamChanged_NewToItemMap()
{
	QListWidgetItem * item = new QListWidgetItem;
	cv::Mat img = m_calib_entity->getItemMap().at(QString::fromStdString(std::to_string(m_calib_entity->getIndex())));
	QPixmap pixmap = QPixmap::fromImage(EvisionUtils::cvMat2QImage(img));


	item->setIcon(QIcon(pixmap));
	item->setText(QString::fromStdString(std::to_string(m_calib_entity->getIndex())));
	ui.listWidget->addItem(item);
	ui.listWidget->scrollToBottom();

	m_MainScene->clear();
	m_MainScene->addPixmap(pixmap);
	ui.graphicsView->setScene(m_MainScene);
	ui.graphicsView->fitInView(m_MainScene->itemsBoundingRect(), Qt::KeepAspectRatio);
	ui.graphicsView->centerOn(0, 0);
	ui.graphicsView->show();
	ui.graphicsView->update();

	img.release();
}

void MonocularCalibraterView::onParamChanged_ClearItemMap()
{
	ui.listWidget->clear();
}

void MonocularCalibraterView::onItemClicked(QListWidgetItem* item)
{
	m_MainScene->clear();
	m_MainScene->addPixmap(QPixmap::fromImage(EvisionUtils::cvMat2QImage(m_calib_entity->getItemMap().at(item->text()))));
	ui.graphicsView->setScene(m_MainScene);
	ui.graphicsView->fitInView(m_MainScene->itemsBoundingRect(), Qt::KeepAspectRatio);
	ui.graphicsView->centerOn(0, 0);
	ui.graphicsView->show();
	ui.graphicsView->update();
}
/*
 * 保存参数文件
 */
void MonocularCalibraterView::onPush_saveParamsToFile()
{
	m_calib_controller->SaveParamsToFileCommand();
}

