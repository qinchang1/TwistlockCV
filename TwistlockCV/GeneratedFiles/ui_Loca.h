/********************************************************************************
** Form generated from reading UI file 'Loca.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCA_H
#define UI_LOCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocaWin
{
public:
    QWidget *centralwidget;
    QLabel *cam1_label;
    QLabel *cam2_label;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *location_pushButton;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *X_label;
    QLabel *Y_label;
    QLabel *Z_label;

    void setupUi(QMainWindow *LocaWin)
    {
        if (LocaWin->objectName().isEmpty())
            LocaWin->setObjectName(QStringLiteral("LocaWin"));
        LocaWin->resize(800, 550);
        centralwidget = new QWidget(LocaWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cam1_label = new QLabel(centralwidget);
        cam1_label->setObjectName(QStringLiteral("cam1_label"));
        cam1_label->setGeometry(QRect(10, 30, 640, 240));
        cam1_label->setStyleSheet(QStringLiteral("background-color: rgb(195, 195, 195);"));
        cam2_label = new QLabel(centralwidget);
        cam2_label->setObjectName(QStringLiteral("cam2_label"));
        cam2_label->setGeometry(QRect(10, 300, 640, 240));
        cam2_label->setStyleSheet(QStringLiteral("background-color: rgb(195, 195, 195);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 280, 71, 20));
        label->setStyleSheet(QStringLiteral("background-color: rgb(145, 145, 145);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 71, 20));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(145, 145, 145);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 430, 111, 28));
        location_pushButton = new QPushButton(centralwidget);
        location_pushButton->setObjectName(QStringLiteral("location_pushButton"));
        location_pushButton->setGeometry(QRect(670, 510, 111, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(670, 470, 111, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 30, 21, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 70, 21, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 110, 21, 20));
        X_label = new QLabel(centralwidget);
        X_label->setObjectName(QStringLiteral("X_label"));
        X_label->setGeometry(QRect(700, 30, 72, 20));
        X_label->setStyleSheet(QStringLiteral("background-color: rgb(185, 185, 185);"));
        Y_label = new QLabel(centralwidget);
        Y_label->setObjectName(QStringLiteral("Y_label"));
        Y_label->setGeometry(QRect(700, 70, 72, 20));
        Y_label->setStyleSheet(QStringLiteral("background-color: rgb(185, 185, 185);"));
        Z_label = new QLabel(centralwidget);
        Z_label->setObjectName(QStringLiteral("Z_label"));
        Z_label->setGeometry(QRect(700, 110, 72, 20));
        Z_label->setStyleSheet(QStringLiteral("background-color: rgb(185, 185, 185);"));
        LocaWin->setCentralWidget(centralwidget);

        retranslateUi(LocaWin);

        QMetaObject::connectSlotsByName(LocaWin);
    } // setupUi

    void retranslateUi(QMainWindow *LocaWin)
    {
        LocaWin->setWindowTitle(QApplication::translate("LocaWin", "\345\256\232\344\275\215\346\265\213\350\257\225", Q_NULLPTR));
        cam1_label->setText(QString());
        cam2_label->setText(QString());
        label->setText(QApplication::translate("LocaWin", "\345\217\214\347\233\256\347\233\270\346\234\2722", Q_NULLPTR));
        label_2->setText(QApplication::translate("LocaWin", "\345\217\214\347\233\256\347\233\270\346\234\2721", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LocaWin", "\346\221\204\345\203\217\345\244\264\345\257\274\345\205\245", Q_NULLPTR));
        location_pushButton->setText(QApplication::translate("LocaWin", "\346\211\255\351\224\201\345\256\232\344\275\215", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("LocaWin", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("LocaWin", "X:", Q_NULLPTR));
        label_4->setText(QApplication::translate("LocaWin", "Y:", Q_NULLPTR));
        label_5->setText(QApplication::translate("LocaWin", "Z:", Q_NULLPTR));
        X_label->setText(QApplication::translate("LocaWin", "0", Q_NULLPTR));
        Y_label->setText(QApplication::translate("LocaWin", "0", Q_NULLPTR));
        Z_label->setText(QApplication::translate("LocaWin", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LocaWin: public Ui_LocaWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCA_H
