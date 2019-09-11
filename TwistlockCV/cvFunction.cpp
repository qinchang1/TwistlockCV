#include "cvFunction.h"

int featureType = 0;

bool ascendSort(vector<Point> a, vector<Point> b) {
	return a.size() > b.size();
}

//**************** Class FrameImg ******************//

Mat FrameImg::outGray(){
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
	dilate(tempGray, tempGray, dilateElement);//膨胀
	//imshow("Dilate", tempGray);
	erode(tempGray, tempGray, erodeElement);//腐蚀
	//imshow("Erode", tempGray);
	blur(tempGray, tempGray, Size(blurPara, blurPara));//模糊化  
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
	srcImg = src.clone();
	outImg = src.clone();
	Mat tempBin = bin.clone();
	vector< vector< Point> > contours; //save all contours data
	vector<Vec4i> hierarchy;
	findContours(tempBin, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE); //find contours
	sort(contours.begin(), contours.end(), ascendSort); //ascending sort
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

//******************* class FeatureMatch ********************//

void FeatureMatch::fit(const ContourReco &left, const ContourReco &right) {
	leftImg = left.srcImg.clone();
	rightImg = right.srcImg.clone();
	// 高斯模糊
	GaussianBlur(leftImg, leftImg, Size(3, 3), 0.5);
	GaussianBlur(rightImg, rightImg, Size(3, 3), 0.5);
	switch (featureType){
	case 0: // ORB算法
	{
		Ptr<ORB> orb = ORB::create(1000);
		orb->setFastThreshold(0);
		// 计算特征点
		vector<KeyPoint> keyPoint1, keyPoint2;
		Mat descriptors_1, descriptors_2;
		orb->detectAndCompute(leftImg, Mat(), keyPoint1, descriptors_1);
		orb->detectAndCompute(rightImg, Mat(), keyPoint2, descriptors_2);
		// 绘制关键点
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		// 特征点匹配
		BFMatcher matcher;
		vector<DMatch> matchesAll, matchesGMS;
		// GMS算法: Grid-based Motion Statistics for Fast, Ultra-robust Feature Correspondence CVPR2017
		matcher.match(descriptors_1, descriptors_2, matchesAll);
		xfeatures2d::matchGMS(leftImg.size(), rightImg.size(), keyPoint1, keyPoint2, matchesAll, matchesGMS);
		// 合并左右图像
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, matchesGMS, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		empty = false;
		break;
	}
	case 1: // SURF算法
	{
		// 找出特征点
		Ptr<Feature2D>f2d = xfeatures2d::SURF::create();
		vector<KeyPoint> keyPoint1, keyPoint2;
		f2d->detect(leftImg, keyPoint1);
		f2d->detect(rightImg, keyPoint2);
		// 绘制关键点
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		/*drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1));
		drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1));*/
		// 特征点计算
		Mat descriptors_1, descriptors_2;
		f2d->compute(leftImg, keyPoint1, descriptors_1);
		f2d->compute(rightImg, keyPoint2, descriptors_2);
		// 特征点匹配
		BFMatcher matcher;
		vector<DMatch> matches;
		matcher.match(descriptors_1, descriptors_2, matches);
		// 计算特征点最长和最短匹配距离
		double maxdist = 0; double mindist = 100;
		for (int i = 0; i < descriptors_1.rows; i++){
			double dist = matches[i].distance;
			if (dist < mindist)mindist = dist;
			if (dist > maxdist)maxdist = dist;
		}
		// 挑选好的匹配点
		vector<DMatch>goodMatches;
		for (int i = 0; i < descriptors_1.rows; i++){
			if (matches[i].distance<2 * mindist){
				goodMatches.push_back(matches[i]);
			}
		}
		// 合并左右图像
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		empty = false;
		break;
	}
	case 2: // SIFT算法
	{

		break;
	}
	default:
		break;
	}
}

bool FeatureMatch::isEmpty() {
	return empty;
}