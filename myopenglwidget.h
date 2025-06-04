#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include "dataacquisition.h"
#include "mainwindow.h"
#include <QThread>
#include "BrigthnessScrollBar.h"
#include <QMouseEvent>

class MyOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();

    void initDef();

    void DrawTexts(int xPos, int yPos, QString str);

    void display();

    void UpdateColormap();

    void UpdateColors();

    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;


public:
    QThread *thread;

    StatusDataForDisp m_dispStatus;

    DisplayData *m_disp_dat = new DisplayData;

    DataAcquisition *dataacquisition = NULL;

    float m_fanFrame[276];      //扇形框架
    float m_fanback[521][2];    //扇形背景
    int intvl=1;
    float coef = (float)intvl / m_range;
    int nTicks;

    int m_range;      //探测距离(50m)

    bool ready = false;
    float c;

    int frame = 0;

    int pingNo = 0;

    bool m_show_acousticimage;

    float ratio;

    float m_colorValue0 = 1e18;    //最小强度
    float m_colorValue1 = 1e25;    //最大强度
    float m_colormap[32768][3];
    int m_colorsel;

    BrigthnessScrollBar m_barDispGain;  //显示增益进度条
    int m_brightness;   //增益系数
    float m_linearGain;

    GLfloat m_colors[IMAG_SIZE*IMAG_ANG_NUM*6][3];

public:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    void updateFPS(qreal);
    void calcFPS();
    void paint();

private:
    qreal		fps;
};


#endif // MYOPENGLWIDGET_H
