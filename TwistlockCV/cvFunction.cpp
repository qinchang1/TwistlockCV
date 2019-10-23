#include "cvFunction.h"

extern int featureType;
extern int featureCreatePara;
extern double errorRange;
extern float confThreshold;
extern float nmsThreshold;
extern int inpWidth;
extern int inpHeight;
string classesFile = "yolo3/coco.names";          //Names of classes
String modelConfiguration = "yolo3/yolov3.cfg";   //Configuration file
String modelWeights = "yolo3/yolov3.weights";     //Weight file

bool ascendSort(vector<Point> a, vector<Point> b) {
	return a.size() > b.size();
}

bool ascendPara(parallax a, parallax b)
{
	return a.paraValue < b.paraValue;
}

//**************************************************//
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

//*******************************************************//
//******************* class ImgClass ********************//

void ImgClass::addImg(const Mat &src, const Mat &bin) {
	srcImg = src.clone();
	binImg = bin.clone();
	empty = false;
}

bool ImgClass::isEmpty() {
	return empty;
}

//*******************************************************//
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

//**********************************************************//
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

//***********************************************************//
//******************* class FeatureMatch ********************//

void FeatureMatch::fit(const ContourReco &left, const ContourReco &right) {
	leftImg = left.srcImg.clone();
	rightImg = right.srcImg.clone();
	// 高斯模糊
	GaussianBlur(leftImg, leftImg, Size(3, 3), 0.5);
	GaussianBlur(rightImg, rightImg, Size(3, 3), 0.5);

	// 匹配特征点
	vector<DMatch>goodMatches; 
	vector<KeyPoint> keyPoint1, keyPoint2;

	//**************************** 匹配算法 *********************************//
	bool flagMatch = false;
	switch (featureType){
	case 0: // ORB算法
	{
		Ptr<ORB> orb = ORB::create(featureCreatePara);
		orb->setFastThreshold(0);
		// 计算特征点
		Mat descriptors_1, descriptors_2;
		orb->detectAndCompute(leftImg, Mat(), keyPoint1, descriptors_1);
		orb->detectAndCompute(rightImg, Mat(), keyPoint2, descriptors_2);
		// 绘制关键点
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		// 特征点匹配
		BFMatcher matcher;
		vector<DMatch> matchesAll;
		// GMS算法: Grid-based Motion Statistics for Fast, Ultra-robust Feature Correspondence CVPR2017
		matcher.match(descriptors_1, descriptors_2, matchesAll);
		xfeatures2d::matchGMS(leftImg.size(), rightImg.size(), keyPoint1, keyPoint2, matchesAll, goodMatches);
		// 合并左右图像
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	case 1: // SURF算法
	{
		// 找出特征点
		Ptr<Feature2D>f2d = xfeatures2d::SURF::create(featureCreatePara);
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
		for (int i = 0; i < descriptors_1.rows; i++){
			if (matches[i].distance<2 * mindist){
				goodMatches.push_back(matches[i]);
			}
		}
		// 合并左右图像
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	case 2: // SIFT算法
	{
		// 找出特征点
		Ptr<Feature2D>f2d = xfeatures2d::SIFT::create(featureCreatePara);
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
		for (int i = 0; i < descriptors_1.rows; i++) {
			double dist = matches[i].distance;
			if (dist < mindist)mindist = dist;
			if (dist > maxdist)maxdist = dist;
		}
		// 挑选好的匹配点
		for (int i = 0; i < descriptors_1.rows; i++) {
			if (matches[i].distance<2 * mindist) {
				goodMatches.push_back(matches[i]);
			}
		}
		// 合并左右图像
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	default:
		break;
	}

	// ***************************** 计算视差 ************************************ //
	if(flagMatch){
		vector<parallax>para;
		feaNum = goodMatches.size();
		for (int i = 0; i < goodMatches.size(); i++){
			parallax temp(keyPoint1[goodMatches[i].queryIdx].pt.x, keyPoint2[goodMatches[i].trainIdx].pt.x);
			para.push_back(temp);
			//cout << "No." << i + 1 << ":\t l_X ";
			//cout << para[i].leftX << "\t r_X " << para[i].rightX;
			//cout << "\t parallax " << para[i].paraValue << endl;
		}
		sort(para.begin(), para.end(), ascendPara);
		int idxMedian = int(para.size() / 2);
		double paraMedian = para[idxMedian].paraValue;
		vector<parallax>::iterator it;
		for (it = para.begin(); it != para.end(); ){
			if (it->paraValue<((1 - errorRange)*paraMedian) || it->paraValue>((1 + errorRange)*paraMedian))
				it = para.erase(it);
			else
				it++;
		}
		// cout << "Final data..." << endl;
		double paraSum = 0;
		goodNum = para.size();
		for (int i = 0; i < para.size(); i++){
			paraSum = paraSum + para[i].paraValue;
			// cout << "No." << i << "\t" << para[i].paraValue << endl;
		}
		px = paraSum / para.size();
		// cout << "Parallax is " << paraMean << " pixel." << endl;
		empty = false;
	}
}

// 返回计算的距离值（需要输入摄像头参数）
double FeatureMatch::distance(const CamPara &cam) {
	if (isEmpty()) {
		return -1;
	}
	else {
		double dis;
		dis = cam.para0 + px*cam.para1 + px*px*cam.para2 + px*px*px*cam.para3;
		return dis;
	}
}

bool FeatureMatch::isEmpty() {
	return empty;
}

//*********************************************************//
//******************* class YoloDetect ********************//

// 构造函数
YoloDetect::YoloDetect(){
	// 载入类名
	ifstream ifs(classesFile.c_str());
	string line;
	while (getline(ifs, line)) classes.push_back(line);
	// 载入网络
	net = readNetFromDarknet(modelConfiguration, modelWeights);
	net.setPreferableBackend(DNN_BACKEND_OPENCV);
	net.setPreferableTarget(DNN_TARGET_CPU);
	cout << "yolo completed!" << endl;
}

// 处理函数
void YoloDetect::fit(const Mat &src) {
	frame = src.clone();
	// Create a 4D blob from a frame.
	blobFromImage(frame, blob, 1 / 255.0, cvSize(inpWidth, inpHeight), Scalar(0, 0, 0), true, false);
	//Sets the input to the network
	net.setInput(blob);
	// Runs the forward pass to get output of the output layers
	vector<Mat> outs;
	net.forward(outs, getOutputsNames(net));
}

// Get the names of the output layers
vector<String> YoloDetect::getOutputsNames(const Net& net)
{
	static vector<String> names;
	if (names.empty())
	{
		//Get the indices of the output layers, i.e. the layers with unconnected outputs
		vector<int> outLayers = net.getUnconnectedOutLayers();
		//get the names of all the layers in the network
		vector<String> layersNames = net.getLayerNames();
		// Get the names of the output layers in names
		names.resize(outLayers.size());
		for (size_t i = 0; i < outLayers.size(); ++i)
			names[i] = layersNames[outLayers[i] - 1];
	}
	return names;
}

bool YoloDetect::isEmpty() {
	return empty;
}