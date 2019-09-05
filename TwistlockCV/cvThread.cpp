#include "cvThread.h"

ImgClass cam1;
ImgClass cam2;
SplitImg split1;
SplitImg split2;
ContourReco contour1_l;
ContourReco contour1_r;
ContourReco contour2_l;
ContourReco contour2_r;

// ******************* camera1 ********************** //

Cam1Thread::Cam1Thread(QObject *parent){}

void Cam1Thread::run(){
	if (!cam1.isEmpty()) {
		// ͼ�����ҷָ����
		split1.fit(cam1.srcImg, cam1.binImg);
		if (!split1.isEmpty()) {
			// ͼ��ȡ��������С������ѡ
			contour1_l.fit(split1.left, split1.leftBin);
			contour1_r.fit(split1.right, split1.rightBin);
		}
	}
	//���ͽ����ź�
	emit finishSlot();
	exec();
}

// ******************* camera2 ********************** //

Cam2Thread::Cam2Thread(QObject *parent) {}

void Cam2Thread::run() {
	if (!cam2.isEmpty()) {
		// ͼ�����ҷָ����
		split2.fit(cam2.srcImg, cam2.binImg);
		if (!split2.isEmpty()) {
			// ͼ��ȡ��������С������ѡ
			contour2_l.fit(split2.left, split2.leftBin);
			contour2_r.fit(split2.right, split2.rightBin);
		}
	}
	// qDebug() << "end2" << "\n";
	//���ͽ����ź�
	emit finishSlot();
	exec();
}