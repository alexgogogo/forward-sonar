#ifndef DATAACQUISITION_H
#define DATAACQUISITION_H
#include <QString>
#include <QThread>
#include <QVector>
#include <QFile>
#include "parsingfile.h"

class DataAcquisition : public QObject
{
    Q_OBJECT


public:
    explicit DataAcquisition(QObject *parent = nullptr);
    ~DataAcquisition();

    void readDatFile(const QString &filePath);  //读取文件

    void Acquisition();         //实时模式

    void OnDataDecode();        //解码

    void BuildFanImage();       //计算点的位置信息

    void Update_XYGrid();       //更新xy坐标系

    void ReadData();

public:

    char *m_data;

    char *buffer;

    float *m_echo_dat;

    ParsingFile *pf = NULL;

    volatile bool m_isExtractingData = false;   //判断是否在处理数据

    int m_startscan = 0;    //回放的位置

    int m_reply_speed = 1;

    QThread *thread;

    bool m_stop;
    bool m_pause;
    bool m_exitAfterStop;
    bool m_stopped;

    QVector<ULONGLONG> m_headIndex;     //帧从哪个位置开始
    QVector<int> m_packetSize;          //帧的大小
    QVector<double> m_scantimes;
    QVector<UINT32> m_pingNOs;          //第几帧



    int sampleCount;
    int pointNum = 0;

    DisplayData *disp_dat_pre;
    DisplayData *disp_dat0;
    DisplayData *disp_dat1;

    QFile fdata;

    int m_startNewRecording;

signals:
    void can_draw();

    void update();

    void update_range();

    void parseReady();
};

#endif // DATAACQUISITION_H
