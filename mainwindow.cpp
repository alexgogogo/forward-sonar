#include "mainwindow.h"
#include "dataacquisition.h"
#include "FanViewSettingDlg.h"
#include "./ui_mainwindow.h"

#include <QToolBar>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QAction>
#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimediaWidgets/QVideoWidget>
//#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QOpenGLWidget>
#include <QElapsedTimer>



MainWindow* m_window;
extern QSemaphore Sem_ReplayCtrl;   //回放信号,用于实现暂停，开始
extern QSemaphore Sem_ThreadStop;   //实现回放线程的暂停和恢复

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
    read_thread->deleteLater();
    reject_thread->deleteLater();
}

void MainWindow::Init()
{
    m_window = this;

    m_sonarip = "10.12.13.118";
    m_dispPCip = "10.12.13.120";

    connect(ui->m_btOpenFile, SIGNAL(clicked()), this, SLOT(on_OpenRecord_clicked()));
    connect(ui->m_btStart, SIGNAL(clicked()), this, SLOT(on_Start_clicked()));
    connect(ui->m_btPause, SIGNAL(clicked()), this, SLOT(on_Pause_clicked()));
    connect(ui->m_btStop, SIGNAL(clicked()), this, SLOT(on_Stop_clicked()));
    connect(ui->m_btLastPing, SIGNAL(clicked()), this, SLOT(on_LastPing_clicked()));
    connect(ui->m_btNextPing, SIGNAL(clicked()), this, SLOT(on_NextPing_clicked()));
    connect(ui->button_start, SIGNAL(clicked()), this, SLOT(OnBnClickedStart()));

    connect(ui->button_stop, SIGNAL(clicked()), this, SLOT(OnBnClickedStop()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)));

    fData = new DataAcquisition;
    read_thread = new QThread;
    fData->moveToThread(read_thread);
    m_CmdThread = new CmdThread();
    reject_thread = new QThread;
    m_CmdThread->moveToThread(reject_thread);

    dlg = new FanViewSettingDlg();

    connect(read_thread, &QThread::finished, fData, &DataAcquisition::deleteLater);
    connect(read_thread, &QThread::started, fData, [=](){
        while(1) {
            fData->readDatFile(filePath);
            if(fData->m_startscan >= fData->m_packetSize.size())    //播放完毕
                on_Stop_clicked();
            Sleep(10);
        }
    });
    connect(reject_thread, &QThread::finished, m_CmdThread, &CmdThread::deleteLater);
    connect(reject_thread, &QThread::started, m_CmdThread, [=](){
        m_CmdThread->OnStartSonar();
        fData->Acquisition();
    });

    connect(fData, &DataAcquisition::update, [=](){     //更新进度条
        qDebug() << fData->m_packetSize.size();
        ui->horizontalSlider->setRange(0, fData->m_packetSize.size() - 1);
    });

    connect(fData, &DataAcquisition::can_draw, [=](){
        //qDebug() << "画图咯!";
        //ui->horizontalSlider->setValue(fData->m_startscan);
        if(fData->m_pause == false)
            ui->horizontalSlider->setSliderPosition(fData->m_startscan);
        ui->openGLWidget->m_disp_dat = fData->disp_dat_pre;
        ui->openGLWidget->ready = true;
        ui->openGLWidget->frame ++;       //会被屏幕刷新率给限制
        ui->openGLWidget->pingNo = fData->m_startscan;
        ui->openGLWidget->update();       //更新画面

        QElapsedTimer timer;
        timer.start();//开始计时
    });

    connect(fData, &DataAcquisition::update_range, [=](){
        ui->openGLWidget->m_range = fData->sampleCount / 1650 * 50;
    });

    connect(ui->m_colorSet, &QAction::triggered, [=](){
       dlg->show();
    });

    connect(ui->m_collet, &QAction::triggered, [=](){
        ui->m_replay->setChecked(false);
        ui->m_collet->setChecked(true);
        m_operMode = 1;
        ui->tabWidget->setCurrentIndex(0);
        ui->tab->setEnabled(true);
        ui->tab_2->setEnabled(true);
        ui->tab_3->setEnabled(false);
    });
    connect(ui->m_replay, &QAction::triggered, [=](){
        ui->m_collet->setChecked(false);
        ui->m_replay->setChecked(true);
        m_operMode = 2;
        ui->tabWidget->setCurrentIndex(2);
        ui->tab->setEnabled(false);
        ui->tab_2->setEnabled(false);
        ui->tab_3->setEnabled(true);
    });
}

void MainWindow::onStart()
{
    if (m_operMode == 1)
    {
        reject_thread->start();
        //AfxBeginThread(AcquisitionThread,0,THREAD_PRIORITY_HIGHEST);		//实时
    }
    else if(m_operMode == 2)
    {
        qDebug() << "thread->start()";

        if(read_thread->isRunning())
            Sem_ThreadStop.release();   //恢复线程
        read_thread->start();

        Sleep(10);
        // AfxBeginThread(DataReadThread,0,THREAD_PRIORITY_HIGHEST);		//回放
        //
    }
}



/*  回放相关控件
*/
void MainWindow::on_Start_clicked()
{
    if(m_operMode == 0 || m_operMode == 1)
        return;

    if(!m_isStarted) { //第一次点击
        m_isStarted = true;
        ui->m_btPause->setEnabled(true);
        ui->m_btStart->setEnabled(false);
        ui->m_btStop->setEnabled(true);
        ui->m_btOpenFile->setEnabled(false);
        m_isPaused=false;
        onStart();
    }
    else if(m_isPaused) {      //开始
        //actionPlay->setIcon(QIcon(":/res/resultset_last.png"));
        fData->m_pause = false;
        m_isPaused=false;
        ui->m_btPause->setEnabled(true);
        ui->m_btStart->setEnabled(false);
        ui->m_btLastPing->setEnabled(false);
        ui->m_btNextPing->setEnabled(false);
        Sem_ReplayCtrl.release(2);
    }
}

void MainWindow::on_Pause_clicked()
{
    if(m_operMode == 0 || m_operMode == 1)
        return;

    if(m_isStarted) {
        Sem_ReplayCtrl.acquire(1);
        fData->m_pause = true;
        Sleep(10);
        m_isPaused=true;
        ui->m_btPause->setEnabled(false);
        ui->m_btStart->setEnabled(true);
        ui->m_btLastPing->setEnabled(true);
        ui->m_btNextPing->setEnabled(true);
    }
}

void MainWindow::on_Stop_clicked()
{
    qDebug() << "size:" << fData->m_headIndex.size();

    ui->m_btOpenFile->setEnabled(true);
    fData->m_pause = false;
    m_isStarted = false;
    if(m_isPaused)
        Sem_ReplayCtrl.release(2);      //1

    fData->m_stop = true;
    Sem_ThreadStop.acquire();

    ui->m_btPause->setEnabled(false);
    ui->m_btStart->setEnabled(true);
    ui->m_btLastPing->setEnabled(false);
    ui->m_btNextPing->setEnabled(false);
    ui->m_btStop->setEnabled(false);
    ui->horizontalSlider->setValue(0);
    fData->m_startscan = 0;
    fData->m_reply_speed = 1;

    qDebug() << "size:" << fData->m_headIndex.size();
}

void MainWindow::on_LastPing_clicked()
{
    if(!m_isPaused || m_operMode != 2)
        return;

    fData->m_startscan -= 2;
    if(fData->m_startscan < 0)  fData->m_startscan = 0;
    fData->m_pause = true;
    ui->horizontalSlider->setSliderPosition(fData->m_startscan);
    Sem_ReplayCtrl.release();
}

void MainWindow::on_NextPing_clicked()
{
    if(!m_isPaused || m_operMode != 2)
        return;

    fData->m_pause = true;
    ui->horizontalSlider->setSliderPosition(fData->m_startscan);
    Sem_ReplayCtrl.release();
}

void MainWindow::on_OpenRecord_clicked()
{
    m_isStarted=false;
    qDebug() << "开始打开回放文件";
    qDebug() << "size:" << fData->m_headIndex.size();
    if(pf != NULL) {
        delete pf;
        pf = NULL;
    }
    if(thread1 != NULL) {
        thread1->quit();
        thread1->wait();
        delete thread1;
        thread1 = NULL;
    }

    qDebug() << "size:" << fData->m_headIndex.size();
    fData->m_headIndex.clear();
    fData->m_packetSize.clear();
    fData->m_pingNOs.clear();

    m_operMode = 2;
    filePath = QFileDialog::getOpenFileName(this, "打开文件");

    if(filePath == "")
        return;

    pf = new ParsingFile();
    replayProgress *rp = new replayProgress();

    thread1 = new QThread;
    pf->moveToThread(thread1);

    connect(pf, &ParsingFile::progressUpdate, [=](){
        rp->progress->setValue(pf->progress);
        if(pf->progress == 100) {
            rp->progressDialog->close();
            ui->horizontalSlider->setRange(0, fData->m_packetSize.size() - 1);
            delete rp;
//            delete rp->progressDialog;
//            delete rp->label1;
//            delete rp->progress;
            thread1->exit();
        }
    });

    connect(thread1, &QThread::started, pf, [=](){
        qDebug() << "显示进度条";
        pf->ParseThread();
    });
    thread1->start();

    //pf->moveToThread(thread);
    //connect(thread, &QThread::finished, pf, ParsingFile::deleteLater);

    pf->filePath = filePath;
    //pf->show();       //两个界面都会卡死

    //暂时放这
    ui->m_dataFileName->setText(filePath);
    ui->m_btStart->setEnabled(true);
}



/*  实时相关控件
*/
void MainWindow::OnBnClickedStart()
{
    if (!m_isStarted)
    {
        m_isStarted=true;

        StartSonar();

        ui->button_start->setEnabled(false);
        ui->button_stop->setEnabled(true);
    }
}

void MainWindow::OnBnClickedStop()
{
    if (m_isStarted)
    {
        m_isStarted=false;

        ui->button_start->setEnabled(true);
        ui->button_stop->setEnabled(false);
    }
}

void MainWindow::StartSonar()
{
    if (m_CmdThread==NULL) return;
    if (!m_sonarconnected) return;
    fData->m_startNewRecording=true;

    m_operMode = 1;
    onStart();
}

void MainWindow::StopSonar()
{

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    fData->m_startscan = value;
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    qDebug() << "value:" << value;
    ui->openGLWidget->m_range = ui->horizontalScrollBar->value() * 5;
    ui->edit_range->setText(QString::number(ui->horizontalScrollBar->value() * 5));
    ui->openGLWidget->update();
}

void MainWindow::onIndexChanged(int index) {
    switch (index) {
    case 0:
        fData->m_reply_speed = 1;
        break;
    case 1:
        fData->m_reply_speed = 2;
        break;
    case 2:
        fData->m_reply_speed = 4;
        break;
    case 3:
        fData->m_reply_speed = 8;
        break;
    case 4:
        fData->m_reply_speed = 16;
        break;
    default:
        break;
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(m_operMode == 1) {
        if(index == 2)
            ui->tabWidget->setCurrentIndex(0);

            return;
    }
    else if(m_operMode == 2) {
        if(index == 0 || index == 1)
            ui->tabWidget->setCurrentIndex(2);
            return;
    }
}


