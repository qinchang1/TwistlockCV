#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QMessageBox>
#include <QFileDialog>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <exception>
#include <iostream>
#include "ui_CvSystem.h"
#include "cvFunction.h"
#include "cvThread.h"
#include "pre.h"
#include "para.h"
#include "multi.h"
#include "loca.h"

using namespace std;

#define imageWidth 1280
#define imageHeight 480

class CvSystem : public QMainWindow
{
	Q_OBJECT

public:
	CvSystem(QWidget *parent = Q_NULLPTR);

private:
	Ui::CvSystemClass ui;
	preWindow preWin;
	ParaWindow paraWin;
	MultiWindow multiWin;
	LocaWindow locaWin;

	QTimer *timer;
	VideoCapture capture1,capture2;
	FrameImg frame1, frame2;

	Cam1Thread *cam1fit;
	Cam2Thread *cam2fit;

	double h1 = 0;
	double h2 = 0;
	double w1 = 0;
	double w2 = 0;

	void displayImage(Mat &src, QLabel *label, double ratio, bool isGray = 0);//display image by label
	void readFrame(VideoCapture &capture, FrameImg &frame, QLabel *label, const binPara &bin);//transfer frame to label
	void appendText(const QString &str);
	void setText(const QString &str);
	void showYoloImg1();
	void showYoloImg2();
	void showSplitImg1();
	void showSplitImg2();
	void showMatchImg1();
	void showMatchImg2();
	void finishCamThread1();
	void finishCamThread2();
	double mergeHeight(double h1, double s1, double h2, double s2);
	bool mergeFlag = false;

private slots:
	void outputFrame();
	void on_testButton_clicked();
	void on_display_Button_clicked();
	void on_capType_comboBox_currentIndexChanged();
	void on_capType_comboBox_2_currentIndexChanged();
	void on_stop_Button_clicked();
	void on_start_Button_clicked();
	void on_isYolo_checkBox_1_clicked();
	void on_isYolo_checkBox_2_clicked();

	void on_preSet_Action_triggered();
	void on_paraSet_Action_triggered();
	void on_multiSet_action_triggered();
	void on_location_action_triggered();
};

enum CapType
{
	NONE,
	SIMPLE,
	CAMERA
};

