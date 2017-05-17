#include "myjob.h"
#include <QDebug>
#include <QThread>

MyJob::MyJob(QObject *parent) : QObject(parent)
{
    mstop = false;
}

MyJob::~MyJob()
{
}

void MyJob::start(QString name)
{

    mstop = false;

    for (int i = 0; i < 10000; ++i) {
        qDebug() << "From thread " << i;
        if (mstop) return;

        emit on_number(name,i);
        QThread::currentThread()->msleep(500);
    }
}

void MyJob::obj_slot_stop()
{
    //MessageBox(NULL,L"1",L"DEB",MB_OK);
    mstop = true;
}
