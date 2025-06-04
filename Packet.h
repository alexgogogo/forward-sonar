
#ifndef PACKET_H
#define PACKET_H

#include <QDebug>

#define DATA_HEAD 0x5B5B
#define DATA_TAIL 0x0A0D    //小端, 实际上是0D0A
#define DATA_PACKETSIZE 32774

struct BeamData
{
    unsigned int beam;
    float intensity;
    unsigned int getImgNum(){       //图像号(0-3位)   0-15
        unsigned beam1 = (((beam&0xFF)<<24)|((beam&0xFF00)<<8)|((beam&0xFF0000)>>8)|((beam&0xFF000000)>>24));
        return ((beam1&0xF0000000)>>28);
    }
    unsigned int getFrameInd(){     //小帧号(4-19位)  1650 -- 50m  1650 * 2 -- 100m
        unsigned beam1 = (((beam&0xFF)<<24)|((beam&0xFF00)<<8)|((beam&0xFF0000)>>8)|((beam&0xFF000000)>>24));
        return ((beam1&0x0FFFF000)>>12);
    }
    unsigned int getBeamInd(){      //波束数(20-31位)   0-519
        unsigned beam1 = (((beam&0xFF)<<24)|((beam&0xFF00)<<8)|((beam&0xFF0000)>>8)|((beam&0xFF000000)>>24));
        return (beam1&0xFFF);
    }
};

struct BeamPacket           //把一帧的数据放一起
{
    unsigned int frame_head;  //0x0B0B0A0A(暂时不用)
    int frame_size;         //一帧的大小
    double timeStamp;       //
    unsigned int pingNo;    //第几帧
    int reserved[26];
    int alignment;
};

struct CtrlCmd
{
    unsigned short cmd_head;  //0x5A5A
    unsigned short cmd_len;   //40
    unsigned char pulse;      //0x00=40us, 0x01=80us, 0x02=160us,0x03=240us,0x04=320us, 0x05=480us,0x06=640us,0x07=820us 0x08=1ms,0x09=2ms,0x0a=4ms,0x0b=6ms,0x0c=8ms,0x0d=10ms,
    unsigned char range;      //0x01=10m,0x02=50m,0x03=100m,0x04=150m,
    unsigned char tvg;        //0x01~0x08
    unsigned char onoff;      //0x01=on, 0x02=off
    unsigned char thd;        //threshood for beam image
    unsigned char reserved[29];
    unsigned short cmd_end;     //0x0A0D
};

#endif // PACKET_H
