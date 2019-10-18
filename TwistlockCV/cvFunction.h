#pragma once

#include <iostream>
#include <vector>  
#include <algorithm>
#include <cmath>
#include <opencv2/core.hpp>  
#include <opencv2/highgui.hpp>  
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/flann.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace cv;
using namespace std;

class parallax
{
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
	int cenx, ceny, angle;
private:
	bool empty = true;
};

// 特征点检测
class FeatureMatch {
public:
	void fit(const ContourReco &left, const ContourReco &right);
	Mat leftImg;
	Mat rightImg;
	Mat outImg;
	double paraMean;
	bool isEmpty();
private:
	bool empty = true;
};