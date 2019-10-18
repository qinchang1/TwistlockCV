#include "CvSystem.h"

CapType capType1 = SIMPLE;//camera1 input type
CapType capType2 = NONE;//camera2 input tpye
bool isBinary = 0;//default image is RGB
bool isStart = false; //是否已经开始

//******** 匹配算法 ********//
extern int featureType;

//****** Binary parameter *****//
extern binPara bin1;
extern binPara bin2;

//******** 提取的图像 *********//
extern ImgClass cam1;
extern ImgClass cam2;

//******** 摄像头参数 *********//
extern CamPara camPara1;
extern CamPara camPara2;

//******** 处理后的图像 *********//
extern SplitImg split1;
extern SplitImg split2;
extern ContourReco contour1_l;
extern ContourReco contour1_r;
extern ContourReco contour2_l;
extern ContourReco contour2_r;
extern FeatureMatch match1;
extern FeatureMatch match2;

// 主界面初始化参数
CvSystem::CvSystem(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	timer = new QTimer(this);
	cam1fit = new Cam1Thread();
	cam2fit = new Cam2Thread();
	connect(timer, SIGNAL(timeout()), this, SLOT(outputFrame()));
	connect(cam1fit, &Cam1Thread::finishSplit, this, &CvSystem::showSplitImg1);
	connect(cam2fit, &Cam2Thread::finishSplit, this, &CvSystem::showSplitImg2);
	connect(cam1fit, &Cam1Thread::finishMatch, this, &CvSystem::showMatchImg1);
	connect(cam2fit, &Cam2Thread::finishMatch, this, &CvSystem::showMatchImg2);
	connect(cam1fit, &Cam1Thread::finishAll, this, &CvSystem::finishCamThread1);
	connect(cam2fit, &Cam2Thread::finishAll, this, &CvSystem::finishCamThread2);
	ui.start_Button->setEnabled(false);
}

//********************************************************//
//***************** Interface Function *******************//
//********************************************************//

// 显示框加一行文字
void CvSystem::appendText(const QString &str) {
	QString temp = str;
	ui.textBrowser->append(temp);
}

// 显示框清空显示文字
void CvSystem::setText(const QString &str) {
	QString temp = str;
	ui.textBrowser->setText(temp);
}

void CvSystem::on_preSet_Action_triggered() {
	preWin.show(); // open pretreatment window
}

void CvSystem::on_paraSet_Action_triggered() {
	paraWin.show(); // 显示参数配置窗口
}

//********************************************************//
//****************** Button Function *********************//
//********************************************************//

void CvSystem::on_display_Button_clicked(){
	// 清空各个图像控件
	ui.leftFrame_Label_1->clear();
	ui.leftFrame_Label_2->clear();
	ui.rightFrame_Label_1->clear();
	ui.rightFrame_Label_2->clear();
	ui.matchFrame_Label_1->clear();
	ui.matchFrame_Label_2->clear();
	ui.detectionFrame_Label_1->clear();
	ui.detectionFrame_Label_2->clear();
	//////////////////////video 1
	isStart = true;
	switch (capType1)
	{
	case 1:
	{
		ui.textBrowser->append("导入演示视频1...");
		capture1.open("simple1.mp4");
		break;
	}
	case 2:
	{
		ui.textBrowser->append("导入摄像头1...");
		capture1.open(0);
		break;
	}
	default:
	{
		ui.textBrowser->append("视频源1导入错误！");
		break;
	}
	//////////////////////video 2
	}
	switch (capType2)
	{
	case 0:
	{
		ui.textBrowser->append("视频源2未导入");
		break;
	}
	case 1:
	{
		ui.textBrowser->append("导入演示视频2...");
		capture2.open("simple2.mp4");
		break;
	}
	case 2:
	{
		ui.textBrowser->append("导入摄像头2...");
		capture2.open(1);
		break;
	}
	default:
	{
		ui.textBrowser->append("视频源2导入错误！");
		break;
	}
	}
	// 设置控件不可用
	ui.capType_comboBox->setEnabled(false);
	ui.capType_comboBox_2->setEnabled(false);
	ui.start_Button->setEnabled(true);
	timer->start(33);// Start timing, signal out when timeout
}

void CvSystem::on_capType_comboBox_currentIndexChanged(){
	switch (ui.capType_comboBox->currentIndex())
	{
	case 0://simple video
	{
		capType1 = SIMPLE;
		break;
	}
	case 1://camera1
	{
		capType1 = CAMERA;
		break;
	}
	default:
		break;
	}
}

void CvSystem::on_capType_comboBox_2_currentIndexChanged(){
	switch (ui.capType_comboBox_2->currentIndex())
	{
	case 0://none
	{
		capType2 = NONE;
		break;
	}
	case 1://simple video
	{
		capType2 = SIMPLE;
		break;
	}
	case 2://camera2
	{
		capType2 = CAMERA;
		break;
	}
	default:
		break;
	}
}

// 图像提取按钮
void CvSystem::on_start_Button_clicked() {
	appendText("开始处理...");
	appendText("【开始】图像处理...");
	if (0 == featureType) {
		ui.matchType_Label->setText("ORB");
	}
	else if (1 == featureType) {
		ui.matchType_Label->setText("SURF");
	}
	else if (2 == featureType) {
		ui.matchType_Label->setText("SIFT");
	}
	else {
		ui.matchType_Label->setText("匹配算法");
	}
	// 放入第一个相机的图片
	if (!frame1.srcFrame.empty()) {
		cam1.addImg(frame1.srcFrame, frame1.outBinary(bin1.lowThreshold, bin1.highThreshold, bin1.dilatePara, bin1.erodePara, bin1.blurPara));
		ui.extract_progressBar->setValue(10);
		cam1fit->start();
	}
	// 放入第二个相机的图片
	if (!frame2.srcFrame.empty()) {
		if (capType2) {
			cam2.addImg(frame2.srcFrame, frame2.outBinary(bin2.lowThreshold, bin2.highThreshold, bin2.dilatePara, bin2.erodePara, bin2.blurPara));
			ui.extract_progressBar_2->setValue(10);
			cam2fit->start();
		}
	}
}

// 停止按钮
void CvSystem::on_stop_Button_clicked(){
	ui.textBrowser->append("视频源导入停止！");
	isStart = false;
	// 设置控件可用性
	ui.capType_comboBox->setEnabled(true);
	ui.capType_comboBox_2->setEnabled(true);
	ui.start_Button->setEnabled(false);
	// 时间器停止
	timer->stop();
	// 图像捕捉器释放
	capture1.release();
	capture2.release();
}

//********************************************************//
//******************* Video Function *********************//
//********************************************************//

// 显示图像
void CvSystem::displayImage(Mat &src, QLabel *label, double ratio,bool isGray){
	if (isGray){
		Mat tempImage;
		cvtColor(src, tempImage, CV_GRAY2RGB);//only RGB of Qt
		cv::resize(tempImage, tempImage, Size(), ratio, ratio);
		QImage srcQImage = QImage((uchar*)(tempImage.data), tempImage.cols, tempImage.rows, QImage::Format_RGB888);
		label->setPixmap(QPixmap::fromImage(srcQImage));
		label->resize(srcQImage.size());
		label->show();
	}else{
		Mat tempImage;
		cvtColor(src, tempImage, CV_BGR2RGB);//only RGB of Qt
		cv::resize(tempImage, tempImage, Size(), ratio, ratio);
		QImage srcQImage = QImage((uchar*)(tempImage.data), tempImage.cols, tempImage.rows, QImage::Format_RGB888);
		label->setPixmap(QPixmap::fromImage(srcQImage));
		label->resize(srcQImage.size());
		label->show();
	}
}

void CvSystem::outputFrame(){
	readFrame(capture1, frame1,ui.videoLabel,bin1);//input camera1
	if (capType2){
		readFrame(capture2, frame2, ui.videoLabel_2,bin2);//input camera2
	}
	if (isBinary){
		QString temp = "二值图像";
		ui.displayStatus_Label->setText(temp);
		ui.displayStatus_Label_2->setText(temp);
	}else{
		QString temp = "RGB图像";
		ui.displayStatus_Label->setText(temp);
		ui.displayStatus_Label_2->setText(temp);
	}
}

//read the current frame
void CvSystem::readFrame(VideoCapture &capture, FrameImg &frame, QLabel *label,const binPara &bin) {
	capture >> frame.srcFrame;
	if (frame.srcFrame.empty()){
		ui.textBrowser->append("导入视频源为空！");
	}else if (isBinary)	{
		Mat binImg = frame.outBinary(bin.lowThreshold,bin.highThreshold,bin.dilatePara,bin.erodePara,bin.blurPara);
		cv::resize(binImg, binImg, Size(imageWidth, imageHeight));
		displayImage(binImg, label, 0.5, isBinary);//display source image in the label
	}else{
		cv::resize(frame.srcFrame, frame.srcFrame, Size(imageWidth, imageHeight));
		displayImage(frame.srcFrame, label, 0.5,isBinary);//display source image in the label
	}
}

//********************************************************//
//***************** Detection Function *******************//
//********************************************************//

// 显示分割后的图像1
void CvSystem::showSplitImg1() {
	ui.extract_progressBar->setValue(100);
	if (!contour1_l.isEmpty()) {
		displayImage(contour1_l.outImg, ui.leftFrame_Label_1, 0.5);
		// 显示轮廓中心坐标
		QString temp;
		temp.sprintf("%.3f", contour1_l.cenx);
		ui.cenx_label_1->setText(temp);
		temp.sprintf("%.3f", contour1_l.ceny);
		ui.ceny_label_1->setText(temp);
		temp.sprintf("%.3f", contour1_l.angle);
		ui.angle_label_1->setText(temp);
	}
	if (!contour1_r.isEmpty()) {
		displayImage(contour1_r.outImg, ui.rightFrame_Label_1, 0.5);
	}
	ui.extract_progressBar->setValue(10);
	appendText("【完成】图像1左右分割");
}

// 显示分割后的图像2
void CvSystem::showSplitImg2() {
	ui.extract_progressBar_2->setValue(100);
	if (!contour2_l.isEmpty()) {
		displayImage(contour2_l.outImg, ui.leftFrame_Label_2, 0.5);
		// 显示轮廓中心坐标
		QString temp;
		temp.sprintf("%.3f", contour2_l.cenx);
		ui.cenx_label_2->setText(temp);
		temp.sprintf("%.3f", contour2_l.ceny);
		ui.ceny_label_2->setText(temp);
		temp.sprintf("%.3f", contour2_l.angle);
		ui.angle_label_2->setText(temp);
	}
	if (!contour2_r.isEmpty()) {
		displayImage(contour2_r.outImg, ui.rightFrame_Label_2, 0.5);
	}
	ui.extract_progressBar_2->setValue(10);
	appendText("【完成】图像2左右分割");
}

// 显示特征匹配后的图像1
void CvSystem::showMatchImg1() {
	ui.extract_progressBar->setValue(100);
	if (!match1.isEmpty()) {
		// imshow("KeyPoints of imageL", match1.outImg);
		displayImage(match1.outImg, ui.matchFrame_Label_1, 0.5);
		appendText("【完成】图像1特征匹配");
		QString temp;
		temp.sprintf("%d/%d", match1.goodNum,match1.feaNum);
		ui.feaNum_label_1->setText(temp);
		temp.sprintf("%.3f", match1.distance(camPara1));
		ui.distance_label_1->setText(temp);
		appendText("【完成】图像1视差测距");
	}
}

// 显示特征匹配后的图像2
void CvSystem::showMatchImg2() {
	ui.extract_progressBar_2->setValue(100);
	if (!match2.isEmpty()) {
		displayImage(match2.outImg, ui.matchFrame_Label_2, 0.5);
		appendText("【完成】图像2特征匹配");
		QString temp;
		temp.sprintf("%d/%d", match2.goodNum, match2.feaNum);
		ui.feaNum_label_2->setText(temp);
		temp.sprintf("%.3f", match2.distance(camPara2));
		ui.distance_label_2->setText(temp);
		appendText("【完成】图像2视差测距");
	}
}

void CvSystem::finishCamThread1() {
	cam1fit->quit();
}

void CvSystem::finishCamThread2() {
	cam2fit->quit();
}
