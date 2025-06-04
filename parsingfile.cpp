#include "CommonDefs.h"
#include "dataacquisition.h"
#include "mainwindow.h"
#include "Packet.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QProgressDialog>
#include <QLabel>

extern MainWindow *m_window;

ParsingFile::ParsingFile(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(420, 150);
}

ParsingFile::~ParsingFile()
{
    delete ui;
}

void ParsingFile::ParseThread()
{
    //QProgressDialog progressDialog("Progress Dialog", "Cancel", 0, 100, this);
    //progressDialog.show();
    //progressDialog.close();

//


    //ParsingFile *dlg_parse = new ParsingFile();
    BeamPacket data_hd;
    char *buf = new char[DATA_PACKETSIZE];
    //char *buf2 = new char[DATA_PACKETSIZE];
    u32 img_num = 16;    //图像号、小帧号、波束数
    //u32 Frame_ind = 0;
    //u32 Beam_Ind = 0;
    u32 pingNo = 0;     //第几帧数
    bool image_start = false;   //第一幅图
    ULONGLONG headIndex = 4;

    int n = 0;  //测试

    qDebug() << "---------- 开始解析回放文件 ----------";

    QFile file(filePath);
    QDataStream aStream(&file);

    //qDebug() << filePath;
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件";
        return;
    }
    QFileInfo info(filePath);
    len_Datafile = file.size();


    QByteArray buffer;
    char buff;

    int i = 0;
    qDebug() << "文件的大小为" + QString::number(len_Datafile);

    m_window->m_isStarted = false;

    pingNo = 0;

    while (file.pos() <= len_Datafile - DATA_PACKETSIZE) {
        i ++;
        //qDebug() << "当前读取位置" << file.pos();

        file.read(buf, DATA_PACKETSIZE);

        if(*((u16*)(buf)) == DATA_HEAD && *((u16*)(buf + 32772)) == DATA_TAIL) {
            //qDebug() << "当前读取位置:" << file.pos();
            image_start = true;

            BeamData* pBeamData = (BeamData*)buf;
            //BeamPacket* pPacket;

            int frame_size = -1;

            for(int j = 4; j < DATA_PACKETSIZE - 2; j += 8) {
                pBeamData = (BeamData*)(buf + j);   //隔8位取一个

                // 当前帧图像已结束
                if(img_num != pBeamData->getImgNum() && img_num != 16) {

                    frame_size = file.pos() - DATA_PACKETSIZE + j - headIndex;
                    data_hd.frame_size = frame_size;
                    data_hd.pingNo = ++pingNo;
                    img_num = pBeamData->getImgNum();

                    m_window->fData->m_headIndex.push_back(headIndex);
                    //qDebug() << "head是对的";
                    m_window->fData->m_packetSize.push_back(data_hd.frame_size);
                    m_window->fData->m_pingNOs.push_back(data_hd.pingNo);

                    qDebug() << "头结点" << headIndex << " 帧的长度" << data_hd.frame_size << " pingNo：" << data_hd.pingNo;
                    headIndex = file.pos() - DATA_PACKETSIZE + j;
                }
                img_num = pBeamData->getImgNum();
            }
        }
        else {
            qDebug() << "帧首尾格式错误, 当前文件位置" + QString::number(file.pos());
        }


        memset(buf, 0, sizeof(buf));

        progress = (file.pos() * 100) / len_Datafile;     //进度条进度
        emit progressUpdate();
        //ui->progressBar->setValue(progress);
    }
    qDebug()<<"进度条加载完毕";
    data_hd.frame_size = file.pos() - headIndex;
    data_hd.pingNo = ++pingNo;
    m_window->fData->m_headIndex.push_back(headIndex);
    m_window->fData->m_packetSize.push_back(data_hd.frame_size);
    m_window->fData->m_pingNOs.push_back(data_hd.pingNo);

    qDebug() << "头结点" << headIndex << " 帧的长度" << data_hd.frame_size << " pingNo：" << data_hd.pingNo;



    file.close();
    //this->hide();
    //this->close();
}
