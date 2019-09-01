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

class SplitImg {
public:
	SplitImg(Mat src);
	Mat left;
	Mat right;
};