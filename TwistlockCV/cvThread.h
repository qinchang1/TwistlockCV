#pragma once
#include <QThread>
#include <QDebug>
#include "cvFunction.h"

class Cam1Thread : public QThread
{
	Q_OBJECT
public:
	Cam1Thread(QObject* parent = nullptr);
	//�Զ��巢�͵��ź�
signals:
	void myThreadSignal(const int);
	//�Զ����
	public slots:
	void myThreadSlot(const int);
protected:
	void run() override;
};
