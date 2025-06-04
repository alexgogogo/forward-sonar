#ifndef REPLAYPROGRESS_H
#define REPLAYPROGRESS_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QProgressBar>

class replayProgress : public QObject
{
    Q_OBJECT

public:
    replayProgress();

    QDialog *progressDialog;
    QProgressBar *progress;
    QLabel *label1;

};

#endif // REPLAYPROGRESS_H
