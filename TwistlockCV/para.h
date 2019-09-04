#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <ui_Para.h>

class ParaWindow : public QMainWindow
{
	Q_OBJECT

public:
	ParaWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::ParaWindow ui;

	private slots:
	void on_ok_pushButton_clicked();
};