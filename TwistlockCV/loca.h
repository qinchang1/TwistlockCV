#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <ui_Loca.h>
#include "cvFunction.h"

class LocaWindow : public QMainWindow
{
	Q_OBJECT

public:
	LocaWindow(QWidget *parent = Q_NULLPTR);

	void displayImage(Mat &src, QLabel *label, double ratio = 0.5) {
		Mat tempImage;
		cvtColor(src, tempImage, CV_BGR2RGB);//only RGB of Qt
		cv::resize(tempImage, tempImage, Size(), ratio, ratio);
		QImage srcQImage = QImage((uchar*)(tempImage.data), tempImage.cols, tempImage.rows, QImage::Format_RGB888);
		label->setPixmap(QPixmap::fromImage(srcQImage));
		label->resize(srcQImage.size());
		label->show();
	}

private:
	Mat cam1, cam2;
	YoloDetect yolo;

	Ui::LocaWin ui;

private slots:
	void on_location_pushButton_clicked();

};
