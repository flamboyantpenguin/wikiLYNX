#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateCountdown()
{
    countdown++;
    ui->clock->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->counter->setText(QString::number(countdown));
}
