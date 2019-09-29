#include "para.h"

ParaWindow::ParaWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void ParaWindow::on_ok_pushButton_clicked()
{
	this->close();
}