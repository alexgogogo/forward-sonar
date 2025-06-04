#ifndef COMMONDEFS_H
#define COMMONDEFS_H

#include <QString>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned __int64 ULONGLONG;
typedef unsigned short      UINT16;
typedef unsigned int        UINT32;

#define IMAG_SIZE 1650
#define IMAG_ANG_NUM 520
#define MAX_BEAM_NUM 520
#define MAX_ANG_NUM 520
#define MAX_SAMPLE_NUM 1650 * 3
#define IMAG_ANG_RESOLUTION 0.2596153       // 135 / 520
#define ANG_RESOLUTION 135.0 / 519
#define MAX_PACKET_SIZE 520 * 1650 * 3 * 8
#define NUM_COLOR 32768

typedef struct DisplayData {
    int num_points;     //点的数量

    float image_Points[IMAG_ANG_NUM][IMAG_SIZE];    //点的强度
    float image[IMAG_SIZE * IMAG_ANG_NUM * 6];      //点的强度
    float vertex[IMAG_SIZE * IMAG_ANG_NUM * 6][2];  //对应x, y坐标
    int ready = 0;
}DisplayData;


typedef struct StatusDataForDisp {
    int work_mode;
    int isConnected;

    int beam_nums;  //波束数

}StatusDataForDisp;

#endif // COMMONDEFS_H
