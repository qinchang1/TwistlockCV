#include "cvFunction.h"

bool ascendSort(vector<Point> a, vector<Point> b) {
	return a.size() > b.size();
}

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

//******************* class ImgClass ********************//
void ImgClass::addImg(const Mat &src, const Mat &bin) {
	srcImg = src.clone();
	binImg = bin.clone();
	empty = false;
}

bool ImgClass::isEmpty() {
	return empty;
}

//******************* class SplitImg ********************//
void SplitImg::fit(const Mat &src, const Mat &bin) {
	srcImg = src.clone();
	binImg = bin.clone();
	left = src(Rect(0, 0, src.size().width / 2, src.size().height));
	right = src(Rect(src.size().width / 2, 0, src.size().width / 2, src.size().height));
	leftBin = bin(Rect(0, 0, bin.size().width / 2, bin.size().height));
	rightBin = bin(Rect(bin.size().width / 2, 0, bin.size().width / 2, bin.size().height));
	empty = false;
}

bool SplitImg::isEmpty() {
	return empty;
}

//******************* class ContourReco ********************//
void ContourReco::fit(const Mat &src, const Mat &bin) {
	outImg = src.clone();
	Mat tempBin = bin.clone();
	vector< vector< Point> > contours;//save all contours data
	vector<Vec4i> hierarchy;
	findContours(tempBin, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);//find contours
	sort(contours.begin(), contours.end(), ascendSort);//ascending sort
	vector< vector<Point> >::iterator itc = contours.begin(); //iterator of contour vector
	int i = 0;
	while (itc != contours.end()){
		//ignore the small object
		if (itc->size() > 150){
			if (i>0){
				Rect rect = boundingRect(*itc);//get the rectangle bounding
				x = rect.x;
				y = rect.y;
				w = rect.width;
				h = rect.height;
				rectangle(outImg, rect, { 0, 0, 255 }, 2, 8);//draw the rectangle
				RotatedRect resultRect;
				resultRect = minAreaRect(*itc);//get the min area rectangle   
				Point2f pt[4];
				resultRect.points(pt);//get the coordinate of vertex
				//draw the min area rectangle
				line(outImg, pt[0], pt[1], Scalar(255, 0, 0), 2, 8);
				line(outImg, pt[1], pt[2], Scalar(255, 0, 0), 2, 8);
				line(outImg, pt[2], pt[3], Scalar(255, 0, 0), 2, 8);
				line(outImg, pt[3], pt[0], Scalar(255, 0, 0), 2, 8);
				cenx = resultRect.center.x;
				ceny = resultRect.center.y;
				angle = resultRect.angle;
			}
			i++;
		}
		++itc;
	}
	empty = false;
}

bool ContourReco::isEmpty() {
	return empty;
}

//******************* class FeaturePoint ********************//



bool FeaturePoint::isEmpty() {
	return empty;
}