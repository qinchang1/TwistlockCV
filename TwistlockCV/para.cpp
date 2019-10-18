#include "para.h"

int featureType = 0;
int featureCreatePara = 1000;
double errorRange = 0.03;
CamPara camPara1(1022.928968, -34.5373582, 0.732326515, -0.00660332);
CamPara camPara2(1022.928968, -34.5373582, 0.732326515, -0.00660332);

// 判断是不是数字的函数
bool QStringIsNum(QString src)
{
	bool QsIsNum = true;
	QByteArray temp = src.toLatin1();
	const char *s = temp.data();
	while (*s){
		if ((*s >= '0' && *s <= '9') || *s == '.'){}
		else{
			QsIsNum = false;
			break;
		}
		s++;
	}
	return QsIsNum;
}

ParaWindow::ParaWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// 获取默认值
	featureType0 = featureType;
	featureCreatePara0 = featureCreatePara;
	errorRange0 = errorRange;
	camPara01 = camPara1;
	camPara02 = camPara2;
	updateLabel();
}

// 恢复默认按钮
void ParaWindow::on_default_pushButton_clicked()
{
	featureType = featureType0;
	featureCreatePara = featureCreatePara0;
	errorRange = errorRange0;
	camPara1 = camPara01;
	camPara2 = camPara02;
	updateLabel();
}

// 更新所有显示标签
void ParaWindow::updateLabel()
{
	QString temp;
	// 匹配参数初始化
	ui.matchType_comboBox->setCurrentIndex(featureType);
	if (0 == featureType) {
		ui.matchType_Label->setText("ORB");
	}
	else if (1 == featureType) {
		ui.matchType_Label->setText("SURF");
	}
	else if (2 == featureType) {
		ui.matchType_Label->setText("SIFT");
	}
	temp.sprintf("%d", featureCreatePara);
	ui.minHessian_Label->setText(temp);
	// 默认偏差范围更新
	temp.sprintf("%.3f", errorRange);
	ui.errorRange_Label->setText(temp);
	// 摄像头1参数初始化
	temp.sprintf("%.9f", camPara1.para0);
	ui.cameraPara0_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para1);
	ui.cameraPara1_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para2);
	ui.cameraPara2_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para3);
	ui.cameraPara3_Label_1->setText(temp);
	// 摄像头2参数初始化
	temp.sprintf("%.9f", camPara2.para0);
	ui.cameraPara0_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para1);
	ui.cameraPara1_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para2);
	ui.cameraPara2_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para3);
	ui.cameraPara3_Label_2->setText(temp);
}

void ParaWindow::on_update_pushButton_clicked()
{
	//******************* 匹配参数 ********************//
	switch (ui.matchType_comboBox->currentIndex())
	{
	case 0:// ORB
	{
		QString temp = "ORB";
		ui.matchType_Label->setText(temp);
		featureType = 0;
		break;
	}
	case 1:// SURF
	{
		QString temp = "SURF";
		ui.matchType_Label->setText(temp);
		featureType = 1;
		break;
	}
	case 2:// SIFT
	{
		QString temp = "SIFT";
		ui.matchType_Label->setText(temp);
		featureType = 2;
		break;
	}
	default:
		break;
	}
	if (!ui.minHessian_lineEdit->text().isEmpty())
	{
		QString temp = ui.minHessian_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum)
		{
			featureCreatePara = temp.toDouble();
			ui.minHessian_Label->setText(temp);
		}
		ui.minHessian_lineEdit->clear();
	}

	//****************** 视差筛选范围 ********************//
	if (!ui.errorRange_lineEdit->text().isEmpty())
	{
		QString temp = ui.errorRange_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum)
		{
			errorRange = temp.toDouble();
			ui.errorRange_Label->setText(temp);
		}
		ui.errorRange_lineEdit->clear();
	}
	//******************* 摄像头1参数 ********************//
	if (!ui.cameraPara0_lineEdit_1->text().isEmpty()){
		QString temp = ui.cameraPara0_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara1.para0 = temp.toDouble();
			ui.cameraPara0_Label_1->setText(temp);
		}
		ui.cameraPara0_lineEdit_1->clear();
	}
	if (!ui.cameraPara1_lineEdit_1->text().isEmpty()){
		QString temp = ui.cameraPara1_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara1.para1 = temp.toDouble();
			ui.cameraPara1_Label_1->setText(temp);
		}
		ui.cameraPara1_lineEdit_1->clear();
	}
	if (!ui.cameraPara2_lineEdit_1->text().isEmpty()){
		QString temp = ui.cameraPara2_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara1.para2 = temp.toDouble();
			ui.cameraPara2_Label_1->setText(temp);
		}
		ui.cameraPara2_lineEdit_1->clear();
	}
	if (!ui.cameraPara3_lineEdit_1->text().isEmpty()){
		QString temp = ui.cameraPara3_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara1.para3 = temp.toDouble();
			ui.cameraPara3_Label_1->setText(temp);
		}
		ui.cameraPara3_lineEdit_1->clear();
	}

	//******************* 摄像头2参数 ********************//
	if (!ui.cameraPara0_lineEdit_2->text().isEmpty()){
		QString temp = ui.cameraPara0_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara2.para0 = temp.toDouble();
			ui.cameraPara0_Label_2->setText(temp);
		}
		ui.cameraPara0_lineEdit_2->clear();
	}
	if (!ui.cameraPara1_lineEdit_2->text().isEmpty()){
		QString temp = ui.cameraPara1_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara2.para1 = temp.toDouble();
			ui.cameraPara1_Label_2->setText(temp);
		}
		ui.cameraPara1_lineEdit_2->clear();
	}
	if (!ui.cameraPara2_lineEdit_2->text().isEmpty()){
		QString temp = ui.cameraPara2_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara2.para2 = temp.toDouble();
			ui.cameraPara2_Label_2->setText(temp);
		}
		ui.cameraPara2_lineEdit_2->clear();
	}
	if (!ui.cameraPara3_lineEdit_2->text().isEmpty()){
		QString temp = ui.cameraPara3_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum){
			camPara2.para3 = temp.toDouble();
			ui.cameraPara3_Label_2->setText(temp);
		}
		ui.cameraPara3_lineEdit_2->clear();
	}
}

void ParaWindow::on_cancel_pushButton_clicked()
{
	this->close();
}