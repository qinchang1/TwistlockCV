#include "CvSystem.h"

CapType capType1 = SIMPLE;//camera1 input type
CapType capType2 = NONE;//camera2 input tpye
bool isBinary = 0;//default image is RGB
bool isStart = false; //是否已经开始

//****** Binary parameter *****//
extern binPara bin1;
extern binPara bin2;
//*****************************//

CvSystem::CvSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(outputFrame()));
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

void CvSystem::on_preSet_Action_triggered()
{
	preWin.show();//open pretreatment window
}

//********************************************************//
//****************** Button Function *********************//
//********************************************************//

void CvSystem::on_display_Button_clicked(){
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
	splitImg();
	appendText("【完成】图像处理");
}

// 停止按钮
void CvSystem::on_stop_Button_clicked(){
	ui.textBrowser->append("视频源导入停止！");
	isStart = false;
	// 设置控件可用
	ui.capType_comboBox->setEnabled(true);
	ui.capType_comboBox_2->setEnabled(true);
	timer->stop();
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

void CvSystem::splitImg() {
	if (!frame1.srcFrame.empty()) {
		// 图像左右分割并输入
		split1.fit(frame1.srcFrame,frame1.outBinary(bin1.lowThreshold, bin1.highThreshold, bin1.dilatePara, bin1.erodePara, bin1.blurPara)); 
		if (!split1.isEmpty()) {
			// 图像取轮廓，最小轮廓框选
			contour1_l.fit(split1.left, split1.leftBin);
			contour1_r.fit(split1.right, split1.rightBin);
			// 显示框选后的图像
			if (!contour1_l.isEmpty()) {
				displayImage(contour1_l.outImg, ui.leftFrame_Label, 0.5);
			}
			if (!contour1_r.isEmpty()) {
				displayImage(contour1_r.outImg, ui.rightFrame_Label, 0.5);
			}
		}
	}
	if (!frame2.srcFrame.empty()) {
		// 图像左右分割并输入
		split2.fit(frame2.srcFrame, frame2.outBinary(bin2.lowThreshold, bin2.highThreshold, bin2.dilatePara, bin2.erodePara, bin2.blurPara));
		if (!split2.isEmpty()) {
			// 图像取轮廓，最小轮廓框选
			contour2_l.fit(split2.left, split2.leftBin);
			contour2_r.fit(split2.right, split2.rightBin);
			// 显示框选后的图像
			if (!contour2_l.isEmpty()) {
				displayImage(contour2_l.outImg, ui.leftFrame_Label_2, 0.5);
			}
			if (!contour2_r.isEmpty()) {
				displayImage(contour2_r.outImg, ui.rightFrame_Label_2, 0.5);
			}
		}
	}
}
