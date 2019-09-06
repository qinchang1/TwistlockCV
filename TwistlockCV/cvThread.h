#pragma once
#include <QThread>
#include "cvFunction.h"

// ******************* 左右图像分割 ********************** //

class Cam1Thread : public QThread
{
	Q_OBJECT
public:
	Cam1Thread(QObject* parent = nullptr);
//自定义发送的信号
signals:
	void finishSlot();
protected:
	void run() override;
};

class Cam2Thread : public QThread
{
	Q_OBJECT
public:
	Cam2Thread(QObject* parent = nullptr);
	//自定义发送的信号
signals:
	void finishSlot();
protected:
	void run() override;
};

// ******************* 左右图像特征点匹配 ********************** //

class Cam1Thread_FM : public QThread
{
	Q_OBJECT
public:
	Cam1Thread_FM(QObject* parent = nullptr);
	//自定义发送的信号
signals:
	void finishSlot();
protected:
	void run() override;
};