#include "dataacquisition.h"
#include "CommonDefs.h"
#include "Packet.h"
#include "myopenglwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QThread>
#include <QtMath>
#include <QSemaphore>

UINT16 points_counts[IMAG_ANG_NUM][IMAG_SIZE];
float points_x[IMAG_ANG_NUM][IMAG_SIZE];
float points_z[IMAG_ANG_NUM][IMAG_SIZE];
float x[IMAG_ANG_NUM][MAX_SAMPLE_NUM];
float y[IMAG_ANG_NUM][MAX_SAMPLE_NUM];
extern int ready;

QSemaphore Sem_ReplayCtrl(1);
QSemaphore Sem_ThreadStop(1);
extern MainWindow *m_window;

DataAcquisition::DataAcquisition(QObject *parent): QObject{parent}
{
    m_echo_dat = new float[MAX_BEAM_NUM * MAX_SAMPLE_NUM];
    m_startscan = 0;

    m_stop = false;
    m_pause = false;
    m_exitAfterStop = false;
    m_stopped = false;
    m_reply_speed = 1;

    disp_dat0 = new DisplayData;
    disp_dat1 = new DisplayData;
    disp_dat_pre = disp_dat0;

    Update_XYGrid();
}

DataAcquisition::~DataAcquisition()
{

}

// DataAcquisition::DataAcquisition() {


// }

//QFile fdata;
int flag;   //控制回放数据的测量距离
void DataAcquisition::readDatFile(const QString &path) {

    //u8 *buffer;

    Sem_ThreadStop.acquire();

    qDebug() << "---------- 开始读取回放文件 ----------";
    qDebug() << path;
    fdata.setFileName(path);
    flag = 0;

    if (!fdata.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件";
        return;
    }

    m_stop = false; //测试

    ReadData();

    Sem_ThreadStop.release();
    Sleep(10);      //不能删
}

void DataAcquisition::Acquisition()
{

}

void DataAcquisition::ReadData()
{
    qDebug() << "---------- 开始播放视频 ----------";
    qDebug() << QString::number(m_startscan) + " " + QString::number(m_headIndex.size());
    buffer = new char[MAX_PACKET_SIZE];
    qDebug() << "m_headIndex:" << m_headIndex.size();
    while (m_startscan < m_headIndex.size())
    {
        //qDebug() << "---------- 开始播放视频m_startscan ----------";
        if (m_stop) break;

        while(m_isExtractingData)
        {
            QThread::sleep(10);
        }
        //Sleep(1);   //图像闪烁

        fdata.seek(m_headIndex[m_startscan]);
        fdata.read(buffer, m_packetSize[m_startscan]);

        if (!m_exitAfterStop)
        {
            m_isExtractingData=true;
            //编译画图
            OnDataDecode();
            //PostThreadMessage(ON_DATA_DECODE,m_startscan,0);

            // if(buffer != NULL) {        //不清理内存会报错内存不够
            //     delete[] buffer;
            //     buffer = NULL;
            // }
        }

        if (m_pause)
        {
            m_pause = false;
            Sem_ReplayCtrl.acquire();   //-1
            m_startscan ++;
            Sleep(10);
        }
        else
        {
            int frameJump = m_reply_speed - 1;

            m_startscan += (1 + frameJump);
        }

    }

    fdata.close();
}

int lastScan = -1;


void DataAcquisition::OnDataDecode()
{
    // if(lastScan == m_startscan)
    //     return;
    // lastScan = m_startscan;

    pointNum = 0;
    float halfSoundspeed = 15000 / 20;

    qDebug() << "---------- 开始文件编译ing ----------";
    if (m_stopped || m_stop)
    {
        m_isExtractingData = false;
        return;
    }
    BeamData *beamData;
    int num_echos = (m_packetSize[m_startscan] - m_packetSize[m_startscan] / DATA_PACKETSIZE) / 8;
    //qDebug() << "点的个数" << num_echos;
    //qDebug() << "当前帧数" << m_startscan;

    //qDebug() << buffer;
    beamData = (BeamData*)(buffer + m_packetSize[m_startscan] - 8);     //buffer从head开始读
    //qDebug() << QString::number(pf->m_packetSize[m_startscan] - 8);

    //qDebug() << beamData->intensity;
    int num_beams = MAX_BEAM_NUM;
    sampleCount = beamData->getFrameInd();
    if(sampleCount > 1650 * 3) {
        sampleCount = 1650 * 3;
    }
    else if(sampleCount > 1650 * 2){
        sampleCount = 1650 * 2;
    }
    else if(sampleCount > 1650){
        sampleCount = 1650;
    }

    sampleCount = 1650;   //只显示50m以内

    if(flag == 0) {
        emit update_range();
        flag = 1;
    }


    float* echo_dat = m_echo_dat;
    memset(echo_dat, 0x0, num_beams * sampleCount * sizeof(float));

    int pos = 0;
    qDebug() << "sampleCount" << sampleCount;

    while(pos < m_packetSize[m_startscan]) {
        if(*((u16*)(buffer + pos)) == 0x0A0D && *((u16*)(buffer + pos + 2)) == DATA_HEAD) {          //有点小问题
            //qDebug() << "当前结果" + QString::number(*((u16*)(buffer + pos)));
            pos += 6;
            continue;
        }
        beamData = (BeamData*)(buffer + pos);

        int i = beamData->getFrameInd();
        int j = beamData->getBeamInd();

        //以下点不符合条件，不画
        if(i >= sampleCount || i >= m_window->ui->openGLWidget->m_range * 1650 / 50 || j >= num_beams || i <= 0 || j <= 0 || beamData->intensity < 0) {
            pos += 8;
            continue;
        }

        echo_dat[i * num_beams + j] = beamData->intensity;

        // 测试
        // qDebug() << "小帧号、波束数分别为" + QString::number(i) + " " + QString::number(j) + "强度" + QString::number(beamData->intensity);

        pointNum ++;
        pos += 8;
    }
    //qDebug() << "点数为" + QString::number(pointNum) + " " + QString::number(num_echos);

    memset(disp_dat_pre->image_Points, 0, sizeof(float) * (IMAG_ANG_NUM) * IMAG_SIZE);
    memset(points_counts, 0, sizeof(UINT16) * (IMAG_ANG_NUM) * IMAG_SIZE);

    if (IMAG_SIZE >= sampleCount)   //探测距离小于50m
    {
        float coef = 1;

        for (int i = 0; i < IMAG_ANG_NUM; i++)
        {
            for (int j = 0; j < IMAG_SIZE; j++)
            {
                points_x[i][j] = x[i][j] * coef;
                points_z[i][j] = y[i][j] * coef;
            }
        }
        {
            //BackGroundNoiseSuppress(echo_dat, header_dat->dataSampleCount,num_beams);
            for (int i = 0; i < sampleCount; i++)
            {
                //				if (i*toaResolution*halfSoundspeed>status.max_range) break;

                for (int j = 0; j < num_beams; j++)
                {
                    if(echo_dat[i * num_beams + j] == 0) continue;
                    disp_dat_pre->image_Points[j][i] = echo_dat[i * num_beams + j];
                    points_counts[j][i] ++;
                }

            }
        }
    }
    else
    {
        float coef = IMAG_SIZE / ((float)(sampleCount));
        float i_coef = 1.0 / coef;

        for (int i = 0; i < IMAG_ANG_NUM; i++)
        {
            for (int j = 0; j < IMAG_SIZE; j++)
            {
                int k = j * i_coef;
                points_x[i][j] = x[i][k];
                points_z[i][j] = y[i][k];
                //qDebug() << "points_x[" + QString::number(i) + "][" + QString::number(j) + "]: "  + QString::number(x[i][k]);
            }
        }

        {
            //BackGroundNoiseSuppress(echo_dat, header_dat->dataSampleCount, num_beams);
            for (int i = 0; i < sampleCount;i++)
            {
                for (int j = 0; j < num_beams;j++)
                {
                    if(echo_dat[i * num_beams + j] <= 0) continue;
                    int k = i * coef + 0.5;
                    //qDebug() << sampleCount << " " << coef;
                    if (k < IMAG_SIZE)
                    {
                        //qDebug() << "k" << QString::number(k);
                        //disp_dat_pre->image_beamPoints[m][k] +=echo_dat[i*num_beams+j];
                        disp_dat_pre->image_Points[j][k] += echo_dat[i * num_beams + j];
                        points_counts[j][k]++;
                    }
                }
            }
        }
    }

    BuildFanImage();

    m_window->ui->openGLWidget->UpdateColors();

    emit can_draw();

    m_isExtractingData = false;
}

void DataAcquisition::BuildFanImage()
{
    //qDebug() << "---------- 开始BuildFanImage ----------";
    int ind = 0;

    for (int k = 0; k < IMAG_SIZE; k++)
    {
        for (int m = 0; m < IMAG_ANG_NUM; m++)
        {
            if(points_counts[m][k] > 1)
            {
                disp_dat_pre->image_Points[m][k] /= points_counts[m][k];
            }
        }
    }
    for (int k = 1; k < IMAG_SIZE - 1; k++)
    {
        for (int m = k % 2; m < IMAG_ANG_NUM; m += 2)
        {
            if (m >= 1)
            {
                if (points_counts[m][k]!=0 || points_counts[m-1][k] !=0 || points_counts[m][k-1] !=0)
                {
                    disp_dat_pre->image[ind]=disp_dat_pre->image_Points[m][k-1];
                    disp_dat_pre->vertex[ind][0] = points_x[m][k-1];
                    disp_dat_pre->vertex[ind][1] = points_z[m][k-1];
                    ind++;
                    disp_dat_pre->image[ind] = disp_dat_pre->image_Points[m-1][k];
                    disp_dat_pre->vertex[ind][0] = points_x[m-1][k];
                    disp_dat_pre->vertex[ind][1] = points_z[m-1][k];
                    ind++;
                    disp_dat_pre->image[ind] = disp_dat_pre->image_Points[m][k];
                    disp_dat_pre->vertex[ind][0] = points_x[m][k];
                    disp_dat_pre->vertex[ind][1] = points_z[m][k];
                    ind++;
                }
                if  (points_counts[m][k]!=0 || points_counts[m-1][k] !=0 || points_counts[m][k+1] !=0)
                {
                    disp_dat_pre->image[ind]=disp_dat_pre->image_Points[m-1][k];
                    disp_dat_pre->vertex[ind][0]=points_x[m-1][k];
                    disp_dat_pre->vertex[ind][1]=points_z[m-1][k];
                    ind++;
                    disp_dat_pre->image[ind]=disp_dat_pre->image_Points[m][k+1];
                    disp_dat_pre->vertex[ind][0]=points_x[m][k+1];
                    disp_dat_pre->vertex[ind][1]=points_z[m][k+1];
                    ind++;
                    disp_dat_pre->image[ind]=disp_dat_pre->image_Points[m][k];
                    disp_dat_pre->vertex[ind][0]=points_x[m][k];
                    disp_dat_pre->vertex[ind][1]=points_z[m][k];
                    ind++;
                }
            }

        }
    }
    disp_dat_pre->num_points = ind;
}

void DataAcquisition::Update_XYGrid() {
    //float toa_scaling = 1.0 / 25000;

    for(int i = 0; i < MAX_ANG_NUM; i++)
    {
        double doa = (i * ANG_RESOLUTION - 67.5) * 0.0174533;

        for(int j = 0; j < MAX_SAMPLE_NUM; j++)
        {
            x[i][j] = j * sin(doa);
            y[i][j] = j * cos(doa);
            //qDebug() << "i, j: " << QString::number(i) + " " + QString::number(j) << " " << x[i][j] << " " << y[i][j];
        }
    }
}

