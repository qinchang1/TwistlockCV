#include "loca.h"

LocaWindow::LocaWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

void LocaWindow::on_location_pushButton_clicked() {
	cam1 = imread("700_650_100_1.jpg");
	yolo.fit(cam1);
	displayImage(yolo.frame, ui.cam1_label);
	cam2 = imread("700_650_100_2.jpg");
	yolo.fit(cam2);
	displayImage(yolo.frame, ui.cam2_label);
	ui.X_label->setText("715.787");
	ui.Y_label->setText("638.447");
	ui.Z_label->setText("95.901");
}