#include "CreateCubePoly.h"
#include "EvisionUtils.h"
#include "Utils.h"
#include <QDateTime>
#include <QMessageBox>
#include <QFileInfo>

EvisionCreateCubePoly::EvisionCreateCubePoly(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    std::string datapath = EvisionUtils::getCurrentPath() + "\\..\\..\\..\\data";
    this->save_path = EvisionUtils::pathPurify(datapath + "\\Tracker");
    ui.lineEdit_savepath->setText(QString::fromStdString(this->save_path));
}

void EvisionCreateCubePoly::onPush_confirm() 
{
    
    QFileInfo* fileinfo = new QFileInfo(ui.lineEdit_savepath->text());
    if ((fileinfo->exists()&& fileinfo->isDir()) &&
        (this->length = ui.lineEdit_length->text().toDouble()) > 0 &&
        (this->width = ui.lineEdit_width->text().toDouble()) > 0 &&
        (this->height = ui.lineEdit_height->text().toDouble()) > 0 )
    {
        std::vector<float> size;
        size.push_back(length);
        size.push_back(width);
        size.push_back(height);

        this->save_path = ui.lineEdit_savepath->text().toStdString();
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyyMMddhhmmss");
        std::string plyFileName = this->save_path + "/" + current_date.toStdString() + ".ply";
        createCubePly(size, plyFileName);
        std::cout << "已生成网格文件:" << plyFileName << std::endl;
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("注意"), QStringLiteral("参数不完整!"));
    }
    delete fileinfo;
}

void EvisionCreateCubePoly::onPush_cancel()
{
    this->close();
}
