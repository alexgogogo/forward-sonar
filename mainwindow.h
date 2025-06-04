#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QThread>
#include <QMouseEvent>
#include "CommonDefs.h"
//#include <myopenglwidget.h>
#include "dataacquisition.h"
#include "FanViewSettingDlg.h"
#include "CmdThread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Init();    //初始化按钮

    void DrawScene();         //绘图

    void onStart();         //根据当前运行模式绘图

    void StartSonar();      //声呐启动

    void StopSonar();



public:
    Ui::MainWindow *ui;

    QString filePath = NULL;

    ParsingFile *pf = NULL;

    FanViewSettingDlg *dlg = NULL;

    CmdThread *m_CmdThread;

    int m_operMode = 1;     // 1为实时模式，2为回放模式

    DataAcquisition *fData;

    bool m_isPaused;

    bool m_isStarted = false;

    int flag = 0;

    bool m_sonarconnected = false;  //声呐连接状态

    QString m_sonarip;
    QString m_dispPCip;

    QThread *read_thread = NULL;    //读文件线程

    QThread *reject_thread = NULL;    //读文件线程

    QThread *thread1 = NULL;   //进度条线程

private slots:
    void on_Start_clicked();

    void on_Pause_clicked();

    void on_Stop_clicked();

    void on_LastPing_clicked();

    void on_NextPing_clicked();

    void on_OpenRecord_clicked();

    void OnBnClickedStart();

    void OnBnClickedStop();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalScrollBar_valueChanged(int value);

    void onIndexChanged(int index);

    void on_tabWidget_currentChanged(int index);

    void on_button_start_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:

};
#endif // MAINWINDOW_H
