#ifndef COLORVALUESETDLG_H
#define COLORVALUESETDLG_H

#include <QDialog>

namespace Ui {
class ColorValueSetDlg;
}

class ColorValueSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ColorValueSetDlg(QWidget *parent = nullptr);
    ~ColorValueSetDlg();

    bool OnOK();

public:
    float m_colorValue0;    //最小值
    float m_colorValue1;

private slots:


private:
    Ui::ColorValueSetDlg *ui;
};

#endif // COLORVALUESETDLG_H
