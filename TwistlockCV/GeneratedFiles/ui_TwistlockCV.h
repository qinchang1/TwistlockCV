/********************************************************************************
** Form generated from reading UI file 'TwistlockCV.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWISTLOCKCV_H
#define UI_TWISTLOCKCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwistlockCVClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TwistlockCVClass)
    {
        if (TwistlockCVClass->objectName().isEmpty())
            TwistlockCVClass->setObjectName(QStringLiteral("TwistlockCVClass"));
        TwistlockCVClass->resize(600, 400);
        menuBar = new QMenuBar(TwistlockCVClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TwistlockCVClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TwistlockCVClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TwistlockCVClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TwistlockCVClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TwistlockCVClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TwistlockCVClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TwistlockCVClass->setStatusBar(statusBar);

        retranslateUi(TwistlockCVClass);

        QMetaObject::connectSlotsByName(TwistlockCVClass);
    } // setupUi

    void retranslateUi(QMainWindow *TwistlockCVClass)
    {
        TwistlockCVClass->setWindowTitle(QApplication::translate("TwistlockCVClass", "TwistlockCV", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwistlockCVClass: public Ui_TwistlockCVClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWISTLOCKCV_H
