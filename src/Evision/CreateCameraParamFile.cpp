#include "CreateCameraParamFile.h"
#include <QMessageBox>

CreateCameraParamFile::CreateCameraParamFile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CreateCameraParamFile::~CreateCameraParamFile()
{
}
/*
 * 校验参数
 */
void CreateCameraParamFile::onPush_check()
{
	checkpass = false;
	fxl = ui.lineEdit_fxl->text().toDouble();
	fyl = ui.lineEdit_fyl->text().toDouble();
	cxl = ui.lineEdit_cxl->text().toDouble();
	cyl = ui.lineEdit_cyl->text().toDouble();
	if (fxl<=0|| fyl<=0|| cxl<=0||cyl<=0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("左相机内参有误!"));
		return;
	}
	fxr = ui.lineEdit_fxr->text().toDouble();
	fyr = ui.lineEdit_fyr->text().toDouble();
	cxr = ui.lineEdit_cxr->text().toDouble();
	cyr = ui.lineEdit_cyr->text().toDouble();

	if (fxr <= 0 || fyr <= 0 || cxr <= 0 || cyr <= 0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("右相机内参有误!"));
		return;
	}
	QList<QString> qlistL = ui.lineEdit_coeffsl->text().split(',', QString::SkipEmptyParts);
	
	for (int i = 0; i < qlistL.size(); ++i)
	{
		coeffsl.push_back(qlistL.at(i).toDouble());
	}
	if (coeffsl.size()==0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("左相机畸变有误!"));
		return;
	}
	QList<QString> qlistR = ui.lineEdit_coeffsr->text().split(',', QString::SkipEmptyParts);
	
	for (int i = 0; i < qlistR.size(); ++i)
	{
		coeffsr.push_back(qlistR.at(i).toDouble());
	}
	if (coeffsr.size() == 0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("右相机畸变有误!"));
		return;
	}
	QList<QString> qlistRotation=ui.lineEdit_R->text().split(',', QString::SkipEmptyParts);
	
	for (int i = 0; i < qlistRotation.size(); ++i)
	{
		rotation.push_back(qlistRotation.at(i).toDouble());
	}
	if (rotation.size() == 0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("旋转矩阵有误!"));
		return;
	}
	QList<QString> qlistTranslation=ui.lineEdit_t->text().split(',', QString::SkipEmptyParts);
	
	for (int i = 0; i < qlistTranslation.size(); ++i)
	{
		translation.push_back(qlistTranslation.at(i).toDouble());
	}
	if (translation.size() == 0)
	{
		QMessageBox::information(this, QStringLiteral("参数不完整"), QStringLiteral("平移矩阵有误!"));
		return;
	}
	QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("校验通过!"));

	checkpass = true;

}
/*
 * 保存参数
 */
void CreateCameraParamFile::onPush_save()
{

}
