#include "ColorValueSetDlg.h"
#include "ui_ColorValueSetDlg.h"
#include "ui_FanViewSettingDlg.h"
#include "mainwindow.h"
#include <QString>
#include <QErrorMessage>
#include <QDebug>

extern MainWindow *m_window;

ColorValueSetDlg::ColorValueSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorValueSetDlg)
{
    ui->setupUi(this);

    connect(ui->onOK, &QPushButton::clicked, [=](){
        if(OnOK())
            this->close();
    });

    connect(ui->onCancel, &QPushButton::clicked, [=](){
        this->close();
    });
}

ColorValueSetDlg::~ColorValueSetDlg()
{
    delete ui;
}

bool ColorValueSetDlg::OnOK()
{
    m_colorValue0 = ui->minVal->text().toFloat();
    m_colorValue1 = ui->maxVal->text().toFloat();

    if(m_colorValue0 < 0 || m_colorValue1 < 0 || m_colorValue1 <= m_colorValue0) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("错误：数值必须大于0，且最大值必须大于最小值");;

        if(m_colorValue0 < 0)
            ui->minVal->setText(0);
        if(m_colorValue1 < 0)
            ui->maxVal->setText(0);
        if(m_colorValue1 <= m_colorValue0)
            ui->maxVal->setText(QString::number(m_colorValue0*10));

        return false;
    }
    m_window->dlg->valueBack0 = m_colorValue0;
    m_window->dlg->valueBack1 = m_colorValue1;
    ui->minVal->setText(QString::number(m_colorValue0));
    ui->maxVal->setText(QString::number(m_colorValue1));
    m_window->dlg->ui->colorValue0->setText(QString::number(m_colorValue0));
    m_window->dlg->ui->colorValue1->setText(QString::number(m_colorValue1));

    return true;
}



