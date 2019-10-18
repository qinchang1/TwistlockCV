/********************************************************************************
** Form generated from reading UI file 'CvSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVSYSTEM_H
#define UI_CVSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CvSystemClass
{
public:
    QAction *new_action;
    QAction *save_action;
    QAction *paraSet_Action;
    QAction *preSet_Action;
    QAction *actions;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *displayStatus_Label;
    QLabel *videoLabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *detectionFrame_Label_1;
    QWidget *tab_2;
    QLabel *matchFrame_Label_1;
    QWidget *tab_3;
    QLabel *rightFrame_Label_1;
    QLabel *leftFrame_Label_1;
    QTextBrowser *textBrowser;
    QLabel *displayStatus_Label_2;
    QLabel *label_2;
    QLabel *videoLabel_2;
    QLabel *label_X;
    QLabel *label_Z;
    QLabel *label_A;
    QLabel *label_3;
    QLabel *label_Y;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_A_2;
    QLabel *label_7;
    QComboBox *capType_comboBox;
    QProgressBar *extract_progressBar;
    QLabel *matchType_Label;
    QComboBox *capType_comboBox_2;
    QProgressBar *extract_progressBar_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QLabel *detectionFrame_Label_2;
    QWidget *tab_5;
    QLabel *matchFrame_Label_2;
    QWidget *tab_6;
    QLabel *rightFrame_Label_2;
    QLabel *leftFrame_Label_2;
    QLabel *label_8;
    QLabel *logName_Label;
    QGroupBox *groupBox;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QGroupBox *groupBox_2;
    QPushButton *display_Button;
    QPushButton *start_Button;
    QPushButton *stop_Button;
    QGroupBox *groupBox_3;
    QLabel *distance_label_1;
    QLabel *label_30;
    QGroupBox *groupBox_4;
    QLabel *distance_label_2;
    QLabel *label_35;
    QGroupBox *groupBox_5;
    QLabel *cenx_label_1;
    QLabel *label_31;
    QLabel *ceny_label_1;
    QLabel *label_32;
    QLabel *angle_label_1;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *feaNum_label_1;
    QGroupBox *groupBox_6;
    QLabel *cenx_label_2;
    QLabel *label_38;
    QLabel *ceny_label_2;
    QLabel *label_39;
    QLabel *angle_label_2;
    QLabel *label_40;
    QLabel *label_36;
    QLabel *feaNum_label_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *CvSystemClass)
    {
        if (CvSystemClass->objectName().isEmpty())
            CvSystemClass->setObjectName(QStringLiteral("CvSystemClass"));
        CvSystemClass->resize(1800, 950);
        CvSystemClass->setMinimumSize(QSize(1800, 950));
        CvSystemClass->setMaximumSize(QSize(1800, 950));
        new_action = new QAction(CvSystemClass);
        new_action->setObjectName(QStringLiteral("new_action"));
        save_action = new QAction(CvSystemClass);
        save_action->setObjectName(QStringLiteral("save_action"));
        paraSet_Action = new QAction(CvSystemClass);
        paraSet_Action->setObjectName(QStringLiteral("paraSet_Action"));
        preSet_Action = new QAction(CvSystemClass);
        preSet_Action->setObjectName(QStringLiteral("preSet_Action"));
        actions = new QAction(CvSystemClass);
        actions->setObjectName(QStringLiteral("actions"));
        centralWidget = new QWidget(CvSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 16));
        displayStatus_Label = new QLabel(centralWidget);
        displayStatus_Label->setObjectName(QStringLiteral("displayStatus_Label"));
        displayStatus_Label->setGeometry(QRect(570, 10, 80, 20));
        displayStatus_Label->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 170);"));
        displayStatus_Label->setAlignment(Qt::AlignCenter);
        videoLabel = new QLabel(centralWidget);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setGeometry(QRect(10, 30, 640, 240));
        videoLabel->setLayoutDirection(Qt::LeftToRight);
        videoLabel->setStyleSheet(QStringLiteral("background-color: rgb(133, 133, 133);"));
        videoLabel->setTextFormat(Qt::AutoText);
        videoLabel->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(660, 10, 660, 270));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        detectionFrame_Label_1 = new QLabel(tab);
        detectionFrame_Label_1->setObjectName(QStringLiteral("detectionFrame_Label_1"));
        detectionFrame_Label_1->setGeometry(QRect(0, 0, 640, 240));
        detectionFrame_Label_1->setAutoFillBackground(false);
        detectionFrame_Label_1->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        detectionFrame_Label_1->setTextFormat(Qt::AutoText);
        detectionFrame_Label_1->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        matchFrame_Label_1 = new QLabel(tab_2);
        matchFrame_Label_1->setObjectName(QStringLiteral("matchFrame_Label_1"));
        matchFrame_Label_1->setGeometry(QRect(0, 0, 640, 240));
        matchFrame_Label_1->setAutoFillBackground(false);
        matchFrame_Label_1->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        matchFrame_Label_1->setTextFormat(Qt::AutoText);
        matchFrame_Label_1->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        rightFrame_Label_1 = new QLabel(tab_3);
        rightFrame_Label_1->setObjectName(QStringLiteral("rightFrame_Label_1"));
        rightFrame_Label_1->setGeometry(QRect(330, 0, 320, 240));
        rightFrame_Label_1->setAutoFillBackground(false);
        rightFrame_Label_1->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        rightFrame_Label_1->setTextFormat(Qt::AutoText);
        rightFrame_Label_1->setAlignment(Qt::AlignCenter);
        leftFrame_Label_1 = new QLabel(tab_3);
        leftFrame_Label_1->setObjectName(QStringLiteral("leftFrame_Label_1"));
        leftFrame_Label_1->setGeometry(QRect(0, 0, 320, 240));
        leftFrame_Label_1->setAutoFillBackground(false);
        leftFrame_Label_1->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        leftFrame_Label_1->setTextFormat(Qt::AutoText);
        leftFrame_Label_1->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_3, QString());
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 570, 641, 321));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        displayStatus_Label_2 = new QLabel(centralWidget);
        displayStatus_Label_2->setObjectName(QStringLiteral("displayStatus_Label_2"));
        displayStatus_Label_2->setGeometry(QRect(570, 280, 80, 20));
        displayStatus_Label_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 170);"));
        displayStatus_Label_2->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 280, 141, 16));
        videoLabel_2 = new QLabel(centralWidget);
        videoLabel_2->setObjectName(QStringLiteral("videoLabel_2"));
        videoLabel_2->setGeometry(QRect(10, 300, 640, 240));
        videoLabel_2->setLayoutDirection(Qt::LeftToRight);
        videoLabel_2->setStyleSheet(QStringLiteral("background-color: rgb(133, 133, 133);"));
        videoLabel_2->setTextFormat(Qt::AutoText);
        videoLabel_2->setAlignment(Qt::AlignCenter);
        label_X = new QLabel(centralWidget);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setGeometry(QRect(1560, 40, 111, 25));
        QFont font;
        font.setPointSize(15);
        label_X->setFont(font);
        label_X->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_Z = new QLabel(centralWidget);
        label_Z->setObjectName(QStringLiteral("label_Z"));
        label_Z->setGeometry(QRect(1560, 120, 111, 25));
        label_Z->setFont(font);
        label_Z->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label_Z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_A = new QLabel(centralWidget);
        label_A->setObjectName(QStringLiteral("label_A"));
        label_A->setGeometry(QRect(1560, 160, 111, 25));
        label_A->setFont(font);
        label_A->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label_A->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1480, 40, 80, 25));
        label_3->setFont(font);
        label_Y = new QLabel(centralWidget);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        label_Y->setGeometry(QRect(1560, 80, 111, 25));
        label_Y->setFont(font);
        label_Y->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label_Y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1480, 80, 80, 25));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1480, 120, 80, 25));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1480, 160, 80, 25));
        label_6->setFont(font);
        label_A_2 = new QLabel(centralWidget);
        label_A_2->setObjectName(QStringLiteral("label_A_2"));
        label_A_2->setGeometry(QRect(1560, 200, 111, 25));
        label_A_2->setFont(font);
        label_A_2->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        label_A_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1480, 200, 80, 25));
        label_7->setFont(font);
        capType_comboBox = new QComboBox(centralWidget);
        capType_comboBox->setObjectName(QStringLiteral("capType_comboBox"));
        capType_comboBox->setGeometry(QRect(1320, 220, 111, 35));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(capType_comboBox->sizePolicy().hasHeightForWidth());
        capType_comboBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        capType_comboBox->setFont(font1);
        capType_comboBox->setAutoFillBackground(false);
        extract_progressBar = new QProgressBar(centralWidget);
        extract_progressBar->setObjectName(QStringLiteral("extract_progressBar"));
        extract_progressBar->setGeometry(QRect(1320, 260, 118, 23));
        extract_progressBar->setValue(0);
        matchType_Label = new QLabel(centralWidget);
        matchType_Label->setObjectName(QStringLiteral("matchType_Label"));
        matchType_Label->setGeometry(QRect(10, 550, 80, 20));
        matchType_Label->setStyleSheet(QStringLiteral("background-color: rgb(210, 210, 210);"));
        matchType_Label->setAlignment(Qt::AlignCenter);
        capType_comboBox_2 = new QComboBox(centralWidget);
        capType_comboBox_2->setObjectName(QStringLiteral("capType_comboBox_2"));
        capType_comboBox_2->setGeometry(QRect(1320, 490, 111, 35));
        sizePolicy.setHeightForWidth(capType_comboBox_2->sizePolicy().hasHeightForWidth());
        capType_comboBox_2->setSizePolicy(sizePolicy);
        capType_comboBox_2->setFont(font1);
        capType_comboBox_2->setAutoFillBackground(false);
        extract_progressBar_2 = new QProgressBar(centralWidget);
        extract_progressBar_2->setObjectName(QStringLiteral("extract_progressBar_2"));
        extract_progressBar_2->setGeometry(QRect(1320, 530, 118, 23));
        extract_progressBar_2->setValue(0);
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(660, 280, 660, 270));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        detectionFrame_Label_2 = new QLabel(tab_4);
        detectionFrame_Label_2->setObjectName(QStringLiteral("detectionFrame_Label_2"));
        detectionFrame_Label_2->setGeometry(QRect(0, 0, 640, 240));
        detectionFrame_Label_2->setAutoFillBackground(false);
        detectionFrame_Label_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        detectionFrame_Label_2->setTextFormat(Qt::AutoText);
        detectionFrame_Label_2->setAlignment(Qt::AlignCenter);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        matchFrame_Label_2 = new QLabel(tab_5);
        matchFrame_Label_2->setObjectName(QStringLiteral("matchFrame_Label_2"));
        matchFrame_Label_2->setGeometry(QRect(0, 0, 640, 240));
        matchFrame_Label_2->setAutoFillBackground(false);
        matchFrame_Label_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        matchFrame_Label_2->setTextFormat(Qt::AutoText);
        matchFrame_Label_2->setAlignment(Qt::AlignCenter);
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        rightFrame_Label_2 = new QLabel(tab_6);
        rightFrame_Label_2->setObjectName(QStringLiteral("rightFrame_Label_2"));
        rightFrame_Label_2->setGeometry(QRect(330, 0, 320, 240));
        rightFrame_Label_2->setAutoFillBackground(false);
        rightFrame_Label_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        rightFrame_Label_2->setTextFormat(Qt::AutoText);
        rightFrame_Label_2->setAlignment(Qt::AlignCenter);
        leftFrame_Label_2 = new QLabel(tab_6);
        leftFrame_Label_2->setObjectName(QStringLiteral("leftFrame_Label_2"));
        leftFrame_Label_2->setGeometry(QRect(0, 0, 320, 240));
        leftFrame_Label_2->setAutoFillBackground(false);
        leftFrame_Label_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(200, 200, 200);"));
        leftFrame_Label_2->setTextFormat(Qt::AutoText);
        leftFrame_Label_2->setAlignment(Qt::AlignCenter);
        tabWidget_2->addTab(tab_6, QString());
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1520, 930, 270, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        label_8->setFont(font2);
        label_8->setLayoutDirection(Qt::LeftToRight);
        logName_Label = new QLabel(centralWidget);
        logName_Label->setObjectName(QStringLiteral("logName_Label"));
        logName_Label->setGeometry(QRect(570, 550, 80, 20));
        logName_Label->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 170);"));
        logName_Label->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(660, 560, 661, 331));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 30, 72, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 30, 72, 20));
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 80, 72, 20));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(110, 80, 72, 20));
        label_12->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 120, 72, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 120, 72, 20));
        label_14->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 160, 72, 20));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(110, 160, 72, 20));
        label_16->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(110, 200, 72, 20));
        label_17->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(30, 240, 72, 20));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(30, 280, 72, 20));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(110, 240, 72, 20));
        label_20->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(110, 280, 72, 20));
        label_21->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 200, 72, 20));
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(310, 200, 72, 20));
        label_23->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(230, 240, 72, 20));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(230, 280, 72, 20));
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(310, 240, 72, 20));
        label_26->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_26->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(310, 280, 72, 20));
        label_27->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        label_27->setAlignment(Qt::AlignCenter);
        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(230, 200, 72, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1660, 700, 121, 181));
        display_Button = new QPushButton(groupBox_2);
        display_Button->setObjectName(QStringLiteral("display_Button"));
        display_Button->setGeometry(QRect(10, 30, 100, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(10);
        display_Button->setFont(font3);
        start_Button = new QPushButton(groupBox_2);
        start_Button->setObjectName(QStringLiteral("start_Button"));
        start_Button->setGeometry(QRect(10, 80, 100, 35));
        start_Button->setFont(font3);
        stop_Button = new QPushButton(groupBox_2);
        stop_Button->setObjectName(QStringLiteral("stop_Button"));
        stop_Button->setGeometry(QRect(10, 130, 100, 35));
        stop_Button->setFont(font3);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1320, 30, 111, 51));
        distance_label_1 = new QLabel(groupBox_3);
        distance_label_1->setObjectName(QStringLiteral("distance_label_1"));
        distance_label_1->setGeometry(QRect(10, 20, 71, 20));
        distance_label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        distance_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_30 = new QLabel(groupBox_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(90, 20, 21, 20));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1320, 300, 111, 51));
        distance_label_2 = new QLabel(groupBox_4);
        distance_label_2->setObjectName(QStringLiteral("distance_label_2"));
        distance_label_2->setGeometry(QRect(10, 20, 71, 20));
        distance_label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        distance_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(90, 20, 21, 16));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(1320, 80, 111, 141));
        cenx_label_1 = new QLabel(groupBox_5);
        cenx_label_1->setObjectName(QStringLiteral("cenx_label_1"));
        cenx_label_1->setGeometry(QRect(30, 20, 71, 20));
        cenx_label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cenx_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_31 = new QLabel(groupBox_5);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 20, 21, 20));
        ceny_label_1 = new QLabel(groupBox_5);
        ceny_label_1->setObjectName(QStringLiteral("ceny_label_1"));
        ceny_label_1->setGeometry(QRect(30, 50, 71, 20));
        ceny_label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        ceny_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_32 = new QLabel(groupBox_5);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 50, 21, 20));
        angle_label_1 = new QLabel(groupBox_5);
        angle_label_1->setObjectName(QStringLiteral("angle_label_1"));
        angle_label_1->setGeometry(QRect(30, 80, 71, 20));
        angle_label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        angle_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_33 = new QLabel(groupBox_5);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 80, 21, 21));
        label_34 = new QLabel(groupBox_5);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(10, 110, 21, 21));
        feaNum_label_1 = new QLabel(groupBox_5);
        feaNum_label_1->setObjectName(QStringLiteral("feaNum_label_1"));
        feaNum_label_1->setGeometry(QRect(30, 110, 71, 20));
        feaNum_label_1->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        feaNum_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(1320, 350, 111, 141));
        cenx_label_2 = new QLabel(groupBox_6);
        cenx_label_2->setObjectName(QStringLiteral("cenx_label_2"));
        cenx_label_2->setGeometry(QRect(30, 20, 71, 20));
        cenx_label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        cenx_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(10, 20, 21, 20));
        ceny_label_2 = new QLabel(groupBox_6);
        ceny_label_2->setObjectName(QStringLiteral("ceny_label_2"));
        ceny_label_2->setGeometry(QRect(30, 50, 71, 20));
        ceny_label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        ceny_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(10, 50, 21, 20));
        angle_label_2 = new QLabel(groupBox_6);
        angle_label_2->setObjectName(QStringLiteral("angle_label_2"));
        angle_label_2->setGeometry(QRect(30, 80, 71, 20));
        angle_label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        angle_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_40 = new QLabel(groupBox_6);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(10, 80, 21, 21));
        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(10, 110, 21, 21));
        feaNum_label_2 = new QLabel(groupBox_6);
        feaNum_label_2->setObjectName(QStringLiteral("feaNum_label_2"));
        feaNum_label_2->setGeometry(QRect(30, 110, 71, 20));
        feaNum_label_2->setStyleSheet(QStringLiteral("background-color: rgb(173, 173, 173);"));
        feaNum_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CvSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CvSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1800, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        CvSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CvSystemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CvSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(new_action);
        menu->addAction(save_action);
        menu_2->addAction(actions);
        mainToolBar->addAction(preSet_Action);
        mainToolBar->addSeparator();
        mainToolBar->addAction(paraSet_Action);
        mainToolBar->addSeparator();

        retranslateUi(CvSystemClass);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CvSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *CvSystemClass)
    {
        CvSystemClass->setWindowTitle(QApplication::translate("CvSystemClass", "CvSystem", Q_NULLPTR));
        new_action->setText(QApplication::translate("CvSystemClass", "\346\226\260\345\273\272", Q_NULLPTR));
        save_action->setText(QApplication::translate("CvSystemClass", "\344\277\235\345\255\230", Q_NULLPTR));
        paraSet_Action->setText(QApplication::translate("CvSystemClass", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        preSet_Action->setText(QApplication::translate("CvSystemClass", "\351\242\204\345\244\204\347\220\206\345\217\202\346\225\260", Q_NULLPTR));
        actions->setText(QApplication::translate("CvSystemClass", "\345\205\263\344\272\216", Q_NULLPTR));
        label->setText(QApplication::translate("CvSystemClass", "\350\247\206\351\242\221\350\276\223\345\205\245\357\274\210\344\270\273\346\221\204\357\274\211", Q_NULLPTR));
        displayStatus_Label->setText(QApplication::translate("CvSystemClass", "RGB\345\233\276\345\203\217", Q_NULLPTR));
        videoLabel->setText(QApplication::translate("CvSystemClass", "\350\247\206\351\242\221\350\276\223\345\205\245", Q_NULLPTR));
        detectionFrame_Label_1->setText(QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\346\243\200\346\265\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\346\243\200\346\265\213", Q_NULLPTR));
        matchFrame_Label_1->setText(QApplication::translate("CvSystemClass", "\347\211\271\345\276\201\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CvSystemClass", "\347\211\271\345\276\201\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        rightFrame_Label_1->setText(QApplication::translate("CvSystemClass", "\345\217\263\346\221\204\345\203\217\345\244\264\345\233\276\345\203\217", Q_NULLPTR));
        leftFrame_Label_1->setText(QApplication::translate("CvSystemClass", "\345\267\246\346\221\204\345\203\217\345\244\264\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CvSystemClass", "\345\267\246\345\217\263\345\233\276\345\203\217\345\210\206\345\211\262", Q_NULLPTR));
        displayStatus_Label_2->setText(QApplication::translate("CvSystemClass", "RGB\345\233\276\345\203\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("CvSystemClass", "\350\247\206\351\242\221\350\276\223\345\205\245\357\274\210\345\211\257\346\221\204\357\274\211", Q_NULLPTR));
        videoLabel_2->setText(QApplication::translate("CvSystemClass", "\350\247\206\351\242\221\350\276\223\345\205\245", Q_NULLPTR));
        label_X->setText(QApplication::translate("CvSystemClass", "0", Q_NULLPTR));
        label_Z->setText(QApplication::translate("CvSystemClass", "0", Q_NULLPTR));
        label_A->setText(QApplication::translate("CvSystemClass", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("CvSystemClass", "X\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_Y->setText(QApplication::translate("CvSystemClass", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("CvSystemClass", "Y\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("CvSystemClass", "Z\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("CvSystemClass", "A\345\201\217\350\247\222\357\274\232", Q_NULLPTR));
        label_A_2->setText(QApplication::translate("CvSystemClass", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("CvSystemClass", "B\345\201\217\350\247\222\357\274\232", Q_NULLPTR));
        capType_comboBox->clear();
        capType_comboBox->insertItems(0, QStringList()
         << QApplication::translate("CvSystemClass", "\346\274\224\347\244\272\350\247\206\351\242\221", Q_NULLPTR)
         << QApplication::translate("CvSystemClass", "\346\221\204\345\203\217\345\244\2641", Q_NULLPTR)
        );
        matchType_Label->setText(QApplication::translate("CvSystemClass", "\345\214\271\351\205\215\347\256\227\346\263\225", Q_NULLPTR));
        capType_comboBox_2->clear();
        capType_comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("CvSystemClass", "\346\227\240\350\276\223\345\205\245", Q_NULLPTR)
         << QApplication::translate("CvSystemClass", "\346\274\224\347\244\272\350\247\206\351\242\221", Q_NULLPTR)
         << QApplication::translate("CvSystemClass", "\346\221\204\345\203\217\345\244\2642", Q_NULLPTR)
        );
        detectionFrame_Label_2->setText(QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\346\243\200\346\265\213", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\346\243\200\346\265\213", Q_NULLPTR));
        matchFrame_Label_2->setText(QApplication::translate("CvSystemClass", "\347\211\271\345\276\201\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("CvSystemClass", "\347\211\271\345\276\201\347\202\271\346\217\220\345\217\226", Q_NULLPTR));
        rightFrame_Label_2->setText(QApplication::translate("CvSystemClass", "\345\217\263\346\221\204\345\203\217\345\244\264\345\233\276\345\203\217", Q_NULLPTR));
        leftFrame_Label_2->setText(QApplication::translate("CvSystemClass", "\345\267\246\346\221\204\345\203\217\345\244\264\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("CvSystemClass", "\345\267\246\345\217\263\345\233\276\345\203\217\345\210\206\345\211\262", Q_NULLPTR));
        label_8->setText(QApplication::translate("CvSystemClass", "\351\233\206\350\243\205\347\256\261\346\211\255\351\224\201\350\247\206\350\247\211\350\257\206\345\210\253\347\263\273\347\273\237 v2.0", Q_NULLPTR));
        logName_Label->setText(QApplication::translate("CvSystemClass", "\350\277\220\350\241\214\346\227\245\345\277\227", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CvSystemClass", "\346\234\272\346\242\260\350\207\202\347\212\266\346\200\201", Q_NULLPTR));
        label_9->setText(QApplication::translate("CvSystemClass", "\351\200\232\344\277\241\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_11->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2021\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_13->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2022\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_15->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2023\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_17->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_18->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2025\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2026\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_21->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_22->setText(QApplication::translate("CvSystemClass", "\345\205\263\350\212\2024\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_24->setText(QApplication::translate("CvSystemClass", "\346\260\224\351\230\2002\357\274\232", Q_NULLPTR));
        label_25->setText(QApplication::translate("CvSystemClass", "\346\260\224\351\230\2003\357\274\232", Q_NULLPTR));
        label_26->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_27->setText(QApplication::translate("CvSystemClass", "none", Q_NULLPTR));
        label_28->setText(QApplication::translate("CvSystemClass", "\346\260\224\351\230\2001\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CvSystemClass", "\345\237\272\346\234\254\346\223\215\344\275\234", Q_NULLPTR));
        display_Button->setText(QApplication::translate("CvSystemClass", "\350\247\206\351\242\221\345\257\274\345\205\245", Q_NULLPTR));
        start_Button->setText(QApplication::translate("CvSystemClass", "\345\233\276\345\203\217\346\217\220\345\217\226", Q_NULLPTR));
        stop_Button->setText(QApplication::translate("CvSystemClass", "\345\201\234\346\255\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\350\267\235\347\246\273", Q_NULLPTR));
        distance_label_1->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_30->setText(QApplication::translate("CvSystemClass", "mm", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("CvSystemClass", "\347\233\256\346\240\207\350\267\235\347\246\273", Q_NULLPTR));
        distance_label_2->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_35->setText(QApplication::translate("CvSystemClass", "mm", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("CvSystemClass", "\346\243\200\346\265\213\344\277\241\346\201\257", Q_NULLPTR));
        cenx_label_1->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_31->setText(QApplication::translate("CvSystemClass", "x1", Q_NULLPTR));
        ceny_label_1->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_32->setText(QApplication::translate("CvSystemClass", "y1", Q_NULLPTR));
        angle_label_1->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_33->setText(QApplication::translate("CvSystemClass", "a1", Q_NULLPTR));
        label_34->setText(QApplication::translate("CvSystemClass", "n", Q_NULLPTR));
        feaNum_label_1->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("CvSystemClass", "\346\243\200\346\265\213\344\277\241\346\201\257", Q_NULLPTR));
        cenx_label_2->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_38->setText(QApplication::translate("CvSystemClass", "x1", Q_NULLPTR));
        ceny_label_2->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_39->setText(QApplication::translate("CvSystemClass", "y1", Q_NULLPTR));
        angle_label_2->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        label_40->setText(QApplication::translate("CvSystemClass", "a1", Q_NULLPTR));
        label_36->setText(QApplication::translate("CvSystemClass", "n", Q_NULLPTR));
        feaNum_label_2->setText(QApplication::translate("CvSystemClass", "-1", Q_NULLPTR));
        menu->setTitle(QApplication::translate("CvSystemClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("CvSystemClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CvSystemClass: public Ui_CvSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVSYSTEM_H
