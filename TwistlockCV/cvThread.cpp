#include "cvThread.h"

ImgClass cam1;
ImgClass cam2;
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
		// 图像左右分割并输入
		split1.fit(cam1.srcImg, cam1.binImg);
		if (!split1.isEmpty()) {
			// 图像取轮廓，最小轮廓框选
			contour1_l.fit(split1.left, split1.leftBin);
			contour1_r.fit(split1.right, split1.rightBin);
		}
	}
	//发送结束信号
	emit finishSlot();
	exec();
}

// ******************* camera2 左右图像分割 ********************** //

Cam2Thread::Cam2Thread(QObject *parent) {}

void Cam2Thread::run() {
	if (!cam2.isEmpty()) {
		// 图像左右分割并输入
		split2.fit(cam2.srcImg, cam2.binImg);
		if (!split2.isEmpty()) {
			// 图像取轮廓，最小轮廓框选
			contour2_l.fit(split2.left, split2.leftBin);
			contour2_r.fit(split2.right, split2.rightBin);
		}
	}
	//发送结束信号
	emit finishSlot();
	exec();
}

// ******************* camera1 左右特征点匹配 ********************** //

Cam1Thread_FM::Cam1Thread_FM(QObject *parent) {}

void Cam1Thread_FM::run() {
	if (!split1.isEmpty()) {
		// 特征点匹配
		match1.fit(contour1_l, contour1_r);
	}
	//发送结束信号
	emit finishSlot();
	exec();
}