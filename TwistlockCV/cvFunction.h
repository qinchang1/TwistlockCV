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

// ����ͷ��ȡ��ͼ��
class ImgClass {
public:
	void addImg(const Mat &src, const Mat &bin);
	bool isEmpty();
	Mat srcImg;
	Mat binImg;
private:
	bool empty = true;
};

// ���ҷָ����루������ֵͼ��
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

// ����ʶ��
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

// ��������
class FeatureMatch {
public:
	void fit(const ContourReco &left, const ContourReco &right);
	Mat leftImg;
	Mat rightImg;
	bool isEmpty();
private:
	bool empty = true;
};