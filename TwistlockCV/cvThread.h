#pragma once
#include <QThread>
#include <QDebug>
#include "cvFunction.h"

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
