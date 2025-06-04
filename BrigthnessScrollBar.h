#ifndef BRIGTHNESSSCROLLBAR_H
#define BRIGTHNESSSCROLLBAR_H

#include <QWidget>
#include <QMouseEvent>

class BrigthnessScrollBar : public QWidget
{
public:
    BrigthnessScrollBar();

    void Draw(int xPos, int yPos);

    bool onMouseMove(int xpos, int ypos);
    bool OnMouseDown(int xpos,int ypos);
    bool OnMouseUp(int xpos,int ypos);

    int WhichArrowClicked();
    void SetPos(int pos);

protected:

private:
    int m_xpos;
    int m_ypos;
    int m_width;
    int m_height;
    int m_range;
    int m_pos;

    bool leftArrowActived;
    bool rightArrowActived;
    bool leftArrowDown;
    bool rightArrowDown;
};

#endif // BRIGTHNESSSCROLLBAR_H
