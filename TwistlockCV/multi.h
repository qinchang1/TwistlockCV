#pragma once

#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <ui_Multi.h>

class MultiWindow : public QMainWindow
{
	Q_OBJECT

public:
	MultiWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::mutilWindow ui;

private slots:
void on_cancel_pushButton_clicked();
void on_update_pushButton_clicked();
void on_default_pushButton_clicked();
};
