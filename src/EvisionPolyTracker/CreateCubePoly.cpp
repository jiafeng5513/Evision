#include "CreateCubePoly.h"
#include "Utils.h"
#include <QDateTime>
#include <QMessageBox>

EvisionCreateCubePoly::EvisionCreateCubePoly(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    std::string datapath = getCurrentPath() + "\\..\\..\\..\\data";
    this->save_path = datapath + "\\Tracker";
    ui.lineEdit_savepath->setText(QString::fromStdString(this->save_path));
}

void EvisionCreateCubePoly::onPush_confirm() 
{
    
    if (!ui.lineEdit_savepath->text().isEmpty() && 
        (this->length = ui.lineEdit_length->text().toDouble()) > 0 &&
        (this->width = ui.lineEdit_width->text().toDouble()) > 0 &&
        (this->height = ui.lineEdit_height->text().toDouble()) > 0 )
    {
        std::vector<float> size;
        size.push_back(length);
        size.push_back(width);
        size.push_back(height);

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
}

void EvisionCreateCubePoly::onPush_cancel()
{
    this->close();
}
