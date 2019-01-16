#include "Matcher.h"
#include "EvisionUtils.h"

Matcher::Matcher(QWidget *parent)
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
	connect(m_entity, SIGNAL(paramChanged_msgBuffer()), this, SLOT(onParamChanged_msgBuffer()));
}

Matcher::~Matcher()
{
}
//默认匹配参数
void Matcher::setDefaultMatchParam()
{
	m_controller->setDefaultMatchParamCommand();
}
//匹配
void Matcher::doMatch()
{
	m_controller->MatchCommand();
}
//刷新匹配结果
void Matcher::RefreshStereoMatch()
{
	m_controller->RefreshStereoMatchCommand();
}

void Matcher::valueChanged_MinDisp(int value)
{
	ui.lineEdit_MinDisp->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMinDisp() != value)
	{
		m_entity->setMinDisp(value);
	}
}
void Matcher::onParamChanged_MinDisp()
{
	ui.horizontalSlider_MinDisp->setValue(m_entity->getMinDisp());
}

void Matcher::valueChanged_uniradio(int value)
{
	ui.lineEdit_uniradio->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getUniradio() != value)
	{
		m_entity->setUniradio(value);
	}
}

void Matcher::onParamChanged_uniradio()
{
	ui.horizontalSlider_uniradio->setValue(m_entity->getUniradio());
}

void Matcher::valueChanged_specwinsz(int value)
{
	ui.lineEdit_specwinsz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecwinsz() != value)
	{
		m_entity->setSpecwinsz(value);
	}
}

void Matcher::onParamChanged_specwinsz()
{
	ui.horizontalSlider_specwinsz->setValue(m_entity->getSpecwinsz());

}

void Matcher::valueChanged_NumDisparities(int value)
{
	ui.lineEdit_NumDisparities->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getNumDisparities() != value)
	{
		m_entity->setNumDisparities(value);
	}
}

void Matcher::onParamChanged_NumDisparities()
{
	ui.horizontalSlider_NumDisparities->setValue(m_entity->getNumDisparities());

}

void Matcher::valueChanged_Specrange(int value)
{
	ui.lineEdit_specrange->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecrange() != value)
	{
		m_entity->setSpecrange(value);
	}
}

void Matcher::onParamChanged_Specrange()
{
	ui.horizontalSlider_specrange->setValue(m_entity->getSpecrange());

}

void Matcher::valueChanged_Prefilcap(int value)
{
	ui.lineEdit_prefilcap->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getPrefilcap() != value)
	{
		m_entity->setPrefilcap(value);
	}
}

void Matcher::onParamChanged_Prefilcap()
{
	ui.horizontalSlider_prefilcap->setValue(m_entity->getPrefilcap());

}

void Matcher::valueChanged_SadWinSize(int value)
{
	ui.lineEdit_SadWinSiz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSadWinsz() != value)
	{
		m_entity->setSadWinsz(value);
	}
}

void Matcher::onParamChanged_SadWinSize()
{
	ui.horizontalSlider_SadWinSiz->setValue(m_entity->getSadWinsz());

}

void Matcher::valueChanged_TextThread(int value)
{
	ui.lineEdit_textThread->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getTextThread() != value)
	{
		m_entity->setTextThread(value);
	}
}

void Matcher::onParamChanged_TextThread()
{
	ui.horizontalSlider_textThread->setValue(m_entity->getTextThread());

}

void Matcher::valueChanged_MaxDifdisp2(int value)
{
	ui.lineEdit_maxdifdisp12->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMaxdifdisp12() != value)
	{
		m_entity->setMaxdifdisp12(value);
	}
}

void Matcher::onParamChanged_MaxDifdisp2()
{
	ui.horizontalSlider_maxdifdisp12->setValue(m_entity->getMaxdifdisp12());

}

void Matcher::onClicked_BM(bool value)
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

void Matcher::onParamChanged_BM()
{
	ui.radioButton_BM->setChecked(m_entity->getBM());

}

void Matcher::onClicked_SGBM(bool value)
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

void Matcher::onParamChanged_SGBM()
{
	ui.radioButton_SGBM->setChecked(m_entity->getSGBM());

}

void Matcher::onClicked_MODE_HH(bool value)
{
	if (m_entity->getMODE_HH() != value)
	{
		m_entity->setMODE_HH(value);
	}
}

void Matcher::onParamChanged_MODE_HH()
{
	ui.radioButton_MODE_HH->setChecked(m_entity->getMODE_HH());

}

void Matcher::onClicked_MODE_SGBM(bool value)
{
	if (m_entity->getMODE_SGBM() != value)
	{
		m_entity->setMODE_SGBM(value);
	}
}

void Matcher::onParamChanged_MODE_SGBM()
{
	ui.radioButton_MODE_SGBM->setChecked(m_entity->getMODE_SGBM());

}

void Matcher::onClicked_MODE_3WAY(bool value)
{
	if (m_entity->getMODE_3WAY() != value)
	{
		m_entity->setMODE_3WAY(value);
	}
}

void Matcher::onParamChanged_MODE_3WAY()
{
	ui.radioButton_MODE_3WAY->setChecked(m_entity->getMODE_3WAY());

}

void Matcher::onParamChanged_imgDtoShow()
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

void Matcher::onParamChanged_msgBuffer()
{
	ui.label->setText(m_entity->getmsgBuffer());
}
