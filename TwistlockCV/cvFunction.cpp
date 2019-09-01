#include "cvFunction.h"

//**************** Class FrameImg ******************//

Mat FrameImg::outGray()
{
	Mat grayFrame;
	cvtColor(srcFrame, grayFrame, CV_BGR2GRAY);//convert to grayscale
	return grayFrame;
}

Mat FrameImg::outBinary(const int& lowThreshold, const int& highThreshold, const int& dilatePara, const int& erodePara, const int& blurPara)
{
	Mat tempGray, tempBinary;
	cvtColor(srcFrame, tempGray, CV_BGR2GRAY);//convert to grayscale

	Mat dstTempImage1, dstTempImage2;
	Mat dilateElement = getStructuringElement(0, Size(2 * dilatePara + 1, 2 * dilatePara + 1), Point(dilatePara, dilatePara));
	Mat erodeElement = getStructuringElement(0, Size(2 * erodePara + 1, 2 * erodePara + 1), Point(erodePara, erodePara));

	//convert to binaryImage
	dilate(tempGray, tempGray, dilateElement);//ÅòÕÍ
	//imshow("Dilate", tempGray);
	erode(tempGray, tempGray, erodeElement);//¸¯Ê´
	//imshow("Erode", tempGray);
	blur(tempGray, tempGray, Size(blurPara, blurPara));//Ä£ºý»¯  
	//imshow("Blur", tempGray);
	threshold(tempGray, dstTempImage1, lowThreshold, 254, THRESH_BINARY);
	threshold(tempGray, dstTempImage2, highThreshold, 254, THRESH_BINARY_INV);
	bitwise_xor(dstTempImage1, dstTempImage2, tempBinary);
	//imshow("Binary", tempBinary);
	return tempBinary;
}

//******************* class SplitImg ********************//
SplitImg::SplitImg(Mat src) {
	left = src(Rect(0, 0, src.size().width / 2, src.size().height));
	right = src(Rect(src.size().width / 2, 0, src.size().width / 2, src.size().height));
}