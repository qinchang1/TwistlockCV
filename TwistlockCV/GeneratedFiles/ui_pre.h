/********************************************************************************
** Form generated from reading UI file 'pre.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRE_H
#define UI_PRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preWindow
{
public:
    QWidget *centralwidget;
    QCheckBox *binary_checkBox;
    QPushButton *ok_Button;
    QGroupBox *groupBox;
    QSpinBox *dilate_spinBox;
    QLabel *label_5;
    QSpinBox *highTh_spinBox;
    QSpinBox *erode_spinBox;
    QSlider *dilate_horizontalSlider;
    QSlider *erode_horizontalSlider;
    QSlider *highTh_horizontalSlider;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *blur_spinBox;
    QLabel *label_3;
    QSlider *lowTh_horizontalSlider;
    QSlider *blur_horizontalSlider;
    QLabel *label;
    QSpinBox *lowTh_spinBox;
    QGroupBox *groupBox_2;
    QSpinBox *dilate_spinBox_2;
    QLabel *label_6;
    QSpinBox *highTh_spinBox_2;
    QSpinBox *erode_spinBox_2;
    QSlider *dilate_horizontalSlider_2;
    QSlider *erode_horizontalSlider_2;
    QSlider *highTh_horizontalSlider_2;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *blur_spinBox_2;
    QLabel *label_9;
    QSlider *lowTh_horizontalSlider_2;
    QSlider *blur_horizontalSlider_2;
    QLabel *label_10;
    QSpinBox *lowTh_spinBox_2;
    QPushButton *default_Button;

    void setupUi(QMainWindow *preWindow)
    {
        if (preWindow->objectName().isEmpty())
            preWindow->setObjectName(QStringLiteral("preWindow"));
        preWindow->resize(430, 520);
        centralwidget = new QWidget(preWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        binary_checkBox = new QCheckBox(centralwidget);
        binary_checkBox->setObjectName(QStringLiteral("binary_checkBox"));
        binary_checkBox->setGeometry(QRect(30, 480, 111, 19));
        ok_Button = new QPushButton(centralwidget);
        ok_Button->setObjectName(QStringLiteral("ok_Button"));
        ok_Button->setGeometry(QRect(320, 480, 93, 28));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 391, 221));
        dilate_spinBox = new QSpinBox(groupBox);
        dilate_spinBox->setObjectName(QStringLiteral("dilate_spinBox"));
        dilate_spinBox->setGeometry(QRect(330, 110, 46, 22));
        dilate_spinBox->setMaximum(10);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 190, 81, 16));
        highTh_spinBox = new QSpinBox(groupBox);
        highTh_spinBox->setObjectName(QStringLiteral("highTh_spinBox"));
        highTh_spinBox->setGeometry(QRect(330, 70, 46, 22));
        highTh_spinBox->setMaximum(254);
        erode_spinBox = new QSpinBox(groupBox);
        erode_spinBox->setObjectName(QStringLiteral("erode_spinBox"));
        erode_spinBox->setGeometry(QRect(330, 150, 46, 22));
        erode_spinBox->setMaximum(10);
        dilate_horizontalSlider = new QSlider(groupBox);
        dilate_horizontalSlider->setObjectName(QStringLiteral("dilate_horizontalSlider"));
        dilate_horizontalSlider->setGeometry(QRect(110, 110, 201, 22));
        dilate_horizontalSlider->setMaximum(10);
        dilate_horizontalSlider->setOrientation(Qt::Horizontal);
        dilate_horizontalSlider->setInvertedAppearance(false);
        dilate_horizontalSlider->setInvertedControls(false);
        dilate_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        erode_horizontalSlider = new QSlider(groupBox);
        erode_horizontalSlider->setObjectName(QStringLiteral("erode_horizontalSlider"));
        erode_horizontalSlider->setGeometry(QRect(110, 150, 201, 22));
        erode_horizontalSlider->setMaximum(10);
        erode_horizontalSlider->setOrientation(Qt::Horizontal);
        erode_horizontalSlider->setInvertedAppearance(false);
        erode_horizontalSlider->setInvertedControls(false);
        erode_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        highTh_horizontalSlider = new QSlider(groupBox);
        highTh_horizontalSlider->setObjectName(QStringLiteral("highTh_horizontalSlider"));
        highTh_horizontalSlider->setGeometry(QRect(110, 70, 201, 22));
        highTh_horizontalSlider->setMaximum(254);
        highTh_horizontalSlider->setOrientation(Qt::Horizontal);
        highTh_horizontalSlider->setInvertedAppearance(false);
        highTh_horizontalSlider->setInvertedControls(false);
        highTh_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 81, 16));
        blur_spinBox = new QSpinBox(groupBox);
        blur_spinBox->setObjectName(QStringLiteral("blur_spinBox"));
        blur_spinBox->setGeometry(QRect(330, 190, 46, 22));
        blur_spinBox->setMinimum(1);
        blur_spinBox->setMaximum(10);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 81, 16));
        lowTh_horizontalSlider = new QSlider(groupBox);
        lowTh_horizontalSlider->setObjectName(QStringLiteral("lowTh_horizontalSlider"));
        lowTh_horizontalSlider->setGeometry(QRect(110, 30, 201, 22));
        lowTh_horizontalSlider->setMaximum(254);
        lowTh_horizontalSlider->setOrientation(Qt::Horizontal);
        lowTh_horizontalSlider->setInvertedAppearance(false);
        lowTh_horizontalSlider->setInvertedControls(false);
        lowTh_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        blur_horizontalSlider = new QSlider(groupBox);
        blur_horizontalSlider->setObjectName(QStringLiteral("blur_horizontalSlider"));
        blur_horizontalSlider->setGeometry(QRect(110, 190, 201, 22));
        blur_horizontalSlider->setMinimum(1);
        blur_horizontalSlider->setMaximum(10);
        blur_horizontalSlider->setPageStep(1);
        blur_horizontalSlider->setOrientation(Qt::Horizontal);
        blur_horizontalSlider->setInvertedAppearance(false);
        blur_horizontalSlider->setInvertedControls(false);
        blur_horizontalSlider->setTickPosition(QSlider::TicksAbove);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 91, 16));
        lowTh_spinBox = new QSpinBox(groupBox);
        lowTh_spinBox->setObjectName(QStringLiteral("lowTh_spinBox"));
        lowTh_spinBox->setGeometry(QRect(330, 30, 46, 22));
        lowTh_spinBox->setMaximum(254);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 391, 221));
        dilate_spinBox_2 = new QSpinBox(groupBox_2);
        dilate_spinBox_2->setObjectName(QStringLiteral("dilate_spinBox_2"));
        dilate_spinBox_2->setGeometry(QRect(330, 110, 46, 22));
        dilate_spinBox_2->setMaximum(10);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 190, 81, 16));
        highTh_spinBox_2 = new QSpinBox(groupBox_2);
        highTh_spinBox_2->setObjectName(QStringLiteral("highTh_spinBox_2"));
        highTh_spinBox_2->setGeometry(QRect(330, 70, 46, 22));
        highTh_spinBox_2->setMaximum(254);
        erode_spinBox_2 = new QSpinBox(groupBox_2);
        erode_spinBox_2->setObjectName(QStringLiteral("erode_spinBox_2"));
        erode_spinBox_2->setGeometry(QRect(330, 150, 46, 22));
        erode_spinBox_2->setMaximum(10);
        dilate_horizontalSlider_2 = new QSlider(groupBox_2);
        dilate_horizontalSlider_2->setObjectName(QStringLiteral("dilate_horizontalSlider_2"));
        dilate_horizontalSlider_2->setGeometry(QRect(110, 110, 201, 22));
        dilate_horizontalSlider_2->setMaximum(10);
        dilate_horizontalSlider_2->setOrientation(Qt::Horizontal);
        dilate_horizontalSlider_2->setInvertedAppearance(false);
        dilate_horizontalSlider_2->setInvertedControls(false);
        dilate_horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        erode_horizontalSlider_2 = new QSlider(groupBox_2);
        erode_horizontalSlider_2->setObjectName(QStringLiteral("erode_horizontalSlider_2"));
        erode_horizontalSlider_2->setGeometry(QRect(110, 150, 201, 22));
        erode_horizontalSlider_2->setMaximum(10);
        erode_horizontalSlider_2->setOrientation(Qt::Horizontal);
        erode_horizontalSlider_2->setInvertedAppearance(false);
        erode_horizontalSlider_2->setInvertedControls(false);
        erode_horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        highTh_horizontalSlider_2 = new QSlider(groupBox_2);
        highTh_horizontalSlider_2->setObjectName(QStringLiteral("highTh_horizontalSlider_2"));
        highTh_horizontalSlider_2->setGeometry(QRect(110, 70, 201, 22));
        highTh_horizontalSlider_2->setMaximum(254);
        highTh_horizontalSlider_2->setOrientation(Qt::Horizontal);
        highTh_horizontalSlider_2->setInvertedAppearance(false);
        highTh_horizontalSlider_2->setInvertedControls(false);
        highTh_horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 91, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 150, 81, 16));
        blur_spinBox_2 = new QSpinBox(groupBox_2);
        blur_spinBox_2->setObjectName(QStringLiteral("blur_spinBox_2"));
        blur_spinBox_2->setGeometry(QRect(330, 190, 46, 22));
        blur_spinBox_2->setMinimum(1);
        blur_spinBox_2->setMaximum(10);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 110, 81, 16));
        lowTh_horizontalSlider_2 = new QSlider(groupBox_2);
        lowTh_horizontalSlider_2->setObjectName(QStringLiteral("lowTh_horizontalSlider_2"));
        lowTh_horizontalSlider_2->setGeometry(QRect(110, 30, 201, 22));
        lowTh_horizontalSlider_2->setMaximum(254);
        lowTh_horizontalSlider_2->setOrientation(Qt::Horizontal);
        lowTh_horizontalSlider_2->setInvertedAppearance(false);
        lowTh_horizontalSlider_2->setInvertedControls(false);
        lowTh_horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        blur_horizontalSlider_2 = new QSlider(groupBox_2);
        blur_horizontalSlider_2->setObjectName(QStringLiteral("blur_horizontalSlider_2"));
        blur_horizontalSlider_2->setGeometry(QRect(110, 190, 201, 22));
        blur_horizontalSlider_2->setMinimum(1);
        blur_horizontalSlider_2->setMaximum(10);
        blur_horizontalSlider_2->setPageStep(1);
        blur_horizontalSlider_2->setOrientation(Qt::Horizontal);
        blur_horizontalSlider_2->setInvertedAppearance(false);
        blur_horizontalSlider_2->setInvertedControls(false);
        blur_horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 91, 16));
        lowTh_spinBox_2 = new QSpinBox(groupBox_2);
        lowTh_spinBox_2->setObjectName(QStringLiteral("lowTh_spinBox_2"));
        lowTh_spinBox_2->setGeometry(QRect(330, 30, 46, 22));
        lowTh_spinBox_2->setMaximum(254);
        default_Button = new QPushButton(centralwidget);
        default_Button->setObjectName(QStringLiteral("default_Button"));
        default_Button->setGeometry(QRect(210, 480, 93, 28));
        preWindow->setCentralWidget(centralwidget);

        retranslateUi(preWindow);

        QMetaObject::connectSlotsByName(preWindow);
    } // setupUi

    void retranslateUi(QMainWindow *preWindow)
    {
        preWindow->setWindowTitle(QApplication::translate("preWindow", "\351\242\204\345\244\204\347\220\206\347\252\227\345\217\243", Q_NULLPTR));
        binary_checkBox->setText(QApplication::translate("preWindow", "\344\272\214\345\200\274\345\214\226\346\230\276\347\244\272", Q_NULLPTR));
        ok_Button->setText(QApplication::translate("preWindow", "\345\256\214\346\210\220", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("preWindow", "\344\270\273\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_5->setText(QApplication::translate("preWindow", "\345\271\263\346\273\221\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("preWindow", "\344\272\214\345\200\274\351\253\230\351\230\210\345\200\274\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("preWindow", "\350\205\220\350\232\200\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("preWindow", "\350\206\250\350\203\200\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("preWindow", "\344\272\214\345\200\274\344\275\216\351\230\210\345\200\274\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("preWindow", "\345\211\257\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("preWindow", "\345\271\263\346\273\221\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("preWindow", "\344\272\214\345\200\274\351\253\230\351\230\210\345\200\274\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("preWindow", "\350\205\220\350\232\200\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("preWindow", "\350\206\250\350\203\200\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("preWindow", "\344\272\214\345\200\274\344\275\216\351\230\210\345\200\274\357\274\232", Q_NULLPTR));
        default_Button->setText(QApplication::translate("preWindow", "\346\201\242\345\244\215\351\273\230\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class preWindow: public Ui_preWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRE_H
