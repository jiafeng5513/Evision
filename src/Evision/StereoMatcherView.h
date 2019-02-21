#pragma once

#include <QWidget>
#include "ui_StereoMatcherView.h"

class StereoMatcherView : public QWidget
{
	Q_OBJECT

public:
	StereoMatcherView(QWidget *parent = Q_NULLPTR);
	~StereoMatcherView();

private:
	Ui::StereoMatcherView ui;
public slots:
	void onPush_SelectedLeftImg();
	void onPush_SelectedRightImg();
	void onPush_LinkStart();
};
