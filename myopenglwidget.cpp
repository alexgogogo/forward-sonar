#include <GL/glew.h>
#include "myopenglwidget.h"
#include "CommonDefs.h"

#include <QDebug>
#include <QtMath>
#include <QElapsedTimer>
#include <Qpainter>
#include <QtGlobal>
#include <QFont>

float LineColr[3] = {0.9, 0.0, 0.0};
float dispScale = 1.0;
extern MainWindow *m_window;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setMouseTracking(true);
}

MyOpenGLWidget::~MyOpenGLWidget()
{

}

void MyOpenGLWidget::initDef()
{
    m_colorsel = 0;
    m_fanFrame[0] = 0.0;
    m_fanFrame[1] = 0.0;
    m_fanFrame[274] = 0.0;
    m_fanFrame[275] = 0.0;
    //float radis = this->height() * 0.9;
    for (int i = 1; i < 137; i ++)
    {
        m_fanFrame[i * 2] = sin((i - 68.5) * 0.0174533);        // 0.0174533为弧度转度数，上下分别为x，y
        m_fanFrame[i * 2 + 1] = cos((i - 68.5) * 0.0174533);
    }
    for (int i = 0; i < IMAG_ANG_NUM + 1;i++)
    {
        m_fanback[i][0] = sin((i - (IMAG_ANG_NUM >> 1)) * IMAG_ANG_RESOLUTION * 0.0174533);
        m_fanback[i][1] = cos((i - (IMAG_ANG_NUM >> 1)) * IMAG_ANG_RESOLUTION * 0.0174533);
    }
    m_range = 50;

    m_dispStatus.beam_nums = 520;

    m_show_acousticimage = true;

    m_disp_dat->num_points = 0;

    m_brightness = 15;
    m_linearGain=pow(10,m_brightness/20.0);

    memset(m_disp_dat->vertex, 0, sizeof(float) * IMAG_SIZE * IMAG_ANG_NUM * 6 * 2);

    UpdateColormap();
}

void MyOpenGLWidget::UpdateColormap()
{
    int Num_color = NUM_COLOR;
    switch (m_colorsel)
    {
        case 0: //蓝红配色
        {
            int Num_section=(Num_color/5);      // 32768 / 5
            float c_step=1.0f/Num_section;
            for (int i=0;i<Num_color;i++)
            {
                if(i == 0) {
                    m_colormap[i][0]=0.0f;
                    m_colormap[i][1]=0.0f; //
                    m_colormap[i][2]=0.36f;
                }
                else if (i<Num_section)
                {
                    m_colormap[i][0]=0.0f;
                    m_colormap[i][1]=(i+1)*c_step; //
                    m_colormap[i][2]=1.0f;
                    //m_colormap[i][2]=0.5+0.5*i*c_step;
                }
                else if(i<Num_section*2)
                {
                    m_colormap[i][0]=0.0f;
                    m_colormap[i][1]=1.0f;
                    m_colormap[i][2]=m_colormap[i-1][2]-c_step;
                }
                else if (i<Num_section*3)
                {
                    m_colormap[i][0]=m_colormap[i-1][0]+c_step;
                    m_colormap[i][1]=1.0f;
                    m_colormap[i][2]=0.0f;
                }
                else if (i<Num_section*4)
                {
                    m_colormap[i][0]=1.0f;
                    m_colormap[i][1]=m_colormap[i-1][1]-c_step;
                    m_colormap[i][2]=0.0f;
                }
                else
                {
                    m_colormap[i][0]=1.0f;
                    m_colormap[i][1]=0.0f;
                    m_colormap[i][2]=0.0f;
                }
            }
        } break;
        case 1:     //黑白配色
        {
            float c_step=1.0f/(Num_color-1);
            float c_start=c_step;
            m_colormap[0][0]=0.0f;
            m_colormap[0][1]=0.0f;
            m_colormap[0][2]=0.0f;

            for (int i=1;i<Num_color;i++) {
                m_colormap[i][0]=1.0f;
                m_colormap[i][1]=1.0f;
                m_colormap[i][2]=1.0f;
            }
        } break;

    }
}

void MyOpenGLWidget::UpdateColors()
{
    if (m_disp_dat==NULL) return;
    m_linearGain=pow(10,m_brightness/20.0);
    for (int i=0;i<m_disp_dat->num_points;i++)
    {
        int index=((m_disp_dat->image[i]*m_linearGain-m_colorValue0)/(m_colorValue1-m_colorValue0)*NUM_COLOR);
        if (index>=NUM_COLOR) index=NUM_COLOR-1;
        else if(index<0) index=0;

        m_colors[i][0]=m_colormap[index][0];
        m_colors[i][1]=m_colormap[index][1];
        m_colors[i][2]=m_colormap[index][2];
    }
}


void MyOpenGLWidget::initializeGL()
{
    initDef();
}

//widget调整窗体或者首次显示时调用
void MyOpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void MyOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ratio = (float)(this->width())/(this->height());

    int wid = this->width();
    int hei = this->height() - 80;  //上下各留40 40像素

    int centerX = this->width() / 2;
    int centerY = this->height() - 40;
    float radius = this->height() - 80;
    float posX = radius * cos(22.5 * 0.0174533);
    float posY = radius * sin(22.5 * 0.0174533);

    int cnt = 0;
    intvl = 1;
    while(m_range >= 6 * intvl)
    {
        intvl *= 2;
        cnt ++;
        if(cnt == 2)
        {
            intvl = (intvl * 3) / 4;
        }
        else if(cnt == 3)
        {
            intvl = (intvl * 5) / 6;
        }
        else if(cnt == 4)
        {
            cnt = 0;
        }
        coef = (float)intvl / m_range;
        //qDebug() << "m_range:" << m_range << " intvl: " << intvl;
    }
    nTicks = (m_range + 0.1) / intvl;

    glViewport(0,0,this->width(),this->height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,this->width(),0,this->height());
    m_barDispGain.Draw(this->width() - 100, 22);

    glViewport(0, 40, wid, hei);    //限定图在glwidget的范围
    glMatrixMode(GL_PROJECTION);    //将当前矩阵指定为投影矩阵
    glLoadIdentity();           //坐标系的原点移到了屏幕中心
    gluOrtho2D(-0.5 * wid / hei, 0.5 * wid / hei, 0.0, 1.0);    //确定图形的视图范围

    glBegin(GL_TRIANGLE_FAN);		//扇形连续填充三角形串 可以画扇形（重要）
    glColor3f(m_colormap[0][0]*0.9,m_colormap[0][1]*0.9,m_colormap[0][2]*0.9);
    glVertex2f(0.0f,0.0f);
    int i = 0;
    for (i = 0; i < 520; i += 5)
    {
        glVertex2f(m_fanback[i][0],m_fanback[i][1]);  //	蓝色背景
    }
    if (i < 520 + 5)
        glVertex2f(m_fanback[520][0],m_fanback[520][1]);

    glEnd();

    glColor4f(1.0f,0.0f,0.0f,1.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, m_fanFrame);
    glDrawArrays(GL_LINE_STRIP, 0, 138);				//扇形外框(重要）
    glDisableClientState(GL_VERTEX_ARRAY);
    glEnd();

    glMatrixMode(GL_PROJECTION);        //数据点
    glLoadIdentity();

    float range = m_range * 1650.0 / 50;

    gluOrtho2D(-0.5 * wid / hei * range, 0.5 * wid / hei * range, 0.0, range);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, m_colors);
    glVertexPointer(2, GL_FLOAT, 0, m_disp_dat->vertex);					//数据点（重要！！）
    glDrawArrays(GL_TRIANGLES, 0, m_disp_dat->num_points);
    //qDebug() << QString::number(range);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.5 * wid / hei * hei,0.5 * wid / hei * hei, 0, 1.0 * hei);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(4, 0xAAAA);		//实线变虚线
    glColor4f(1.0f,0.0f,0.0f,1.0);

    //c=0;
    for (int i = 1;i <= nTicks; i++)
    {
        c = i * coef;
        //qDebug() << "c: " << c;
        glBegin(GL_LINE_STRIP);						//扇形刻度虚线（重要）
        glVertex2f(m_fanFrame[2] * c * hei - 5, m_fanFrame[3] * c * hei - 5 * 1.73);
        for(int n = 2; n < 274; n += 2)
            glVertex2f(m_fanFrame[n] * c * hei, m_fanFrame[n + 1] * c * hei);
        glVertex2f(m_fanFrame[272] * c * hei+5,m_fanFrame[273] * c * hei - 5 * 1.73);
        glEnd();
    }
    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_LINE_SMOOTH);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::red);
    painter.setFont(QFont("Helvetica", 12));
    for (int i = 1;i <= nTicks; i++) {
        //qDebug() << "intvl*i: " << intvl * i;
        painter.drawText(centerX - posX / m_range * intvl * i - 25, centerY - posY / m_range * intvl * i + 20, QString::number(intvl * i));
        painter.drawText(centerX + posX / m_range * intvl * i, centerY - posY / m_range * intvl * i + 20, QString::number(intvl * i));
    }

    //if(ready == true) {
        calcFPS();
        paint();
    //    ready = false;
    //}
}

void MyOpenGLWidget::updateFPS(qreal v)
{
    fps = v;
}

void MyOpenGLWidget::calcFPS()
{
    static QElapsedTimer time;
    static int	 once = [=]() {
          time.start();
          return 0;
    }();
    Q_UNUSED(once)

    qreal elasped = time.elapsed();

    if (qRound(elasped) > 1000)
    {
        qDebug() << "time:" << elasped << " frame:" << frame;
        updateFPS(frame / elasped * 1000);
        time.restart();
        frame = 0;
    }
}

void MyOpenGLWidget::paint()
{
    QString str = QString("FPS:%1").arg(QString::number(fps, 'f', 3));

    QPainter painter;
    painter.begin(this);
    QFont font;
    font.setFamily("Fira Code");
    font.setPointSize(10);
    painter.setFont(font);

    painter.setRenderHint(QPainter::TextAntialiasing);
    painter.setPen(QColor(255, 0, 0));
    painter.drawText(50, 50, str);

    QString str2 = QString("pingNo:%1").arg(QString::number(pingNo));
    painter.drawText(50, 20, str2);

    QString str3 = QString("显示增益:%1 dB").arg(QString::number(m_brightness));

    painter.drawText(this->width() - 240, this->height() - 25, str3);
    painter.end();
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int up;
    int xposView = event->x();
    int yposView = this->height() - event->y();
    if(m_barDispGain.onMouseMove(xposView,yposView))
        up = 1;

    if(up == 1) {
        this->UpdateColors();
        this->update();
    }
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    int xposView=event->x();
    int yposView=this->height()-event->y();
    if (m_barDispGain.OnMouseDown(xposView,yposView))
    {
        int newBrightness=m_brightness +m_barDispGain.WhichArrowClicked()*5;
        if (newBrightness<0) newBrightness=0;
        else if(newBrightness>60) newBrightness=60;

        if (newBrightness != m_brightness)
        {
            m_brightness=newBrightness;
            m_barDispGain.SetPos(this->m_brightness);
            this->UpdateColors();
            this->update();
        }
    }
}

void MyOpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    int xposView = event->x();
    int yposView = this->height() - event->y();
    if(m_barDispGain.OnMouseUp(xposView,yposView)) {
        this->UpdateColors();
        this->update();
    }
}

