#ifndef CMDTHREAD_H
#define CMDTHREAD_H

#include "Packet.h"
#include <QWidget>
#include <QUdpSocket>

class CmdThread : public QWidget
{
public:
    CmdThread();

    void init();

    void OnStartSonar();

    void OnStopSonar();

public:
    CtrlCmd m_cmd;

    QUdpSocket *m_cmdsocket;

private:
    bool m_bStarted = false;


private slots:
    void readyRead_slot();
};

#endif // CMDTHREAD_H
