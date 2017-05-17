#ifndef MYJOB_H
#define MYJOB_H

#include <QObject>
#include <windows.h>

class MyJob : public QObject
{
    Q_OBJECT
public:
    explicit MyJob(QObject *parent = 0);
    ~MyJob();

    void start(QString name);

signals:
    void on_number(QString name, int number);

public slots:
    void obj_slot_stop();

private:
        bool mstop;
};

#endif // MYJOB_H
