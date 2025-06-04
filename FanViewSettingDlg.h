#ifndef FANVIEWSETTINGDLG_H
#define FANVIEWSETTINGDLG_H



#include <QWidget>
#include <QPaintEvent>
#include "ColorValueSetDlg.h"

namespace Ui {
class FanViewSettingDlg;
}

class FanViewSettingDlg : public QWidget
{
    Q_OBJECT

public:
    explicit FanViewSettingDlg(QWidget *parent = nullptr);
    ~FanViewSettingDlg();

    void colorSet();

    void paintEvent(QPaintEvent *event);

    ColorValueSetDlg *dlg;

public:
    float valueBack0 = 1e18;       //最小强度和最大强度
    float valueBack1 = 1e25;

public:
    Ui::FanViewSettingDlg *ui;
private slots:
    void on_colorsel_currentIndexChanged(int index);
};

#endif // COLORVALUESETDLG_H
