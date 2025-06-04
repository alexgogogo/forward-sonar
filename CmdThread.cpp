#include "CmdThread.h"

CmdThread::CmdThread()
{
    init();
}

void CmdThread::init()
{
    m_cmdsocket = new QUdpSocket(this);

    m_cmd.cmd_head=0x5A5A;
    m_cmd.cmd_end=0x0A0D;
    m_cmd.cmd_len=40;
    m_cmd.onoff = 0x02;
    m_cmd.pulse=0x05;
    m_cmd.range=0x02;
    m_cmd.tvg=0x03;
    m_cmd.thd=64;
    memset(m_cmd.reserved,0x00,sizeof(m_cmd.reserved));
}

void CmdThread::readyRead_slot()
{
    while(1) {
        QByteArray array;

        array.resize(m_cmdsocket->pendingDatagramSize());

        m_cmdsocket->readDatagram(array.data(), array.size());

        qDebug() << QString(array.data());
    }
}

void CmdThread::OnStartSonar()
{
    QHostAddress addr;
    m_bStarted=true;
    m_cmd.onoff=m_bStarted?0x01:0x02;

    m_cmdsocket->bind(QHostAddress::Any, 8000);
    //发送m_cmd给下位机

    //m_cmdsocket->writeDatagram(m_cmdaddr,8000);
}

void CmdThread::OnStopSonar()
{
    m_bStarted=false;
    m_cmd.onoff=m_bStarted?0x01:0x02;

    //发送m_cmd给下位机
}

