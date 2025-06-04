/********************************************************************************
** Form generated from reading UI file 'FanViewSettingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FANVIEWSETTINGDLG_H
#define UI_FANVIEWSETTINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FanViewSettingDlg
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *colorsel;
    QLabel *ribbon;
    QPushButton *colorValue0;
    QPushButton *colorValue1;
    QPushButton *onOK;
    QPushButton *onCancel;

    void setupUi(QWidget *FanViewSettingDlg)
    {
        if (FanViewSettingDlg->objectName().isEmpty())
            FanViewSettingDlg->setObjectName(QString::fromUtf8("FanViewSettingDlg"));
        FanViewSettingDlg->resize(581, 255);
        FanViewSettingDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 214, 241);"));
        tabWidget = new QTabWidget(FanViewSettingDlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(12, 12, 550, 190));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 214, 241);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 525, 125));
        groupBox->setMaximumSize(QSize(525, 125));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 72, 51));
        colorsel = new QComboBox(groupBox);
        colorsel->addItem(QString());
        colorsel->addItem(QString());
        colorsel->setObjectName(QString::fromUtf8("colorsel"));
        colorsel->setEnabled(true);
        colorsel->setGeometry(QRect(110, 30, 145, 22));
        colorsel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        ribbon = new QLabel(groupBox);
        ribbon->setObjectName(QString::fromUtf8("ribbon"));
        ribbon->setGeometry(QRect(110, 70, 310, 25));
        ribbon->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 blue,stop:0.25 aqua, stop:0.5 lime,stop:0.75 yellow, stop:1 red);\n"
"}"));
        colorValue0 = new QPushButton(groupBox);
        colorValue0->setObjectName(QString::fromUtf8("colorValue0"));
        colorValue0->setGeometry(QRect(40, 70, 60, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        colorValue0->setFont(font);
        colorValue0->setStyleSheet(QString::fromUtf8("QPushButton#colorValue0 {\n"
"background-color: rgb(0, 0, 255);\n"
"}"));
        colorValue1 = new QPushButton(groupBox);
        colorValue1->setObjectName(QString::fromUtf8("colorValue1"));
        colorValue1->setGeometry(QRect(430, 70, 60, 25));
        colorValue1->setFont(font);
        colorValue1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        tabWidget->addTab(tab, QString());
        onOK = new QPushButton(FanViewSettingDlg);
        onOK->setObjectName(QString::fromUtf8("onOK"));
        onOK->setGeometry(QRect(130, 210, 93, 28));
        onOK->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 214, 241);\n"
""));
        onCancel = new QPushButton(FanViewSettingDlg);
        onCancel->setObjectName(QString::fromUtf8("onCancel"));
        onCancel->setGeometry(QRect(330, 210, 93, 28));

        retranslateUi(FanViewSettingDlg);

        tabWidget->setCurrentIndex(0);
        colorsel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FanViewSettingDlg);
    } // setupUi

    void retranslateUi(QWidget *FanViewSettingDlg)
    {
        FanViewSettingDlg->setWindowTitle(QCoreApplication::translate("FanViewSettingDlg", "Display Setting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FanViewSettingDlg", "\351\242\234\350\211\262\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("FanViewSettingDlg", "\351\242\234\350\211\262\347\261\273\345\236\213:", nullptr));
        colorsel->setItemText(0, QCoreApplication::translate("FanViewSettingDlg", "\347\272\242\350\223\235\350\211\262\347\263\273", nullptr));
        colorsel->setItemText(1, QCoreApplication::translate("FanViewSettingDlg", "\347\201\260\350\211\262\347\263\273", nullptr));

        colorsel->setCurrentText(QCoreApplication::translate("FanViewSettingDlg", "\347\272\242\350\223\235\350\211\262\347\263\273", nullptr));
        ribbon->setText(QString());
        colorValue0->setText(QCoreApplication::translate("FanViewSettingDlg", "1e+018", nullptr));
        colorValue1->setText(QCoreApplication::translate("FanViewSettingDlg", "1e+025", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FanViewSettingDlg", "\344\270\273\350\247\206\345\233\276", nullptr));
        onOK->setText(QCoreApplication::translate("FanViewSettingDlg", "\347\241\256\345\256\232", nullptr));
        onCancel->setText(QCoreApplication::translate("FanViewSettingDlg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FanViewSettingDlg: public Ui_FanViewSettingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANVIEWSETTINGDLG_H
