#include "cvThread.h"

ImgClass cam1;
ImgClass cam2;
YoloDetect yolo1_l;
bool isYolo1 = true;
// YoloDetect yolo1_r;
YoloDetect yolo2_l;
bool isYolo2 = true;
// YoloDetect yolo2_r;
SplitImg split1;
SplitImg split2;
ContourReco contour1_l;
ContourReco contour1_r;
ContourReco contour2_l;
ContourReco contour2_r;
FeatureMatch match1;
FeatureMatch match2;

// ******************* camera1 左右图像分割 ********************** //

Cam1Thread::Cam1Thread(QObject *parent){}

void Cam1Thread::run(){
	if (!cam1.isEmpty()) {
		split1.fit(cam1.srcImg, cam1.binImg); // 图像左右分割并输入
		if (!split1.isEmpty()) {
			// YOLO检测
			if (isYolo1) {
				yolo1_l.fit(split1.srcImg);
				emit finishYolo(); // 发送yolo结束信号
			}
			// 图像取轮廓，最小轮廓框选
			contour1_l.fit(split1.left, split1.leftBin);
			contour1_r.fit(split1.right, split1.rightBin);
			emit finishSplit(); // 发送分割结束信号
			if ((!contour1_l.isEmpty()) && (!contour1_r.isEmpty())) {
				match1.fit(contour1_l, contour1_r, yolo1_l.twistlock_l, yolo1_l.twistlock_r);// 特征点匹配
				emit finishMatch(); // 发送匹配结束信号
			}
		}
	}
	emit finishAll();
	exec();
}

// ******************* camera2 左右图像分割 ********************** //

Cam2Thread::Cam2Thread(QObject *parent) {}

void Cam2Thread::run() {
	if (!cam2.isEmpty()) {
		split2.fit(cam2.srcImg, cam2.binImg); // 图像左右分割并输入
		if (!split2.isEmpty()) {
			// YOLO检测
			if (isYolo2) {
				yolo2_l.fit(split2.srcImg);
				emit finishYolo(); // 发送yolo结束信号
			}
			// 图像取轮廓，最小轮廓框选
			contour2_l.fit(split2.left, split2.leftBin);
			contour2_r.fit(split2.right, split2.rightBin);
			emit finishSplit(); // 发送分割结束信号
			if ((!contour2_l.isEmpty()) && (!contour2_r.isEmpty())) {
				match2.fit(contour2_l, contour2_r, yolo2_l.twistlock_l, yolo2_l.twistlock_r); // 特征点匹配
				emit finishMatch(); // 发送匹配结束信号
			}
		}
	}
	emit finishAll();
	exec();
}