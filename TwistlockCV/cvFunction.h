#pragma once

#include <vector>  
#include <algorithm>
#include <cmath>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;

//video\camera stream
class FrameImg {
public:
	Mat srcFrame;
	Mat outGray();//output gray image
	Mat outBinary(const int& lowThreshold,const int& highThreshold,const int& dilatePara,const int& erodePara,const int& blurPara);//output binary image
};

// ×óÓÒ·Ö¸î
class SplitImg {
public:
	void fit(const Mat &src);
	bool isEmpty();
	Mat left;
	Mat right;
private:
	bool empty = true;
};

// ÂÖÀªÊ¶±ð
class ContourReco {
public:
	void fit(const Mat &src);
	bool isEmpty();
private:
	bool empty = true;
};