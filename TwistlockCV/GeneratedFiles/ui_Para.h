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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaWindow
{
public:
    QWidget *centralwidget;
    QPushButton *update_pushButton;
    QGroupBox *groupBox_2;
    QLineEdit *errorRange_lineEdit;
    QLabel *errorRange_Label;
    QLabel *label;
    QLabel *cameraPara0_Label_1;
    QLabel *label_3;
    QLineEdit *cameraPara0_lineEdit_1;
    QLabel *label_6;
    QLabel *cameraPara1_Label_1;
    QLineEdit *cameraPara1_lineEdit_1;
    QLabel *label_7;
    QLabel *cameraPara2_Label_1;
    QLineEdit *cameraPara2_lineEdit_1;
    QLabel *label_8;
    QLabel *cameraPara3_Label_1;
    QLineEdit *cameraPara3_lineEdit_1;
    QLabel *label_9;
    QLineEdit *cameraPara1_lineEdit_2;
    QLabel *cameraPara3_Label_2;
    QLineEdit *cameraPara3_lineEdit_2;
    QLabel *cameraPara1_Label_2;
    QLineEdit *cameraPara2_lineEdit_2;
    QLabel *cameraPara0_Label_2;
    QLabel *label_10;
    QLineEdit *cameraPara0_lineEdit_2;
    QLabel *cameraPara2_Label_2;
    QGroupBox *groupBox;
    QLineEdit *minRatio_lineEdit;
    QLabel *matchType_Label;
    QLabel *minHessian_Label;
    QComboBox *matchType_comboBox;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *minRatio_Label;
    QLineEdit *minHessian_lineEdit;
    QLabel *label_5;
    QPushButton *cancel_pushButton;
    QPushButton *default_pushButton;

    void setupUi(QMainWindow *ParaWindow)
    {
        if (ParaWindow->objectName().isEmpty())
            ParaWindow->setObjectName(QStringLiteral("ParaWindow"));
        ParaWindow->resize(700, 480);
        centralwidget = new QWidget(ParaWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        update_pushButton = new QPushButton(centralwidget);
        update_pushButton->setObjectName(QStringLiteral("update_pushButton"));
        update_pushButton->setGeometry(QRect(490, 440, 93, 28));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 170, 681, 261));
        errorRange_lineEdit = new QLineEdit(groupBox_2);
        errorRange_lineEdit->setObjectName(QStringLiteral("errorRange_lineEdit"));
        errorRange_lineEdit->setGeometry(QRect(290, 20, 110, 21));
        errorRange_Label = new QLabel(groupBox_2);
        errorRange_Label->setObjectName(QStringLiteral("errorRange_Label"));
        errorRange_Label->setGeometry(QRect(180, 20, 81, 21));
        errorRange_Label->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 121, 21));
        cameraPara0_Label_1 = new QLabel(groupBox_2);
        cameraPara0_Label_1->setObjectName(QStringLiteral("cameraPara0_Label_1"));
        cameraPara0_Label_1->setGeometry(QRect(180, 100, 81, 21));
        cameraPara0_Label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 91, 21));
        cameraPara0_lineEdit_1 = new QLineEdit(groupBox_2);
        cameraPara0_lineEdit_1->setObjectName(QStringLiteral("cameraPara0_lineEdit_1"));
        cameraPara0_lineEdit_1->setGeometry(QRect(290, 100, 110, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 141, 21));
        cameraPara1_Label_1 = new QLabel(groupBox_2);
        cameraPara1_Label_1->setObjectName(QStringLiteral("cameraPara1_Label_1"));
        cameraPara1_Label_1->setGeometry(QRect(180, 140, 81, 21));
        cameraPara1_Label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cameraPara1_lineEdit_1 = new QLineEdit(groupBox_2);
        cameraPara1_lineEdit_1->setObjectName(QStringLiteral("cameraPara1_lineEdit_1"));
        cameraPara1_lineEdit_1->setGeometry(QRect(290, 140, 110, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 180, 151, 21));
        cameraPara2_Label_1 = new QLabel(groupBox_2);
        cameraPara2_Label_1->setObjectName(QStringLiteral("cameraPara2_Label_1"));
        cameraPara2_Label_1->setGeometry(QRect(180, 180, 81, 21));
        cameraPara2_Label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cameraPara2_lineEdit_1 = new QLineEdit(groupBox_2);
        cameraPara2_lineEdit_1->setObjectName(QStringLiteral("cameraPara2_lineEdit_1"));
        cameraPara2_lineEdit_1->setGeometry(QRect(290, 180, 110, 21));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 151, 21));
        cameraPara3_Label_1 = new QLabel(groupBox_2);
        cameraPara3_Label_1->setObjectName(QStringLiteral("cameraPara3_Label_1"));
        cameraPara3_Label_1->setGeometry(QRect(180, 220, 81, 21));
        cameraPara3_Label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cameraPara3_lineEdit_1 = new QLineEdit(groupBox_2);
        cameraPara3_lineEdit_1->setObjectName(QStringLiteral("cameraPara3_lineEdit_1"));
        cameraPara3_lineEdit_1->setGeometry(QRect(290, 220, 110, 21));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 60, 221, 22));
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229);"));
        label_9->setAlignment(Qt::AlignCenter);
        cameraPara1_lineEdit_2 = new QLineEdit(groupBox_2);
        cameraPara1_lineEdit_2->setObjectName(QStringLiteral("cameraPara1_lineEdit_2"));
        cameraPara1_lineEdit_2->setGeometry(QRect(560, 140, 110, 21));
        cameraPara3_Label_2 = new QLabel(groupBox_2);
        cameraPara3_Label_2->setObjectName(QStringLiteral("cameraPara3_Label_2"));
        cameraPara3_Label_2->setGeometry(QRect(450, 220, 81, 21));
        cameraPara3_Label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cameraPara3_lineEdit_2 = new QLineEdit(groupBox_2);
        cameraPara3_lineEdit_2->setObjectName(QStringLiteral("cameraPara3_lineEdit_2"));
        cameraPara3_lineEdit_2->setGeometry(QRect(560, 220, 110, 21));
        cameraPara1_Label_2 = new QLabel(groupBox_2);
        cameraPara1_Label_2->setObjectName(QStringLiteral("cameraPara1_Label_2"));
        cameraPara1_Label_2->setGeometry(QRect(450, 140, 81, 21));
        cameraPara1_Label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cameraPara2_lineEdit_2 = new QLineEdit(groupBox_2);
        cameraPara2_lineEdit_2->setObjectName(QStringLiteral("cameraPara2_lineEdit_2"));
        cameraPara2_lineEdit_2->setGeometry(QRect(560, 180, 110, 21));
        cameraPara0_Label_2 = new QLabel(groupBox_2);
        cameraPara0_Label_2->setObjectName(QStringLiteral("cameraPara0_Label_2"));
        cameraPara0_Label_2->setGeometry(QRect(450, 100, 81, 21));
        cameraPara0_Label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(450, 60, 221, 22));
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229);"));
        label_10->setAlignment(Qt::AlignCenter);
        cameraPara0_lineEdit_2 = new QLineEdit(groupBox_2);
        cameraPara0_lineEdit_2->setObjectName(QStringLiteral("cameraPara0_lineEdit_2"));
        cameraPara0_lineEdit_2->setGeometry(QRect(560, 100, 110, 21));
        cameraPara2_Label_2 = new QLabel(groupBox_2);
        cameraPara2_Label_2->setObjectName(QStringLiteral("cameraPara2_Label_2"));
        cameraPara2_Label_2->setGeometry(QRect(450, 180, 81, 21));
        cameraPara2_Label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 681, 151));
        minRatio_lineEdit = new QLineEdit(groupBox);
        minRatio_lineEdit->setObjectName(QStringLiteral("minRatio_lineEdit"));
        minRatio_lineEdit->setGeometry(QRect(290, 110, 110, 21));
        matchType_Label = new QLabel(groupBox);
        matchType_Label->setObjectName(QStringLiteral("matchType_Label"));
        matchType_Label->setGeometry(QRect(180, 30, 81, 21));
        matchType_Label->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        minHessian_Label = new QLabel(groupBox);
        minHessian_Label->setObjectName(QStringLiteral("minHessian_Label"));
        minHessian_Label->setGeometry(QRect(180, 70, 81, 21));
        minHessian_Label->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        matchType_comboBox = new QComboBox(groupBox);
        matchType_comboBox->setObjectName(QStringLiteral("matchType_comboBox"));
        matchType_comboBox->setGeometry(QRect(290, 30, 110, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 161, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 91, 21));
        minRatio_Label = new QLabel(groupBox);
        minRatio_Label->setObjectName(QStringLiteral("minRatio_Label"));
        minRatio_Label->setGeometry(QRect(180, 110, 81, 21));
        minRatio_Label->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        minHessian_lineEdit = new QLineEdit(groupBox);
        minHessian_lineEdit->setObjectName(QStringLiteral("minHessian_lineEdit"));
        minHessian_lineEdit->setGeometry(QRect(290, 70, 110, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 131, 21));
        cancel_pushButton = new QPushButton(centralwidget);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));
        cancel_pushButton->setGeometry(QRect(600, 440, 93, 28));
        default_pushButton = new QPushButton(centralwidget);
        default_pushButton->setObjectName(QStringLiteral("default_pushButton"));
        default_pushButton->setGeometry(QRect(380, 440, 93, 28));
        ParaWindow->setCentralWidget(centralwidget);

        retranslateUi(ParaWindow);

        QMetaObject::connectSlotsByName(ParaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ParaWindow)
    {
        ParaWindow->setWindowTitle(QApplication::translate("ParaWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        update_pushButton->setText(QApplication::translate("ParaWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ParaWindow", "\346\265\213\350\267\235\345\217\202\346\225\260", Q_NULLPTR));
        errorRange_Label->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\264\345\270\270\346\225\260\357\274\232", Q_NULLPTR));
        cameraPara0_Label_1->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("ParaWindow", "\345\201\217\345\267\256\350\214\203\345\233\264\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\264\344\270\200\346\254\241\351\241\271\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        cameraPara1_Label_1->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\264\344\272\214\346\254\241\351\241\271\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        cameraPara2_Label_1->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\264\344\270\211\346\254\241\351\241\271\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        cameraPara3_Label_1->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\2641\345\217\202\346\225\260", Q_NULLPTR));
        cameraPara1_lineEdit_2->setText(QString());
        cameraPara3_Label_2->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        cameraPara3_lineEdit_2->setText(QString());
        cameraPara1_Label_2->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        cameraPara2_lineEdit_2->setText(QString());
        cameraPara0_Label_2->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("ParaWindow", "\346\221\204\345\203\217\345\244\2642\345\217\202\346\225\260", Q_NULLPTR));
        cameraPara0_lineEdit_2->setText(QString());
        cameraPara2_Label_2->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ParaWindow", "\345\214\271\351\205\215\345\217\202\346\225\260", Q_NULLPTR));
        matchType_Label->setText(QString());
        minHessian_Label->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        matchType_comboBox->clear();
        matchType_comboBox->insertItems(0, QStringList()
         << QApplication::translate("ParaWindow", "ORB", Q_NULLPTR)
         << QApplication::translate("ParaWindow", "SURF", Q_NULLPTR)
         << QApplication::translate("ParaWindow", "SIFT", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("ParaWindow", "\351\273\221\345\241\236\347\237\251\351\230\265\351\230\210\345\200\274/\347\211\271\345\276\201\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ParaWindow", "\345\214\271\351\205\215\347\256\227\346\263\225\357\274\232", Q_NULLPTR));
        minRatio_Label->setText(QApplication::translate("ParaWindow", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("ParaWindow", "\347\255\233\351\200\211\346\257\224\344\276\213\350\214\203\345\233\264\357\274\232", Q_NULLPTR));
        cancel_pushButton->setText(QApplication::translate("ParaWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        default_pushButton->setText(QApplication::translate("ParaWindow", "\351\273\230\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParaWindow: public Ui_ParaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARA_H
