#ifndef PARSINGFILE_H
#define PARSINGFILE_H

#include <QDialog>
#include <QString>
#include <QThread>
#include "CommonDefs.h"
#include "replayprogress.h"

namespace Ui {
class ParsingFile;
}

class ParsingFile : public QDialog
{
    Q_OBJECT

public:
    explicit ParsingFile(QWidget *parent = nullptr);
    ~ParsingFile();

    void ParseThread();

    QString filePath = NULL;
    QThread *thread;

    int progress = 0;

    long long len_Datafile;         //文件大小

    bool ready = false;

private:
    Ui::ParsingFile *ui;

signals:
    void progressUpdate();
};

#endif // PARSINGFILE_H
