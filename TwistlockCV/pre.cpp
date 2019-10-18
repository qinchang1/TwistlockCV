#include "pre.h"

binPara bin1(0, 140, 2, 7, 9);
binPara bin2(0, 125, 2, 4, 9);
extern bool isBinary;

preWindow::preWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	// ±£´æÄ¬ÈÏ
	bin10 = bin1;
	bin20 = bin2;

	connect(ui.blur_spinBox, SIGNAL(valueChanged(int)), ui.blur_horizontalSlider, SLOT(setValue(int)));
	connect(ui.blur_horizontalSlider, SIGNAL(valueChanged(int)), ui.blur_spinBox, SLOT(setValue(int)));
	connect(ui.dilate_spinBox, SIGNAL(valueChanged(int)), ui.dilate_horizontalSlider, SLOT(setValue(int)));
	connect(ui.dilate_horizontalSlider, SIGNAL(valueChanged(int)), ui.dilate_spinBox, SLOT(setValue(int)));
	connect(ui.erode_spinBox, SIGNAL(valueChanged(int)), ui.erode_horizontalSlider, SLOT(setValue(int)));
	connect(ui.erode_horizontalSlider, SIGNAL(valueChanged(int)), ui.erode_spinBox, SLOT(setValue(int)));
	connect(ui.lowTh_spinBox, SIGNAL(valueChanged(int)), ui.lowTh_horizontalSlider, SLOT(setValue(int)));
	connect(ui.lowTh_horizontalSlider, SIGNAL(valueChanged(int)), ui.lowTh_spinBox, SLOT(setValue(int)));
	connect(ui.highTh_spinBox, SIGNAL(valueChanged(int)), ui.highTh_horizontalSlider, SLOT(setValue(int)));
	connect(ui.highTh_horizontalSlider, SIGNAL(valueChanged(int)), ui.highTh_spinBox, SLOT(setValue(int)));

	connect(ui.blur_spinBox_2, SIGNAL(valueChanged(int)), ui.blur_horizontalSlider_2, SLOT(setValue(int)));
	connect(ui.blur_horizontalSlider_2, SIGNAL(valueChanged(int)), ui.blur_spinBox_2, SLOT(setValue(int)));
	connect(ui.dilate_spinBox_2, SIGNAL(valueChanged(int)), ui.dilate_horizontalSlider_2, SLOT(setValue(int)));
	connect(ui.dilate_horizontalSlider_2, SIGNAL(valueChanged(int)), ui.dilate_spinBox_2, SLOT(setValue(int)));
	connect(ui.erode_spinBox_2, SIGNAL(valueChanged(int)), ui.erode_horizontalSlider_2, SLOT(setValue(int)));
	connect(ui.erode_horizontalSlider_2, SIGNAL(valueChanged(int)), ui.erode_spinBox_2, SLOT(setValue(int)));
	connect(ui.lowTh_spinBox_2, SIGNAL(valueChanged(int)), ui.lowTh_horizontalSlider_2, SLOT(setValue(int)));
	connect(ui.lowTh_horizontalSlider_2, SIGNAL(valueChanged(int)), ui.lowTh_spinBox_2, SLOT(setValue(int)));
	connect(ui.highTh_spinBox_2, SIGNAL(valueChanged(int)), ui.highTh_horizontalSlider_2, SLOT(setValue(int)));
	connect(ui.highTh_horizontalSlider_2, SIGNAL(valueChanged(int)), ui.highTh_spinBox_2, SLOT(setValue(int)));

	ui.lowTh_horizontalSlider->setValue(bin1.lowThreshold);
	ui.highTh_horizontalSlider->setValue(bin1.highThreshold);
	ui.dilate_horizontalSlider->setValue(bin1.dilatePara);
	ui.erode_horizontalSlider->setValue(bin1.erodePara);
	ui.blur_horizontalSlider->setValue(bin1.blurPara);

	ui.lowTh_horizontalSlider_2->setValue(bin2.lowThreshold);
	ui.highTh_horizontalSlider_2->setValue(bin2.highThreshold);
	ui.dilate_horizontalSlider_2->setValue(bin2.dilatePara);
	ui.erode_horizontalSlider_2->setValue(bin2.erodePara);
	ui.blur_horizontalSlider_2->setValue(bin2.blurPara);
}

//************************* video 1 **************************//
void preWindow::on_lowTh_horizontalSlider_valueChanged()
{
	bin1.lowThreshold = ui.lowTh_horizontalSlider->value();
}

void preWindow::on_highTh_horizontalSlider_valueChanged()
{
	bin1.highThreshold = ui.highTh_horizontalSlider->value();
}

void preWindow::on_dilate_horizontalSlider_valueChanged()
{
	bin1.dilatePara = ui.dilate_horizontalSlider->value();
}

void preWindow::on_erode_horizontalSlider_valueChanged()
{
	bin1.erodePara = ui.erode_horizontalSlider->value();
}

void preWindow::on_blur_horizontalSlider_valueChanged()
{
	bin1.blurPara = ui.blur_horizontalSlider->value();
}

//************************* video 2 **************************//
void preWindow::on_lowTh_horizontalSlider_2_valueChanged()
{
	bin2.lowThreshold = ui.lowTh_horizontalSlider_2->value();
}

void preWindow::on_highTh_horizontalSlider_2_valueChanged()
{
	bin2.highThreshold = ui.highTh_horizontalSlider_2->value();
}

void preWindow::on_dilate_horizontalSlider_2_valueChanged()
{
	bin2.dilatePara = ui.dilate_horizontalSlider_2->value();
}

void preWindow::on_erode_horizontalSlider_2_valueChanged()
{
	bin2.erodePara = ui.erode_horizontalSlider_2->value();
}

void preWindow::on_blur_horizontalSlider_2_valueChanged()
{
	bin2.blurPara = ui.blur_horizontalSlider_2->value();
}
//***********************************************************//

void preWindow::on_ok_Button_clicked()
{
	isBinary = 0;
	ui.binary_checkBox->setChecked(false);
	this->close();
}

void preWindow::on_binary_checkBox_clicked()
{
	if (ui.binary_checkBox->isChecked())
	{
		isBinary = 1;
	}
	else
	{
		isBinary = 0;
	}
}

void preWindow::on_default_Button_clicked()
{
	bin1 = bin10;
	bin2 = bin20;

	ui.lowTh_horizontalSlider->setValue(bin1.lowThreshold);
	ui.highTh_horizontalSlider->setValue(bin1.highThreshold);
	ui.dilate_horizontalSlider->setValue(bin1.dilatePara);
	ui.erode_horizontalSlider->setValue(bin1.erodePara);
	ui.blur_horizontalSlider->setValue(bin1.blurPara);

	ui.lowTh_horizontalSlider_2->setValue(bin2.lowThreshold);
	ui.highTh_horizontalSlider_2->setValue(bin2.highThreshold);
	ui.dilate_horizontalSlider_2->setValue(bin2.dilatePara);
	ui.erode_horizontalSlider_2->setValue(bin2.erodePara);
	ui.blur_horizontalSlider_2->setValue(bin2.blurPara);
}