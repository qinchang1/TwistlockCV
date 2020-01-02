#include "multi.h"



MultiWindow::MultiWindow(QWidget *parent): QMainWindow(parent){

	ui.setupUi(this);
}


void MultiWindow::on_update_pushButton_clicked() {

}

void MultiWindow::on_default_pushButton_clicked() {

}

void MultiWindow::on_cancel_pushButton_clicked(){
	this->close();
}