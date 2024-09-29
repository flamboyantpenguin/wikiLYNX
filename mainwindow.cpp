#include "mainwindow.h"
#include "./ui_mainwindow.h"

//#include <QString>
//#include <QDateTime>
//#include <QStringView>

namespace fs = std::filesystem;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QTimer *timer = new QTimer(this);

    instance = "instance"+QDateTime::currentDateTime().toString("yyyyMMddHHmmss").toStdString();
    fs::create_directories("./wikiLYNX/"+instance);

    ui->clock->setAlignment(Qt::AlignCenter);
    ui->counter->setAlignment(Qt::AlignCenter);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    connect(ui->field, &QWebEngineView::urlChanged, this, &MainWindow::initAction);
    connect(ui->exitButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::initalise(QJsonObject *cfgData) {

    countdown = 0;
    this->cfg = (*cfgData)["data"].toObject();
    this->tChk = (*cfgData)["checkpoints"].toInt();
    QUrl url(this->cfg[QString::number(chk)].toObject()["url"].toString());

    ui->field->load(url);
    ui->progressBar->setValue(0);
    return 0;
}


void MainWindow::updateCountdown()
{
    countdown++;
    ui->clock->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->counter->setText(QString::number(countdown));
}


void MainWindow::initAction() {

    auto url = ui->field->page()->url();
    std::ofstream out("./wikiLYNX/"+instance+"/log.txt", std::ios_base::app);
    out << url.toString().toStdString()+"\n";
    out.close();

    auto wUrl = this->cfg[QString::number((this->chk)+1)].toObject()["url"].toString();

    if (url.toString() == wUrl) {
        chk++;
        int prg = (chk/ (float) (tChk-1)) *100;
        ui->progressBar->setValue(prg);

        if (prg == 100) {
            QMessageBox::information(this, "wikiLYNX", "You Won!!!", QMessageBox::Ok);
            ui->field->load(QUrl("https://upload.wikimedia.org/wikipedia/commons/thumb/0/0c/Suresh_10.jpg/640px-Suresh_10.jpg"));
        }

        QApplication::processEvents();
    }

}
