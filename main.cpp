#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //if(QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    //   qputenv("QT_SCALE_FACTOR", "0.8");      // qt6有高dpi，会扩大为1.25倍

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
