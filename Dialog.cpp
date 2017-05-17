#include "Dialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&myjob,&MyJob::on_number,this,&MainWindow::SlotForNumber);
    connect(this,&MainWindow::on_stop,&myjob,&MyJob::obj_slot_stop);
}

MainWindow::~MainWindow()
{
    emit on_stop();
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{

    QFuture<void> test = QtConcurrent::run(&this->myjob, &MyJob::start, QString("Kitten"));
}

void MainWindow::on_btnStop_clicked()
{
    emit on_stop();
}

void MainWindow::SlotForNumber(QString name, int num)
{
    qDebug() << "From DIALOGO " << name << " and " << num;
    ui->lineEdit->setText( "From DIALOGO " + name + " " + QString::number(num));
}
