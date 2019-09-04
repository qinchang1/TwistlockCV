#include "cvThread.h"

ImgClass cam1;
ImgClass cam2;
SplitImg split1;
SplitImg split2;
ContourReco contour1_l;
ContourReco contour1_r;
ContourReco contour2_l;
ContourReco contour2_r;

Cam1Thread::Cam1Thread(QObject *parent){

}

void Cam1Thread::run(){
	qDebug() << "myThread run() start to execute";
	qDebug() << "     current thread ID:" << QThread::currentThreadId() << '\n';
	//循环一百万次
	int count = 0;
	for (int i = 0; i != 1000000; ++i)
	{
		++count;
	}
	//发送结束信号
	emit myThreadSignal(count);
	exec();
}

void Cam1Thread::myThreadSlot(const int val){
	qDebug() << "myThreadSlot() start to execute";
	qDebug() << "     current thread ID:" << QThread::currentThreadId() << '\n';
	//循环一百万次
	int count = 888;
	for (int i = 0; i != 1000000; ++i)
	{
		++count;
	}
}