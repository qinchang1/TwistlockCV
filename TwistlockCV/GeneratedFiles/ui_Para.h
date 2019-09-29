/********************************************************************************
** Form generated from reading UI file 'Para.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARA_H
#define UI_PARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ok_pushButton;

    void setupUi(QMainWindow *ParaWindow)
    {
        if (ParaWindow->objectName().isEmpty())
            ParaWindow->setObjectName(QStringLiteral("ParaWindow"));
        ParaWindow->resize(800, 600);
        centralwidget = new QWidget(ParaWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ok_pushButton = new QPushButton(centralwidget);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));
        ok_pushButton->setGeometry(QRect(690, 560, 93, 28));
        ParaWindow->setCentralWidget(centralwidget);

        retranslateUi(ParaWindow);

        QMetaObject::connectSlotsByName(ParaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ParaWindow)
    {
        ParaWindow->setWindowTitle(QApplication::translate("ParaWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        ok_pushButton->setText(QApplication::translate("ParaWindow", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParaWindow: public Ui_ParaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARA_H
