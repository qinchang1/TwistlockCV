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
	void myThreadSignal(const int);
	//自定义槽
	public slots:
	void myThreadSlot(const int);
protected:
	void run() override;
};
