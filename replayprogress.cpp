#include "replayprogress.h"
#include "parsingfile.h"
#include "mainwindow.h"
#include <QLabel>
#include <QProgressBar>

extern MainWindow *m_window;
replayProgress::replayProgress()
{
    progressDialog = new QDialog();

    progressDialog->resize(550, 160);
    progressDialog->setWindowTitle("打开回放文件");

    label1 = new QLabel("请稍等,正在载入和解析数据文件");
    label1->setGeometry(158, 27, 240, 25);
    label1->setParent(progressDialog);

    progress = new QProgressBar(progressDialog);
    //progress->resize(455, 25);
    progress->setGeometry(48, 70, 455, 25);
    progress->setRange(0, 100);

    progressDialog->show();
}
