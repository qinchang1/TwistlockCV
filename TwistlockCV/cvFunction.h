#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>  
#include <algorithm>
#include <cmath>
#include <opencv2/core.hpp>  
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>  
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/flann.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <para.h>

using namespace cv;
using namespace dnn;
using namespace std;

class parallax{
public:
	double leftX;
	double rightX;
	double paraValue;
	parallax(double lx, double rx) {
		leftX = lx;
		rightX = rx;
		paraValue = leftX - rightX;
	}
};

class yoloClass {
public:
	string name;
	int left, top, right, bottom;
	string score;
	double s;
	string out() {
		string temp = name;
		string para = format(":(%d,%d)(%d,%d) ", left,top,right,bottom);
		temp = temp + para;
		temp = temp + score;
		return temp;
	}
	bool empty = true;
};

//video\camera stream
class FrameImg {
public:
	Mat srcFrame;
	Mat outGray();//output gray image
	Mat outBinary(const int& lowThreshold,const int& highThreshold,const int& dilatePara,const int& erodePara,const int& blurPara);//output binary image
};

// 摄像头提取的图像
class ImgClass {
public:
	void addImg(const Mat &src, const Mat &bin);
	bool isEmpty();
	Mat srcImg;
	Mat binImg;
private:
	bool empty = true;
};

// 左右分割输入（包含二值图像）
class SplitImg {
public:
	void fit(const Mat &src, const Mat &bin);
	bool isEmpty();
	Mat srcImg;
	Mat binImg;
	Mat left;
	Mat leftBin;
	Mat right;
	Mat rightBin;
private:
	bool empty = true;
};

// 轮廓识别
class ContourReco {
public:
	void fit(const Mat &src, const Mat &bin);
	bool isEmpty();
	Mat srcImg;
	Mat outImg;
	int x, y, w, h;
	double cenx, ceny, angle;
private:
	bool empty = true;
};

// 特征点检测
class FeatureMatch {
public:
	void fit(const ContourReco &left, const ContourReco &right, const yoloClass &lock_l, const yoloClass &lock_r);
	double distance(const CamPara &cam);
	double height(const double k, const double b, const double dis, const double v);
	Mat leftImg;
	Mat rightImg;
	Mat outImg;
	int goodNum, feaNum;
	double px; // 视差
	double u, v; // 目标在图像中的像素坐标
	double s; //目标检测置信度
	bool isEmpty();
private:
	bool empty = true;
};

// YOLO算法检测
class YoloDetect {
public:
	YoloDetect();
	vector<string> classes; // 存储类名
	Net net; // 网络
	Mat frame, blob;
	vector<yoloClass> classData;
	yoloClass twistlock_l;
	yoloClass twistlock_r;
	void fit(const Mat &src);
	vector<String> getOutputsNames(const Net& net); // Get the names of the output layers
	void postprocess(Mat& frame, const vector<Mat>& outs); // Remove the bounding boxes with low confidence using non-maxima suppression
	void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame); // Draw the predicted bounding box
	void clearData();
	bool isEmpty();
private:
	bool empty = true;
};