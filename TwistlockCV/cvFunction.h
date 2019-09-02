#pragma once

#include <vector>  
#include <algorithm>
#include <cmath>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;
using namespace std;

//video\camera stream
class FrameImg {
public:
	Mat srcFrame;
	Mat outGray();//output gray image
	Mat outBinary(const int& lowThreshold,const int& highThreshold,const int& dilatePara,const int& erodePara,const int& blurPara);//output binary image
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
	Mat outImg;
	int x, y, w, h;
	int cenx, ceny, angle;
private:
	bool empty = true;
};