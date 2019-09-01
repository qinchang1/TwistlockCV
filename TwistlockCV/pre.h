#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_pre.h"

class binPara
{
public:
	binPara() :lowThreshold(0), highThreshold(0), dilatePara(0),
		erodePara(0), blurPara(1) {};
	binPara(int p1, int p2, int p3, int p4, int p5)
	{
		lowThreshold = p1;
		highThreshold = p2;
		dilatePara = p3;
		erodePara = p4;
		blurPara = p5;
	};
	int lowThreshold;
	int highThreshold;
	int dilatePara;
	int erodePara;
	int blurPara;
	void set(int p1, int p2, int p3, int p4, int p5)
	{
		lowThreshold = p1;
		highThreshold = p2;
		dilatePara = p3;
		erodePara = p4;
		blurPara = p5;
	};
};

class preWindow : public QMainWindow
{
	Q_OBJECT

public:
	preWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::preWindow ui;

	private slots:
	void on_ok_Button_clicked();
	void on_default_Button_clicked();
	void on_lowTh_horizontalSlider_valueChanged();
	void on_highTh_horizontalSlider_valueChanged();
	void on_dilate_horizontalSlider_valueChanged();
	void on_erode_horizontalSlider_valueChanged();
	void on_blur_horizontalSlider_valueChanged();
	void on_lowTh_horizontalSlider_2_valueChanged();
	void on_highTh_horizontalSlider_2_valueChanged();
	void on_dilate_horizontalSlider_2_valueChanged();
	void on_erode_horizontalSlider_2_valueChanged();
	void on_blur_horizontalSlider_2_valueChanged();
	void on_binary_checkBox_clicked();
};
