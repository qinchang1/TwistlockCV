/********************************************************************************
** Form generated from reading UI file 'Multi.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTI_H
#define UI_MULTI_H

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

class Ui_mutilWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *default_pushButton;
    QPushButton *cancel_pushButton;
    QPushButton *update_pushButton;

    void setupUi(QMainWindow *mutilWindow)
    {
        if (mutilWindow->objectName().isEmpty())
            mutilWindow->setObjectName(QStringLiteral("mutilWindow"));
        mutilWindow->resize(800, 640);
        centralwidget = new QWidget(mutilWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 651, 411));
        label->setStyleSheet(QStringLiteral("image: url(:/multi/GeneratedFiles/multi.jpg);"));
        default_pushButton = new QPushButton(centralwidget);
        default_pushButton->setObjectName(QStringLiteral("default_pushButton"));
        default_pushButton->setGeometry(QRect(450, 590, 93, 28));
        cancel_pushButton = new QPushButton(centralwidget);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));
        cancel_pushButton->setGeometry(QRect(670, 590, 93, 28));
        update_pushButton = new QPushButton(centralwidget);
        update_pushButton->setObjectName(QStringLiteral("update_pushButton"));
        update_pushButton->setGeometry(QRect(560, 590, 93, 28));
        mutilWindow->setCentralWidget(centralwidget);

        retranslateUi(mutilWindow);

        QMetaObject::connectSlotsByName(mutilWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mutilWindow)
    {
        mutilWindow->setWindowTitle(QApplication::translate("mutilWindow", "\345\244\232\347\233\256\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QString());
        default_pushButton->setText(QApplication::translate("mutilWindow", "\351\273\230\350\256\244", Q_NULLPTR));
        cancel_pushButton->setText(QApplication::translate("mutilWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        update_pushButton->setText(QApplication::translate("mutilWindow", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mutilWindow: public Ui_mutilWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTI_H
