#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include "myjob.h"
#include <windows.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void on_stop();

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
public slots:
    void SlotForNumber(QString name, int number);
private:
    Ui::MainWindow *ui;
    MyJob myjob;

};

#endif // MAINWINDOW_H
