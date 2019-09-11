#pragma once
#include <QThread>
#include "cvFunction.h"

// ******************* ����ͼ��ָ� ********************** //

class Cam1Thread : public QThread
{
	Q_OBJECT
public:
	Cam1Thread(QObject* parent = nullptr);
//�Զ��巢�͵��ź�
signals:
	void finishSplit();
	void finishMatch();
	void finishAll();
protected:
	void run() override;
};

class Cam2Thread : public QThread
{
	Q_OBJECT
public:
	Cam2Thread(QObject* parent = nullptr);
	//�Զ��巢�͵��ź�
signals:
	void finishSplit();
	void finishMatch();
	void finishAll();
protected:
	void run() override;
};
