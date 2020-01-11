#include "para.h"

// yolo����
float confThreshold = 0.4;
float nmsThreshold = 0.3;
int inpWidth = 416;
int inpHeight = 416;
// ƥ�����
int featureType = 0;
int featureCreatePara = 1000;
double errorRange = 0.03;
// ����ͷ����
CamPara camPara1(1022.928968, -34.5373582, 0.732326515, -0.00660332);
CamPara camPara2(1022.928968, -34.5373582, 0.732326515, -0.00660332);
// ��λ����
double kCam1 = 0.002351668;
double kCam2 = 0.002351668;
double bCam1 = 1.444095622;
double bCam2 = 1.444095622;

// �ж��ǲ������ֵĺ���
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
	// ��ȡĬ��ֵ******
	confThreshold0 = confThreshold;
	nmsThreshold0 = nmsThreshold;
	inpWidth0 = inpWidth;
	inpHeight0 = inpHeight;
	featureType0 = featureType;
	featureCreatePara0 = featureCreatePara;
	errorRange0 = errorRange;
	camPara01 = camPara1;
	camPara02 = camPara2;
	kCam01 = kCam1;
	kCam02 = kCam2;
	bCam01 = bCam1;
	bCam02 = bCam2;
	updateLabel();
}

// �ָ�Ĭ�ϰ�ť******
void ParaWindow::on_default_pushButton_clicked()
{
	confThreshold = confThreshold0;
	nmsThreshold = nmsThreshold0;
	inpWidth = inpWidth0;
	inpHeight = inpHeight0;
	featureType = featureType0;
	featureCreatePara = featureCreatePara0;
	errorRange = errorRange0;
	camPara1 = camPara01;
	camPara2 = camPara02;
	kCam1 = kCam01;
	kCam2 = kCam02;
	bCam1 = bCam01;
	bCam2 = bCam02;
	updateLabel();
}

// ����������ʾ��ǩ******
void ParaWindow::updateLabel()
{
	QString temp;
	// yolo������ʼ��
	temp.sprintf("%.2f", confThreshold);
	ui.confThreshold_Label->setText(temp);
	temp.sprintf("%.2f", nmsThreshold);
	ui.nmsThreshold_Label->setText(temp);
	temp.sprintf("%d", inpWidth);
	ui.inpWidth_Label->setText(temp);
	temp.sprintf("%d", inpHeight);
	ui.inpHeight_Label->setText(temp);
	// ƥ�������ʼ��
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
	// Ĭ��ƫ�Χ����
	temp.sprintf("%.3f", errorRange);
	ui.errorRange_Label->setText(temp);
	// ����ͷ1������ʼ��
	temp.sprintf("%.9f", camPara1.para0);
	ui.cameraPara0_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para1);
	ui.cameraPara1_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para2);
	ui.cameraPara2_Label_1->setText(temp);
	temp.sprintf("%.9f", camPara1.para3);
	ui.cameraPara3_Label_1->setText(temp);
	// ����ͷ2������ʼ��
	temp.sprintf("%.9f", camPara2.para0);
	ui.cameraPara0_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para1);
	ui.cameraPara1_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para2);
	ui.cameraPara2_Label_2->setText(temp);
	temp.sprintf("%.9f", camPara2.para3);
	ui.cameraPara3_Label_2->setText(temp);
	// ��λ������ʼ��
	temp.sprintf("%.9f", kCam1);
	ui.k_Para_Label_1->setText(temp);
	temp.sprintf("%.9f", kCam2);
	ui.k_Para_Label_2->setText(temp);
	temp.sprintf("%.9f", bCam1);
	ui.b_Para_Label_1->setText(temp);
	temp.sprintf("%.9f", bCam2);
	ui.b_Para_Label_2->setText(temp);
}

// �޸İ�ť����
void ParaWindow::on_update_pushButton_clicked()
{
	if (!ui.confThreshold_lineEdit->text().isEmpty()) {
		QString temp = ui.confThreshold_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			confThreshold = temp.toDouble();
			ui.confThreshold_Label->setText(temp);
		}
		ui.confThreshold_lineEdit->clear();
	}
	if (!ui.nmsThreshold_lineEdit->text().isEmpty()) {
		QString temp = ui.nmsThreshold_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			nmsThreshold = temp.toDouble();
			ui.nmsThreshold_Label->setText(temp);
		}
		ui.nmsThreshold_lineEdit->clear();
	}
	if (!ui.inpWidth_lineEdit->text().isEmpty()) {
		QString temp = ui.inpWidth_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			inpWidth = temp.toDouble();
			ui.inpWidth_Label->setText(temp);
		}
		ui.inpWidth_lineEdit->clear();
	}
	if (!ui.inpHeight_lineEdit->text().isEmpty()) {
		QString temp = ui.inpHeight_lineEdit->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			inpHeight = temp.toDouble();
			ui.inpHeight_Label->setText(temp);
		}
		ui.inpHeight_lineEdit->clear();
	}
	//******************* ƥ����� ********************//
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

	//****************** �Ӳ�ɸѡ��Χ ********************//
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
	//******************* ����ͷ1���� ********************//
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

	//******************* ����ͷ2���� ********************//
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
	//******************* ��λ���� ********************//
	if (!ui.k_Para_lineEdit_1->text().isEmpty()) {
		QString temp = ui.k_Para_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			kCam1 = temp.toDouble();
			ui.k_Para_lineEdit_1->setText(temp);
		}
		ui.k_Para_lineEdit_1->clear();
	}
	if (!ui.k_Para_lineEdit_2->text().isEmpty()) {
		QString temp = ui.k_Para_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			kCam2 = temp.toDouble();
			ui.k_Para_lineEdit_2->setText(temp);
		}
		ui.k_Para_lineEdit_2->clear();
	}
	if (!ui.b_Para_lineEdit_1->text().isEmpty()) {
		QString temp = ui.b_Para_lineEdit_1->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			bCam1 = temp.toDouble();
			ui.b_Para_lineEdit_1->setText(temp);
		}
		ui.b_Para_lineEdit_1->clear();
	}
	if (!ui.b_Para_lineEdit_2->text().isEmpty()) {
		QString temp = ui.b_Para_lineEdit_2->text();
		bool isNum = QStringIsNum(temp);
		if (isNum) {
			bCam2 = temp.toDouble();
			ui.b_Para_lineEdit_2->setText(temp);
		}
		ui.b_Para_lineEdit_2->clear();
	}
}

void ParaWindow::on_cancel_pushButton_clicked()
{
	this->close();
}