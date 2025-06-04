#include "FanViewSettingDlg.h"
#include "ui_FanViewSettingDlg.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLinearGradient>
#include <QDialog>
#include <QLabel>
#include <QPainter>

extern MainWindow *m_window;

FanViewSettingDlg::FanViewSettingDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FanViewSettingDlg)
{
    ui->setupUi(this);
    dlg = new ColorValueSetDlg();

    connect(ui->colorValue0, &QPushButton::clicked, [=](){
        colorSet();
    });
    connect(ui->colorValue1, &QPushButton::clicked, [=](){
        colorSet();
    });
    connect(ui->onOK, &QPushButton::clicked, [=](){
        m_window->ui->openGLWidget->m_colorValue0 = valueBack0;
        m_window->ui->openGLWidget->m_colorValue1 = valueBack1;
        m_window->ui->openGLWidget->m_colorsel = ui->colorsel->currentIndex();
        m_window->ui->openGLWidget->UpdateColormap();
        this->close();
    });
    connect(ui->onCancel, &QPushButton::clicked, [=](){
        this->close();
    });
}

FanViewSettingDlg::~FanViewSettingDlg()
{
    delete ui;
}

void FanViewSettingDlg::colorSet() {
    //ColorValueSetDlg *dlg = new ColorValueSetDlg();

    dlg->show();
    valueBack0 = dlg->m_colorValue0;
    valueBack1 = dlg->m_colorValue1;
}

void FanViewSettingDlg::paintEvent(QPaintEvent *event)
{

}

void FanViewSettingDlg::on_colorsel_currentIndexChanged(int index)
{
    if(index == 0) {
        ui->colorValue0->setStyleSheet("background-color: blue;");
        ui->colorValue1->setStyleSheet("background-color: red;");
        ui->ribbon->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                  " stop:0 blue,stop:0.25 aqua, stop:0.5 lime,stop:0.75 yellow,"
                                  " stop:1 red);");
    }
    else if(index == 1) {
        ui->colorValue0->setStyleSheet("background-color: black;");
        ui->colorValue1->setStyleSheet("background-color: white;");
        ui->ribbon->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                  " stop:0 black, stop:1 white);");
    }
}
