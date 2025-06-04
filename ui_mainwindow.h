/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *m_collet;
    QAction *m_replay;
    QAction *m_exit;
    QAction *m_colorSet;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    MyOpenGLWidget *openGLWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QScrollBar *horizontalScrollBar;
    QLabel *label_4;
    QLineEdit *edit_range;
    QLabel *label_meter;
    QCheckBox *checkBox_fps;
    QLineEdit *edit_fps;
    QLabel *label_fps;
    QPushButton *button_start;
    QPushButton *button_stop;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QScrollBar *hScrollBar_pulse;
    QLabel *label_gain;
    QScrollBar *hScrollBar_gain;
    QLineEdit *edit_pulse;
    QLineEdit *edit_gain;
    QLabel *label_9;
    QLabel *label_10;
    QGroupBox *groupBox_5;
    QLabel *label_threshold;
    QScrollBar *hScrollBar_threshold;
    QLineEdit *edit_threshold;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QGroupBox *groupBox_4;
    QLabel *label_13;
    QLineEdit *lineEdit6;
    QPushButton *pushButton_3;
    QLabel *label_14;
    QLineEdit *lineEdit7;
    QLabel *label_15;
    QLineEdit *lineEdit8;
    QLabel *label_3;
    QWidget *tab_3;
    QGroupBox *groupBox_6;
    QLabel *label_2;
    QLineEdit *m_dataFileName;
    QPushButton *m_btOpenFile;
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *m_btStart;
    QPushButton *m_btPause;
    QPushButton *m_btLastPing;
    QPushButton *m_btNextPing;
    QPushButton *m_btStop;
    QLabel *label_16;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_C;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1322, 817);
        MainWindow->setMinimumSize(QSize(1030, 760));
        m_collet = new QAction(MainWindow);
        m_collet->setObjectName(QString::fromUtf8("m_collet"));
        m_collet->setCheckable(true);
        m_collet->setChecked(true);
        QFont font;
        m_collet->setFont(font);
        m_replay = new QAction(MainWindow);
        m_replay->setObjectName(QString::fromUtf8("m_replay"));
        m_replay->setCheckable(true);
        m_replay->setChecked(false);
        m_exit = new QAction(MainWindow);
        m_exit->setObjectName(QString::fromUtf8("m_exit"));
        m_colorSet = new QAction(MainWindow);
        m_colorSet->setObjectName(QString::fromUtf8("m_colorSet"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setEnabled(true);
        widget_2->setMinimumSize(QSize(200, 0));
        widget_2->setMaximumSize(QSize(200, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 0));
        groupBox_2->setMaximumSize(QSize(200, 16777215));

        verticalLayout_5->addWidget(groupBox_2);


        horizontalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new MyOpenGLWidget(widget_5);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout_3->addWidget(openGLWidget);

        tabWidget = new QTabWidget(widget_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setMinimumSize(QSize(0, 200));
        tabWidget->setMaximumSize(QSize(16777215, 200));
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget#tab\n"
"{\n"
"	background-color: rgb(186, 214, 241);\n"
"	\n"
"}\n"
"QWidget#tab_2\n"
"{\n"
"	background-color: rgb(186, 214, 241);\n"
"}\n"
"QWidget#tab_3\n"
"{\n"
"	background-color: rgb(186, 214, 241);\n"
"}\n"
"QWidget#tab_4\n"
"{\n"
"	background-color: rgb(186, 214, 241);\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setEnabled(true);
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 9, 9, 9);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(300, 0));
        groupBox->setMaximumSize(QSize(300, 16777215));
        horizontalScrollBar = new QScrollBar(groupBox);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(100, 40, 85, 21));
        horizontalScrollBar->setMinimumSize(QSize(85, 0));
        horizontalScrollBar->setMaximumSize(QSize(85, 16777215));
        horizontalScrollBar->setMinimum(1);
        horizontalScrollBar->setMaximum(30);
        horizontalScrollBar->setSingleStep(1);
        horizontalScrollBar->setPageStep(1);
        horizontalScrollBar->setValue(10);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 72, 15));
        edit_range = new QLineEdit(groupBox);
        edit_range->setObjectName(QString::fromUtf8("edit_range"));
        edit_range->setGeometry(QRect(210, 40, 51, 21));
        label_meter = new QLabel(groupBox);
        label_meter->setObjectName(QString::fromUtf8("label_meter"));
        label_meter->setGeometry(QRect(270, 40, 21, 16));
        checkBox_fps = new QCheckBox(groupBox);
        checkBox_fps->setObjectName(QString::fromUtf8("checkBox_fps"));
        checkBox_fps->setGeometry(QRect(20, 80, 91, 21));
        edit_fps = new QLineEdit(groupBox);
        edit_fps->setObjectName(QString::fromUtf8("edit_fps"));
        edit_fps->setGeometry(QRect(210, 80, 51, 21));
        label_fps = new QLabel(groupBox);
        label_fps->setObjectName(QString::fromUtf8("label_fps"));
        label_fps->setGeometry(QRect(270, 80, 31, 16));
        button_start = new QPushButton(groupBox);
        button_start->setObjectName(QString::fromUtf8("button_start"));
        button_start->setGeometry(QRect(70, 110, 70, 28));
        button_start->setMaximumSize(QSize(70, 16777215));
        button_stop = new QPushButton(groupBox);
        button_stop->setObjectName(QString::fromUtf8("button_stop"));
        button_stop->setEnabled(false);
        button_stop->setGeometry(QRect(150, 110, 70, 28));
        button_stop->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(groupBox);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(300, 0));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 40, 81, 16));
        hScrollBar_pulse = new QScrollBar(groupBox_3);
        hScrollBar_pulse->setObjectName(QString::fromUtf8("hScrollBar_pulse"));
        hScrollBar_pulse->setGeometry(QRect(100, 40, 85, 21));
        hScrollBar_pulse->setMinimumSize(QSize(85, 0));
        hScrollBar_pulse->setMaximumSize(QSize(85, 16777215));
        hScrollBar_pulse->setOrientation(Qt::Horizontal);
        label_gain = new QLabel(groupBox_3);
        label_gain->setObjectName(QString::fromUtf8("label_gain"));
        label_gain->setGeometry(QRect(20, 80, 81, 16));
        hScrollBar_gain = new QScrollBar(groupBox_3);
        hScrollBar_gain->setObjectName(QString::fromUtf8("hScrollBar_gain"));
        hScrollBar_gain->setGeometry(QRect(100, 80, 85, 21));
        hScrollBar_gain->setMinimumSize(QSize(85, 0));
        hScrollBar_gain->setMaximumSize(QSize(85, 16777215));
        hScrollBar_gain->setOrientation(Qt::Horizontal);
        edit_pulse = new QLineEdit(groupBox_3);
        edit_pulse->setObjectName(QString::fromUtf8("edit_pulse"));
        edit_pulse->setGeometry(QRect(200, 40, 51, 21));
        edit_gain = new QLineEdit(groupBox_3);
        edit_gain->setObjectName(QString::fromUtf8("edit_gain"));
        edit_gain->setGeometry(QRect(200, 80, 51, 21));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(260, 40, 31, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 80, 31, 16));

        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(300, 0));
        groupBox_5->setMaximumSize(QSize(300, 16777215));
        label_threshold = new QLabel(groupBox_5);
        label_threshold->setObjectName(QString::fromUtf8("label_threshold"));
        label_threshold->setGeometry(QRect(20, 40, 81, 16));
        hScrollBar_threshold = new QScrollBar(groupBox_5);
        hScrollBar_threshold->setObjectName(QString::fromUtf8("hScrollBar_threshold"));
        hScrollBar_threshold->setGeometry(QRect(110, 40, 85, 21));
        hScrollBar_threshold->setMinimumSize(QSize(85, 0));
        hScrollBar_threshold->setMaximumSize(QSize(85, 16777215));
        hScrollBar_threshold->setOrientation(Qt::Horizontal);
        edit_threshold = new QLineEdit(groupBox_5);
        edit_threshold->setObjectName(QString::fromUtf8("edit_threshold"));
        edit_threshold->setGeometry(QRect(210, 40, 51, 21));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(270, 40, 31, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(10);
        label_12->setFont(font1);

        horizontalLayout_3->addWidget(groupBox_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 505, 142));
        groupBox_4->setMinimumSize(QSize(505, 142));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 10, 71, 28));
        lineEdit6 = new QLineEdit(groupBox_4);
        lineEdit6->setObjectName(QString::fromUtf8("lineEdit6"));
        lineEdit6->setGeometry(QRect(110, 10, 315, 21));
        lineEdit6->setMinimumSize(QSize(315, 0));
        lineEdit6->setMaximumSize(QSize(315, 16777215));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 10, 45, 28));
        pushButton_3->setMinimumSize(QSize(45, 0));
        pushButton_3->setMaximumSize(QSize(45, 16777215));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 60, 121, 21));
        lineEdit7 = new QLineEdit(groupBox_4);
        lineEdit7->setObjectName(QString::fromUtf8("lineEdit7"));
        lineEdit7->setGeometry(QRect(190, 60, 100, 21));
        lineEdit7->setMinimumSize(QSize(100, 0));
        lineEdit7->setMaximumSize(QSize(100, 16777215));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 100, 151, 21));
        lineEdit8 = new QLineEdit(groupBox_4);
        lineEdit8->setObjectName(QString::fromUtf8("lineEdit8"));
        lineEdit8->setGeometry(QRect(190, 100, 100, 21));
        lineEdit8->setMinimumSize(QSize(100, 0));
        lineEdit8->setMaximumSize(QSize(100, 16777215));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 100, 21, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setEnabled(false);
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 10, 610, 145));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 75, 28));
        m_dataFileName = new QLineEdit(groupBox_6);
        m_dataFileName->setObjectName(QString::fromUtf8("m_dataFileName"));
        m_dataFileName->setEnabled(false);
        m_dataFileName->setGeometry(QRect(130, 10, 360, 28));
        m_dataFileName->setMinimumSize(QSize(360, 28));
        m_dataFileName->setMaximumSize(QSize(360, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(7);
        m_dataFileName->setFont(font2);
        m_dataFileName->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 214, 241);"));
        m_btOpenFile = new QPushButton(groupBox_6);
        m_btOpenFile->setObjectName(QString::fromUtf8("m_btOpenFile"));
        m_btOpenFile->setGeometry(QRect(500, 10, 88, 28));
        m_btOpenFile->setMinimumSize(QSize(88, 28));
        m_btOpenFile->setMaximumSize(QSize(88, 28));
        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 75, 22));
        horizontalSlider = new QSlider(groupBox_6);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(130, 50, 465, 20));
        horizontalSlider->setMinimumSize(QSize(465, 0));
        horizontalSlider->setMaximumSize(QSize(465, 16777215));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        m_btStart = new QPushButton(groupBox_6);
        m_btStart->setObjectName(QString::fromUtf8("m_btStart"));
        m_btStart->setEnabled(false);
        m_btStart->setGeometry(QRect(250, 100, 65, 27));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Agency FB"));
        font3.setPointSize(9);
        m_btStart->setFont(font3);
        m_btPause = new QPushButton(groupBox_6);
        m_btPause->setObjectName(QString::fromUtf8("m_btPause"));
        m_btPause->setEnabled(false);
        m_btPause->setGeometry(QRect(320, 100, 65, 27));
        m_btPause->setFont(font3);
        m_btLastPing = new QPushButton(groupBox_6);
        m_btLastPing->setObjectName(QString::fromUtf8("m_btLastPing"));
        m_btLastPing->setEnabled(false);
        m_btLastPing->setGeometry(QRect(390, 100, 65, 27));
        m_btLastPing->setMaximumSize(QSize(93, 16777215));
        m_btLastPing->setFont(font3);
        m_btNextPing = new QPushButton(groupBox_6);
        m_btNextPing->setObjectName(QString::fromUtf8("m_btNextPing"));
        m_btNextPing->setEnabled(false);
        m_btNextPing->setGeometry(QRect(460, 100, 65, 27));
        m_btNextPing->setFont(font3);
        m_btStop = new QPushButton(groupBox_6);
        m_btStop->setObjectName(QString::fromUtf8("m_btStop"));
        m_btStop->setEnabled(false);
        m_btStop->setGeometry(QRect(530, 100, 65, 27));
        m_btStop->setFont(font3);
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(40, 110, 72, 15));
        comboBox = new QComboBox(groupBox_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 105, 81, 22));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_3->addWidget(tabWidget);


        verticalLayout_2->addWidget(widget_5);


        horizontalLayout->addWidget(widget_4);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1322, 26));
        menubar->setMinimumSize(QSize(0, 25));
        QFont font4;
        font4.setPointSize(9);
        menubar->setFont(font4);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setMinimumSize(QSize(0, 0));
        menu->setMaximumSize(QSize(16777215, 16777215));
        menu->setFont(font4);
        menu_C = new QMenu(menubar);
        menu_C->setObjectName(QString::fromUtf8("menu_C"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_C->menuAction());
        menu->addAction(m_collet);
        menu->addAction(m_replay);
        menu->addAction(m_exit);
        menu_C->addAction(m_colorSet);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\211\215\350\247\206\345\243\260\345\221\220\344\270\212\344\275\215\346\234\272", nullptr));
        m_collet->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\346\250\241\345\274\217\357\274\210O\357\274\211", nullptr));
        m_replay->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\233\236\346\224\276\357\274\210R)", nullptr));
        m_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\357\274\210Q\357\274\211", nullptr));
        m_colorSet->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\256\276\347\275\256(D)", nullptr));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\344\275\234\346\216\247\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\267\245\344\275\234\351\207\217\347\250\213\357\274\232", nullptr));
        edit_range->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_meter->setText(QCoreApplication::translate("MainWindow", "\347\261\263", nullptr));
        checkBox_fps->setText(QCoreApplication::translate("MainWindow", "\345\270\247\347\216\207\351\231\220\345\210\266", nullptr));
        edit_fps->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_fps->setText(QCoreApplication::translate("MainWindow", "fps", nullptr));
        button_start->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        button_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\345\260\204\346\216\245\346\224\266", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\217\221\345\260\204\350\204\211\345\256\275\357\274\232", nullptr));
        label_gain->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\242\236\347\233\212\357\274\232", nullptr));
        edit_pulse->setText(QCoreApplication::translate("MainWindow", "320", nullptr));
        edit_gain->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\276\256\347\247\222", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\346\241\243", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        label_threshold->setText(QCoreApplication::translate("MainWindow", " \346\243\200\346\265\213\351\227\250\351\231\220\357\274\232", nullptr));
        edit_threshold->setText(QCoreApplication::translate("MainWindow", "75", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\243\260\347\272\263\346\216\247\345\210\266", nullptr));
        groupBox_4->setTitle(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\350\256\260\345\275\225\346\226\207\344\273\266\345\220\215\345\211\215\347\274\200\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\350\256\260\345\275\225\346\226\207\344\273\266\345\220\215\345\244\247\345\260\217\344\270\212\351\231\220\357\274\232", nullptr));
        lineEdit8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "GB", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        groupBox_6->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\226\207\344\273\266\357\274\232", nullptr));
        m_btOpenFile->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\233\236\346\224\276\350\277\233\345\272\246\357\274\232", nullptr));
        m_btStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        m_btPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        m_btLastPing->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\345\270\247", nullptr));
        m_btNextPing->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\270\247", nullptr));
        m_btStop->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\345\233\236\346\224\276\351\200\237\345\272\246:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\303\2271", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\303\2272", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\303\2274", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\303\2278", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\303\22716", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\233\236\346\224\276", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "  \345\267\245\344\275\234\346\250\241\345\274\217\357\274\210M\357\274\211", nullptr));
        menu_C->setTitle(QCoreApplication::translate("MainWindow", " \350\256\276\347\275\256\357\274\210C\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
