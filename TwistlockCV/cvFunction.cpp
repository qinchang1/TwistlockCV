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
	dilate(tempGray, tempGray, dilateElement);//����
	//imshow("Dilate", tempGray);
	erode(tempGray, tempGray, erodeElement);//��ʴ
	//imshow("Erode", tempGray);
	blur(tempGray, tempGray, Size(blurPara, blurPara));//ģ����  
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

void FeatureMatch::fit(const ContourReco &left, const ContourReco &right, const yoloClass &lock_l, const yoloClass &lock_r) {
	leftImg = left.srcImg.clone();
	rightImg = right.srcImg.clone();
	// ��˹ģ��
	GaussianBlur(leftImg, leftImg, Size(3, 3), 0.5);
	GaussianBlur(rightImg, rightImg, Size(3, 3), 0.5);

	// ƥ��������
	vector<DMatch>goodMatches; 
	vector<KeyPoint> keyPoint1, keyPoint2;

	//**************************** ƥ���㷨 *********************************//
	bool flagMatch = false;
	switch (featureType){
	case 0: // ORB�㷨
	{
		Ptr<ORB> orb = ORB::create(featureCreatePara);
		orb->setFastThreshold(0);
		// ����������
		Mat descriptors_1, descriptors_2;
		orb->detectAndCompute(leftImg, Mat(), keyPoint1, descriptors_1);
		orb->detectAndCompute(rightImg, Mat(), keyPoint2, descriptors_2);
		// ���ƹؼ���
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		// ������ƥ��
		BFMatcher matcher;
		vector<DMatch> matchesAll;
		// GMS�㷨: Grid-based Motion Statistics for Fast, Ultra-robust Feature Correspondence CVPR2017
		matcher.match(descriptors_1, descriptors_2, matchesAll);

		//ɸѡYOLO����
		if (!lock_l.empty) {
			for (int i = 0; i < matchesAll.size(); i++)
			{
				int x = keyPoint1[matchesAll[i].queryIdx].pt.x;
				int y = keyPoint1[matchesAll[i].queryIdx].pt.y;
				if (x<lock_l.left || x>lock_l.right || y<lock_l.top || y>lock_l.bottom) {
					matchesAll.erase(matchesAll.begin() + i);
					i--;
				}
			}
		}

		xfeatures2d::matchGMS(leftImg.size(), rightImg.size(), keyPoint1, keyPoint2, matchesAll, goodMatches);
		// �ϲ�����ͼ��
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	case 1: // SURF�㷨
	{
		// �ҳ�������
		Ptr<Feature2D>f2d = xfeatures2d::SURF::create(featureCreatePara);
		f2d->detect(leftImg, keyPoint1);
		f2d->detect(rightImg, keyPoint2);
		// ���ƹؼ���
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		/*drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1));
		drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1));*/
		// ���������
		Mat descriptors_1, descriptors_2;
		f2d->compute(leftImg, keyPoint1, descriptors_1);
		f2d->compute(rightImg, keyPoint2, descriptors_2);
		// ������ƥ��
		BFMatcher matcher;
		vector<DMatch> matches;
		matcher.match(descriptors_1, descriptors_2, matches);
		// ����������������ƥ�����
		double maxdist = 0; double mindist = 100;
		for (int i = 0; i < descriptors_1.rows; i++){
			double dist = matches[i].distance;
			if (dist < mindist)mindist = dist;
			if (dist > maxdist)maxdist = dist;
		}
		// ��ѡ�õ�ƥ���
		for (int i = 0; i < descriptors_1.rows; i++){
			if (matches[i].distance<2 * mindist){
				goodMatches.push_back(matches[i]);
			}
		}
		// �ϲ�����ͼ��
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	case 2: // SIFT�㷨
	{
		// �ҳ�������
		Ptr<Feature2D>f2d = xfeatures2d::SIFT::create(featureCreatePara);
		f2d->detect(leftImg, keyPoint1);
		f2d->detect(rightImg, keyPoint2);
		// ���ƹؼ���
		//drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		//drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		/*drawKeypoints(leftImg, keyPoint1, leftImg, Scalar::all(-1));
		drawKeypoints(rightImg, keyPoint2, rightImg, Scalar::all(-1));*/
		// ���������
		Mat descriptors_1, descriptors_2;
		f2d->compute(leftImg, keyPoint1, descriptors_1);
		f2d->compute(rightImg, keyPoint2, descriptors_2);
		// ������ƥ��
		BFMatcher matcher;
		vector<DMatch> matches;
		matcher.match(descriptors_1, descriptors_2, matches);
		// ����������������ƥ�����
		double maxdist = 0; double mindist = 100;
		for (int i = 0; i < descriptors_1.rows; i++) {
			double dist = matches[i].distance;
			if (dist < mindist)mindist = dist;
			if (dist > maxdist)maxdist = dist;
		}
		// ��ѡ�õ�ƥ���
		for (int i = 0; i < descriptors_1.rows; i++) {
			if (matches[i].distance<2 * mindist) {
				goodMatches.push_back(matches[i]);
			}
		}
		// �ϲ�����ͼ��
		drawMatches(leftImg, keyPoint1, rightImg, keyPoint2, goodMatches, outImg, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		flagMatch = true;
		break;
	}
	default:
		break;
	}

	// ***************************** �����Ӳ� ************************************ //
	if ((!lock_l.empty)&&(!lock_r.empty)) {
		double x1 = (lock_l.left + lock_l.right) / 2;
		double x2 = (lock_r.left + lock_r.right - leftImg.size().width * 2) / 2;
		px = x1 - x2;
		double y1 = (lock_l.bottom + lock_l.top) / 2;
		cout << "ʹ��yolo�����Ӳ" << px << endl;
		u = x1 - leftImg.size().width / 2;
		v = leftImg.size().height / 2 - y1;
		s = lock_l.s;
		cout << "ʹ��yolo����λ�ã�" << u << "  " << v << endl;
		empty = false;
	}
	else if(flagMatch&&(goodMatches.size()>0)){
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
		cout << "ʹ������������Ӳ" << px << endl;
		u = v = 0;
		s = 1;
		empty = false;
	}
	else {
		cout << "�Ӳ�����ˣ�" << endl;
		u = v = 0;
		s = 1;
		px = 100;
		empty = false;
	}
}

// ���ؼ���ľ���ֵ����Ҫ��������ͷ������
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

double FeatureMatch::height(const double k, const double b, const double dis, const double v) {
	if (isEmpty()) {
		return -1;
	}
	else {
		double h;
		h = k*dis*v + b;
		return h;
	}
}

bool FeatureMatch::isEmpty() {
	return empty;
}

//*********************************************************//
//******************* class YoloDetect ********************//

// ���캯��
YoloDetect::YoloDetect()
{
	// ��������
	ifstream ifs(classesFile.c_str());
	string line;
	while (getline(ifs, line)) classes.push_back(line);

	// ��������
	net = readNetFromDarknet(modelConfiguration, modelWeights);
	net.setPreferableBackend(DNN_BACKEND_OPENCV);
	net.setPreferableTarget(DNN_TARGET_CPU);
	cout << "yolo completed!" << endl;
}

// ������
void YoloDetect::fit(const Mat &src) 
{
	clearData();

	frame = src.clone();

	// Create a 4D blob from a frame.
	blobFromImage(frame, blob, 1 / 255.0, cvSize(inpWidth, inpHeight), Scalar(0, 0, 0), true, false);

	//Sets the input to the network
	net.setInput(blob);

	// Runs the forward pass to get output of the output layers
	vector<Mat> outs;
	net.forward(outs, getOutputsNames(net));

	// Remove the bounding boxes with low confidence
	postprocess(frame, outs);

	// Put efficiency information. The function getPerfProfile returns the overall time for inference(t) and the timings for each of the layers(in layersTimes)
	vector<double> layersTimes;
	double freq = getTickFrequency() / 1000;
	double t = net.getPerfProfile(layersTimes) / freq;
	string label = format("Inference time for a frame : %.2f ms", t);
	putText(frame, label, Point(0, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));

	/*
	static const string kWinName = "Deep learning object detection in OpenCV";
	namedWindow(kWinName, WINDOW_AUTOSIZE);
	imshow(kWinName, frame);
	*/

	empty = false;
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

// Remove the bounding boxes with low confidence using non-maxima suppression
void YoloDetect::postprocess(Mat& frame, const vector<Mat>& outs)
{
	vector<int> classIds;
	vector<float> confidences;
	vector<Rect> boxes;

	for (size_t i = 0; i < outs.size(); ++i)
	{
		// Scan through all the bounding boxes output from the network and keep only the
		// ones with high confidence scores. Assign the box's class label as the class
		// with the highest score for the box.
		float* data = (float*)outs[i].data;
		for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
		{
			Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
			Point classIdPoint;
			double confidence;
			// Get the value and location of the maximum score
			minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
			if (confidence > confThreshold)
			{
				int centerX = (int)(data[0] * frame.cols);
				int centerY = (int)(data[1] * frame.rows);
				int width = (int)(data[2] * frame.cols);
				int height = (int)(data[3] * frame.rows);
				int left = centerX - width / 2;
				int top = centerY - height / 2;

				classIds.push_back(classIdPoint.x);
				confidences.push_back((float)confidence);
				boxes.push_back(Rect(left, top, width, height));
			}
		}
	}

	// Perform non maximum suppression to eliminate redundant overlapping boxes with
	// lower confidences
	vector<int> indices;
	NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int idx = indices[i];
		Rect box = boxes[idx];
		drawPred(classIds[idx], confidences[idx], box.x, box.y,
			box.x + box.width, box.y + box.height, frame);
	}
}

// Draw the predicted bounding box
void YoloDetect::drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame)
{
	//Draw a rectangle displaying the bounding box
	switch (classId)
	{
	case 0: {
		rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 0, 0), 3);
		break;
	}
	case 1: {
		rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 255, 0), 3);
		break;
	}
	case 2: {
		rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 0, 255), 3);
		break;
	}
	default:{
		rectangle(frame, Point(left, top), Point(right, bottom), Scalar(208, 244, 64), 3);
		break;
	}
	}

	//Get the label for the class name and its confidence
	string label = format("%.2f", conf);
	// ��������б�
	yoloClass temp;
	temp.name = classes[classId];
	temp.left = left;
	temp.top = top;
	temp.right = right;
	temp.bottom = bottom;
	temp.s = conf;
	temp.score = label;
	classData.push_back(temp);
	// �ж��ǲ���Ť����������Ϣ
	if (temp.name == "twistlock") {
		if (twistlock_l.empty) {
			twistlock_l = temp;
			twistlock_l.empty = false;
		}
		else if (twistlock_l.left > temp.left) {
			twistlock_r = twistlock_l;
			twistlock_r.empty = false;
			twistlock_l = temp;
			twistlock_l.empty = false;
		}
		else {
			twistlock_r = temp;
			twistlock_r.empty = false;
		}
	}
	if (!classes.empty())
	{
		CV_Assert(classId < (int)classes.size());
		label = classes[classId] + ":" + label;
	}

	//Display the label at the top of the bounding box
	int baseLine;
	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
	top = max(top, labelSize.height);
	rectangle(frame, Point(left, top - round(1.5*labelSize.height)), Point(left + round(1.5*labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 2);
}

void YoloDetect::clearData() {
	classData.clear();
}

bool YoloDetect::isEmpty() {
	return empty;
}