#include "BrigthnessScrollBar.h"
#include <GL/glew.h>
#include <QMouseEvent>
#include <QDebug>

BrigthnessScrollBar::BrigthnessScrollBar()
{
    m_width = 80;
    m_height = 20;
    m_range = 60;
    m_pos = 15;
    leftArrowActived = false;
    rightArrowActived = false;
    leftArrowDown = false;
    rightArrowDown = false;
}

void BrigthnessScrollBar::Draw(int xPos, int yPos)
{
    m_xpos = xPos;
    m_ypos = yPos;
    //glViewport(0,0,m_width+1,m_height+1);

    glViewport(xPos, yPos, m_width+1, m_height+1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, m_width+1, 0, m_height+1);

    glBegin(GL_TRIANGLES);
    if (leftArrowDown)
        glColor4f(0.5,0.5,1.0,1.0);
    else
        glColor4f(0.0,0.0,1.0,1.0);
    glVertex2f(0, m_height/2);           //左边三角形
    glVertex2f(10, m_height);
    glVertex2f(10, 0);

    if (rightArrowDown)
        glColor4f(1.0, 0.5, 0.5, 1.0);
    else
        glColor4f(1.0, 0.0, 0.0, 1.0);
    glVertex2f(m_width, m_height/2);     //右边三角形
    glVertex2f(m_width-10, m_height);
    glVertex2f(m_width-10, 0);
    glEnd();

    glLineWidth(1.0);
    glColor4f(1.0, 1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0, m_height/2);
    glVertex2f(10, 0);
    glVertex2f(10, m_height);
    glVertex2f(0, m_height/2);
    glEnd();


    //glEnable(GL_LINE_SMOOTH);

    if (leftArrowActived)
    {
        glLineWidth(2.0);
        glColor4f(0.0, 1.0, 0.0, 1.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor4f(1.0, 1.0, 0.0, 1.0);
    }

    glBegin(GL_LINE_STRIP);
    glVertex2f(0,m_height/2);
    glVertex2f(10, 0);
    glVertex2f(10, m_height);
    glVertex2f(0, m_height/2);
    glEnd();

    if (rightArrowActived)
    {
        glLineWidth(2.0);
        glColor4f(0.0, 1.0, 0.0, 1.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor4f(1.0, 1.0, 0.0, 1.0);

    }
    glBegin(GL_LINE_STRIP);
    glVertex2f(m_width, m_height/2);
    glVertex2f(m_width-10, m_height);
    glVertex2f(m_width-10, 0);
    glVertex2f(m_width, m_height/2);
    glEnd();
    //glDisable(GL_LINE_SMOOTH);


    int blue_left = m_pos + 10;       //长方形
    if (blue_left>=11)
    {
        glBegin(GL_QUADS);
        if(blue_left>=16)
        {
            glColor4f(1.0,1.0,0.5,1.0);
            glVertex2f(11,m_height-3);
            glVertex2f(11,2);

            glColor4f(1.0,0.0,0.0,1.0);
            glVertex2f(blue_left-5,2);
            glVertex2f(blue_left-5,m_height-3);

            glColor4f(1.0,0.0,0.0,1.0);
            glVertex2f(blue_left-5,m_height-3);
            glVertex2f(blue_left-5,2);

        }
        else
        {
            glColor4f(1.0,0.0,0.0,1.0);
            glVertex2f(11,m_height-3);
            glVertex2f(11,2);
        }

        glColor4f(1.0,1.0,1.0,1.0);
        glVertex2f(blue_left,2);
        glVertex2f(blue_left,m_height-3);
        glEnd();
    }

    if (blue_left<=m_width-11)
    {
        glBegin(GL_QUADS);
        if(blue_left<=m_width-16)
        {

            glColor4f(0.5,1.0,1.0,1.0);
            glVertex2f(m_width-11,m_height-3);
            glVertex2f(m_width-11,2);


            glColor4f(0.0,0.0,1.0,1.0);
            glVertex2f(blue_left+5,2);
            glVertex2f(blue_left+5,m_height-3);


            glColor4f(0.0,0.0,1.0,1.0);
            glVertex2f(blue_left+5,m_height-3);
            glVertex2f(blue_left+5,2);

        }
        else
        {
            glColor4f(0.0,0.0,1.0,1.0);
            glVertex2f(m_width-11,m_height-3);
            glVertex2f(m_width-11,2);
        }
        glColor4f(1.0,1.0,1.0,1.0);
        glVertex2f(blue_left,2);
        glVertex2f(blue_left,m_height-3);

        glEnd();
    }

    glLineWidth(1.0);
    glColor4f(1.0,1.0,0.0,1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(10,2);
    glVertex2f(m_width-10,2);
    glVertex2f(m_width-10,m_height-3);
    glVertex2f(10,m_height-3);
    glVertex2f(10,2);
    glEnd();
}

bool BrigthnessScrollBar::onMouseMove(int xpos, int ypos)
{
    if (xpos>=m_xpos && xpos<=m_xpos+10 && ypos>=m_ypos && ypos<=m_ypos+m_height) {
        if (!leftArrowActived)
        {
            leftArrowActived=true;
            rightArrowActived=false;
        }
        return true;
    }
    else if(xpos>=m_xpos+m_width-10 && xpos<=m_xpos+m_width && ypos>=m_ypos && ypos<=m_ypos+m_height) {
        if (!rightArrowActived)
        {
            leftArrowActived=false;
            rightArrowActived=true;
        }

        return true;
    }
    else {
        if (leftArrowActived || rightArrowActived ||leftArrowDown || rightArrowDown) {
            leftArrowActived=false;
            rightArrowActived=false;
            leftArrowDown=false;
            rightArrowDown=false;
            return true;
        }
    }
    return false;
}

bool BrigthnessScrollBar::OnMouseDown(int xpos, int ypos)
{
    if (xpos>=m_xpos && xpos<=m_xpos+10 && ypos>=m_ypos && ypos<=m_ypos+m_height)
    {
        if (!leftArrowDown)
        {
            leftArrowDown=true;
            rightArrowDown=false;
            return true;
        }
    }
    else if(xpos>=m_xpos+m_width-10 && xpos<=m_xpos+m_width && ypos>=m_ypos && ypos<=m_ypos+m_height)
    {
        if (!rightArrowDown)
        {
            leftArrowDown=false;
            rightArrowDown=true;
            return true;
        }
    }
    else
    {
        if (leftArrowDown || rightArrowDown)
        {
            leftArrowDown=false;
            rightArrowDown=false;
            return true;
        }
    }

    return false;
}

bool BrigthnessScrollBar::OnMouseUp(int xpos, int ypos)
{
    if (leftArrowDown || rightArrowDown)
    {
        leftArrowDown=false;
        rightArrowDown=false;
        return true;
    }
    return false;
}

int BrigthnessScrollBar::WhichArrowClicked()
{
    if (leftArrowDown) return -1;
    if (rightArrowDown) return 1;
    return 0;
}

void BrigthnessScrollBar::SetPos(int pos)
{
    m_pos = pos;
}


