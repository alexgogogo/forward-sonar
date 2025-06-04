/********************************************************************************
** Form generated from reading UI file 'ColorValueSetDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORVALUESETDLG_H
#define UI_COLORVALUESETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ColorValueSetDlg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *minVal;
    QLineEdit *maxVal;
    QPushButton *onOK;
    QPushButton *onCancel;

    void setupUi(QDialog *ColorValueSetDlg)
    {
        if (ColorValueSetDlg->objectName().isEmpty())
            ColorValueSetDlg->setObjectName(QString::fromUtf8("ColorValueSetDlg"));
        ColorValueSetDlg->resize(380, 190);
        ColorValueSetDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 214, 241);"));
        label = new QLabel(ColorValueSetDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(25, 25, 231, 16));
        label_2 = new QLabel(ColorValueSetDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(65, 65, 72, 15));
        label_3 = new QLabel(ColorValueSetDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(65, 100, 72, 15));
        minVal = new QLineEdit(ColorValueSetDlg);
        minVal->setObjectName(QString::fromUtf8("minVal"));
        minVal->setGeometry(QRect(160, 60, 113, 21));
        minVal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        maxVal = new QLineEdit(ColorValueSetDlg);
        maxVal->setObjectName(QString::fromUtf8("maxVal"));
        maxVal->setGeometry(QRect(160, 100, 113, 21));
        maxVal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        onOK = new QPushButton(ColorValueSetDlg);
        onOK->setObjectName(QString::fromUtf8("onOK"));
        onOK->setGeometry(QRect(90, 150, 93, 28));
        onCancel = new QPushButton(ColorValueSetDlg);
        onCancel->setObjectName(QString::fromUtf8("onCancel"));
        onCancel->setGeometry(QRect(190, 150, 93, 28));

        retranslateUi(ColorValueSetDlg);

        QMetaObject::connectSlotsByName(ColorValueSetDlg);
    } // setupUi

    void retranslateUi(QDialog *ColorValueSetDlg)
    {
        ColorValueSetDlg->setWindowTitle(QCoreApplication::translate("ColorValueSetDlg", "\350\211\262\350\260\261\346\225\260\347\273\204\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ColorValueSetDlg", "\350\257\267\350\276\223\345\205\245\350\211\262\350\260\261\345\257\271\345\272\224\347\232\204\346\234\200\345\244\247\346\234\200\345\260\217\346\225\260\345\200\274:", nullptr));
        label_2->setText(QCoreApplication::translate("ColorValueSetDlg", "\346\234\200\345\260\217\345\200\274:", nullptr));
        label_3->setText(QCoreApplication::translate("ColorValueSetDlg", "\346\234\200\345\244\247\345\200\274:", nullptr));
        minVal->setText(QCoreApplication::translate("ColorValueSetDlg", "1e18", nullptr));
        maxVal->setText(QCoreApplication::translate("ColorValueSetDlg", "1e25", nullptr));
        onOK->setText(QCoreApplication::translate("ColorValueSetDlg", "OK", nullptr));
        onCancel->setText(QCoreApplication::translate("ColorValueSetDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorValueSetDlg: public Ui_ColorValueSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORVALUESETDLG_H
