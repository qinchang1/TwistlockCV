#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <ui_Para.h>

bool QStringIsNum(QString src);

class CamPara {
public:
	double para0;
	double para1;
	double para2;
	double para3;
	CamPara(double p0, double p1, double p2, double p3) :para0(p0), para1(p1), para2(p2), para3(p3) {};
	CamPara() {};
};

class ParaWindow : public QMainWindow
{
	Q_OBJECT

public:
	ParaWindow(QWidget *parent = Q_NULLPTR);
	
	void updateLabel();

private:
	Ui::ParaWindow ui;
	// Ä¬ÈÏ²ÎÊý
	float confThreshold0;
	float nmsThreshold0;
	int inpWidth0;
	int inpHeight0;
	int featureType0;
	int featureCreatePara0;
	double errorRange0;
	CamPara camPara01;
	CamPara camPara02;
	double kCam01;
	double kCam02;
	double bCam01;
	double bCam02;

private slots:
	void on_cancel_pushButton_clicked();
	void on_update_pushButton_clicked();
	void on_default_pushButton_clicked();
};