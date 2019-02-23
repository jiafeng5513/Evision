#include "MatcherView.h"
#include "EvisionUtils.h"
#include "math.h"
#include<qDebug>
MatcherView::MatcherView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_entity = StereoMatchParamEntity::getInstance();
	m_controller = new StereoMatchController();
	connect(m_entity, SIGNAL(paramChanged_MinDisp()), this, SLOT(onParamChanged_MinDisp()));
	connect(m_entity, SIGNAL(paramChanged_Uniradio()), this, SLOT(onParamChanged_uniradio()));
	connect(m_entity, SIGNAL(paramChanged_Specwinsz()), this, SLOT(onParamChanged_specwinsz()));
	connect(m_entity, SIGNAL(paramChanged_NumDisparities()), this, SLOT(onParamChanged_NumDisparities()));
	connect(m_entity, SIGNAL(paramChanged_Specrange()), this, SLOT(onParamChanged_Specrange()));
	connect(m_entity, SIGNAL(paramChanged_Prefilcap()), this, SLOT(onParamChanged_Prefilcap()));
	connect(m_entity, SIGNAL(paramChanged_SadWinsz()), this, SLOT(onParamChanged_SadWinSize()));
	connect(m_entity, SIGNAL(paramChanged_TextThread()), this, SLOT(onParamChanged_TextThread()));
	connect(m_entity, SIGNAL(paramChanged_Maxdifdisp12()), this, SLOT(onParamChanged_MaxDifdisp2()));
	connect(m_entity, SIGNAL(paramChanged_BM()), this, SLOT(onParamChanged_BM()));
	connect(m_entity, SIGNAL(paramChanged_SGBM()), this, SLOT(onParamChanged_SGBM()));
	connect(m_entity, SIGNAL(paramChanged_MODE_HH()), this, SLOT(onParamChanged_MODE_HH()));
	connect(m_entity, SIGNAL(paramChanged_ImageDtoShow()), this, SLOT(onParamChanged_imgDtoShow())/*, Qt::QueuedConnection*/);
	connect(m_entity, SIGNAL(paramChanged_IconImgL()), this, SLOT(onParamChanged_IconImgL()));
	connect(m_entity, SIGNAL(paramChanged_IconImgR()), this, SLOT(onParamChanged_IconImgR()));
	connect(m_entity, SIGNAL(paramChanged_IconRawDisp()), this, SLOT(onParamChanged_IconRawDisp()));
	connect(m_entity, SIGNAL(paramChanged_IconFixDisp()), this, SLOT(onParamChanged_IconFixDisp()));
	connect(m_entity, SIGNAL(paramChanged_IconPcolorDisp()), this, SLOT(onParamChanged_IconPcolorDisp()));
	connect(m_entity, SIGNAL(paramChanged_ImageToShow()), this, SLOT(onParamChanged_ImageToShow()));
	connect(m_entity, SIGNAL(paramChanged_UseExpeModule()), this, SLOT(onParamChanged_UseExpeModule()));
	connect(m_entity, SIGNAL(paramChanged_DoRectify()), this, SLOT(onParamChanged_DoRectify()));

	m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
}

MatcherView::~MatcherView()
{
}
//默认匹配参数
void MatcherView::setDefaultMatchParam()
{
	m_controller->setDefaultMatchParamCommand();
}
//匹配
void MatcherView::doMatch()
{
	m_controller->MatchCommand();
}
//刷新匹配结果
void MatcherView::RefreshStereoMatch()
{
	m_controller->RefreshStereoMatchCommand();
}

void MatcherView::valueChanged_MinDisp(int value)
{
	ui.lineEdit_MinDisp->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMinDisp() != value)
	{
		m_entity->setMinDisp(value);
	}
}
void MatcherView::onParamChanged_MinDisp()
{
	ui.horizontalSlider_MinDisp->setValue(m_entity->getMinDisp());
}

void MatcherView::valueChanged_uniradio(int value)
{
	ui.lineEdit_uniradio->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getUniradio() != value)
	{
		m_entity->setUniradio(value);
	}
}

void MatcherView::onParamChanged_uniradio()
{
	ui.horizontalSlider_uniradio->setValue(m_entity->getUniradio());
}

void MatcherView::valueChanged_specwinsz(int value)
{
	ui.lineEdit_specwinsz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecwinsz() != value)
	{
		m_entity->setSpecwinsz(value);
	}
}

void MatcherView::onParamChanged_specwinsz()
{
	ui.horizontalSlider_specwinsz->setValue(m_entity->getSpecwinsz());

}

void MatcherView::valueChanged_NumDisparities(int value)
{
	ui.lineEdit_NumDisparities->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getNumDisparities() != value)
	{
		m_entity->setNumDisparities(value);
	}
}

void MatcherView::onParamChanged_NumDisparities()
{
	ui.horizontalSlider_NumDisparities->setValue(m_entity->getNumDisparities());

}

void MatcherView::onReleased_NumDisparities()
{
	int oldvalue=ui.horizontalSlider_NumDisparities->value();
	if(oldvalue%16!=0)
	{
		ui.horizontalSlider_NumDisparities->setValue(oldvalue - oldvalue % 16);
	}
}

void MatcherView::valueChanged_Specrange(int value)
{
	ui.lineEdit_specrange->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecrange() != value)
	{
		m_entity->setSpecrange(value);
	}
}

void MatcherView::onParamChanged_Specrange()
{
	ui.horizontalSlider_specrange->setValue(m_entity->getSpecrange());

}

void MatcherView::valueChanged_Prefilcap(int value)
{
	ui.lineEdit_prefilcap->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getPrefilcap() != value)
	{
		m_entity->setPrefilcap(value);
	}
}

void MatcherView::onParamChanged_Prefilcap()
{
	ui.horizontalSlider_prefilcap->setValue(m_entity->getPrefilcap());

}

void MatcherView::valueChanged_SadWinSize(int value)
{
	ui.lineEdit_SadWinSiz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSadWinsz() != value)
	{
		m_entity->setSadWinsz(value);
	}
}

void MatcherView::onParamChanged_SadWinSize()
{
	ui.horizontalSlider_SadWinSiz->setValue(m_entity->getSadWinsz());

}

void MatcherView::onReleased_SadWinSize()
{
	int oldvalue = ui.horizontalSlider_SadWinSiz->value();
	if(oldvalue%2==0)
	{
		ui.horizontalSlider_SadWinSiz->setValue(max(oldvalue-1,5));
	}
}

void MatcherView::valueChanged_TextThread(int value)
{
	ui.lineEdit_textThread->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getTextThread() != value)
	{
		m_entity->setTextThread(value);
	}
}

void MatcherView::onParamChanged_TextThread()
{
	ui.horizontalSlider_textThread->setValue(m_entity->getTextThread());

}

void MatcherView::valueChanged_MaxDifdisp2(int value)
{
	ui.lineEdit_maxdifdisp12->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMaxdifdisp12() != value)
	{
		m_entity->setMaxdifdisp12(value);
	}
}

void MatcherView::onParamChanged_MaxDifdisp2()
{
	ui.horizontalSlider_maxdifdisp12->setValue(m_entity->getMaxdifdisp12());

}

void MatcherView::onClicked_BM(bool value)
{
	if (m_entity->getBM() != value)
	{
		m_entity->setBM(value);
	}
	ui.horizontalSlider_textThread->setEnabled(true);
	ui.radioButton_MODE_HH->setEnabled(false);
	ui.radioButton_MODE_SGBM->setEnabled(false);
	ui.radioButton_MODE_3WAY->setEnabled(false);
}

void MatcherView::onParamChanged_BM()
{
	ui.radioButton_BM->setChecked(m_entity->getBM());

}

void MatcherView::onClicked_SGBM(bool value)
{
	if (m_entity->getSGBM() != value)
	{
		m_entity->setSGBM(value);
	}

	ui.horizontalSlider_textThread->setEnabled(false);
	ui.radioButton_MODE_HH->setEnabled(true);
	ui.radioButton_MODE_SGBM->setEnabled(true);
	ui.radioButton_MODE_3WAY->setEnabled(true);
}

void MatcherView::onParamChanged_SGBM()
{
	ui.radioButton_SGBM->setChecked(m_entity->getSGBM());

}

void MatcherView::onClicked_MODE_HH(bool value)
{
	if (m_entity->getMODE_HH() != value)
	{
		m_entity->setMODE_HH(value);
	}
}
//复选框:进行校正
void MatcherView::onClicked_DoRectify(bool value)
{
	if(m_entity->getDoRectify()!= value)
	{
		m_entity->setDoRectify(value);
	}
}
//
void MatcherView::onParamChanged_DoRectify()
{
	ui.checkBox_DoRectify->setChecked(m_entity->getDoRectify());
}

//复选框:使用实验性匹配模块
void MatcherView::onClicked_UseExpeModule(bool value)
{
	if(m_entity->getUseExpeModule()!=value)
	{
		m_entity->setUseExpeModule(value);
	}
}

void MatcherView::onParamChanged_UseExpeModule()
{
	ui.checkBox_useExpeModule->setChecked(m_entity->getUseExpeModule());
}

void MatcherView::onParamChanged_MODE_HH()
{
	ui.radioButton_MODE_HH->setChecked(m_entity->getMODE_HH());

}

void MatcherView::onClicked_MODE_SGBM(bool value)
{
	if (m_entity->getMODE_SGBM() != value)
	{
		m_entity->setMODE_SGBM(value);
	}
}

void MatcherView::onParamChanged_MODE_SGBM()
{
	ui.radioButton_MODE_SGBM->setChecked(m_entity->getMODE_SGBM());

}

void MatcherView::onClicked_MODE_3WAY(bool value)
{
	if (m_entity->getMODE_3WAY() != value)
	{
		m_entity->setMODE_3WAY(value);
	}
}

void MatcherView::onParamChanged_MODE_3WAY()
{
	ui.radioButton_MODE_3WAY->setChecked(m_entity->getMODE_3WAY());

}

void MatcherView::onParamChanged_imgDtoShow()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getImageDtoShow());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_D->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_D->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_D->centerOn(0, 0);
	ui.graphicsView_D->show();
	ui.graphicsView_D->update();
}

void MatcherView::onParamChanged_IconImgL()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconImgL());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_ImageL->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_ImageL->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_ImageL->centerOn(0, 0);
	ui.graphicsView_ImageL->show();
	ui.graphicsView_ImageL->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::IMG_L)
	{
		m_entity->setImageDtoShow(m_entity->getIconImgL());
	}
}

void MatcherView::onParamChanged_IconImgR()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconImgR());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_ImageR->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_ImageR->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_ImageR->centerOn(0, 0);
	ui.graphicsView_ImageR->show();
	ui.graphicsView_ImageR->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::IMG_R)
	{
		m_entity->setImageDtoShow(m_entity->getIconImgR());
	}
}

void MatcherView::onParamChanged_IconRawDisp()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconRawDisp());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_RawDisp->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_RawDisp->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_RawDisp->centerOn(0, 0);
	ui.graphicsView_RawDisp->show();
	ui.graphicsView_RawDisp->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::RAW_DISP)
	{
		m_entity->setImageDtoShow(m_entity->getIconRawDisp());
	}
}

void MatcherView::onParamChanged_IconFixDisp()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconFixDisp());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_FixDisp->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_FixDisp->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_FixDisp->centerOn(0, 0);
	ui.graphicsView_FixDisp->show();
	ui.graphicsView_FixDisp->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::FIX_DISP)
	{
		m_entity->setImageDtoShow(m_entity->getIconFixDisp());
	}
}

void MatcherView::onParamChanged_IconPcolorDisp()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconPcolorDisp());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_PcolorDisp->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_PcolorDisp->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_PcolorDisp->centerOn(0, 0);
	ui.graphicsView_PcolorDisp->show();
	ui.graphicsView_PcolorDisp->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::PCOLOR_DISP)
	{
		m_entity->setImageDtoShow(m_entity->getIconPcolorDisp());
	}
}
//要在中间放大显示的图片发生变更
void MatcherView::onParamChanged_ImageToShow()
{
	//根据枚举值调整单选框的状态
	ui.radioButton_ImageL->setChecked(false);
	ui.radioButton_ImageR->setChecked(false);
	ui.radioButton_FixDisp->setChecked(false);
	ui.radioButton_RawDisp->setChecked(false);
	ui.radioButton_PcolorDisp->setChecked(false);
	switch (m_entity->getImageToShow())
	{
	case StereoMatchParamEntity::IMG_L:
		ui.radioButton_ImageL->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconImgL());
		break;
	case StereoMatchParamEntity::IMG_R:
		ui.radioButton_ImageR->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconImgR());
		break;
	case StereoMatchParamEntity::RAW_DISP:
		ui.radioButton_RawDisp->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconRawDisp());
		break;
	case StereoMatchParamEntity::FIX_DISP:
		ui.radioButton_FixDisp->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconFixDisp());
		break;
	case StereoMatchParamEntity::PCOLOR_DISP:
		ui.radioButton_PcolorDisp->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconPcolorDisp());
		break;
	default:
		break;
	}
}

void MatcherView::onClicked_IconImgL(bool value)
{
	if(m_entity->getImageToShow()!=StereoMatchParamEntity::IMG_L)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_L);
	}
}

void MatcherView::onClicked_IconImgR(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::IMG_R)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_R);
	}
}

void MatcherView::onClicked_IconRawDisp(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::RAW_DISP)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
	}
}

void MatcherView::onClicked_IconFixDisp(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::FIX_DISP)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::FIX_DISP);
	}
}

void MatcherView::onClicked_IconPcolorDisp(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::PCOLOR_DISP)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::PCOLOR_DISP);
	}
}
