#include "mainwindow.h"
#include "./ui_mainwindow.h"


namespace fs = std::filesystem;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    instance = "instance"+QDateTime::currentDateTime().toString("yyyyMMddHHmmss").toStdString();
    fs::create_directories("./wikiLYNX/"+instance);

    ui->clock->setAlignment(Qt::AlignCenter);
    ui->counter->setAlignment(Qt::AlignCenter);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    connect(ui->field, &QWebEngineView::urlChanged, this, &MainWindow::initAction);
    connect(ui->exitButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
    connect(ui->showHistory, SIGNAL(clicked(bool)), this, SLOT(launchLogs()));
    connect(ui->viewChkButton, SIGNAL(clicked(bool)), this, SLOT(viewCheckPoints()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::initialise(QJsonObject *cfgData, int *d) {

    countdown = 0;
    aTime = QTime::currentTime().toString("hh:mm:ss").toStdString();
    this->cfg = (*cfgData)["data"].toObject();
    this->tChk = (*cfgData)["checkpoints"].toInt();

    this->endTime = (*cfgData)["time"].toInt();
    this->dontKillMe = d;
    QUrl url(this->cfg[QString::number(chk)].toObject()["url"].toString());
    void showHistory();
    ui->field->load(url);
    ui->progressBar->setValue(0);
    QApplication::processEvents();

    timer->start(1000);
    return 0;
}


void MainWindow::updateCountdown()
{
    countdown++;
    ui->clock->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->counter->setText(QString::number(countdown));

    if (countdown == this->endTime) {
        this->missionFailed();
    }

}


void MainWindow::initAction() {

    auto url = ui->field->page()->url();
    std::ofstream out("./wikiLYNX/"+instance+"/log.txt", std::ios_base::app);
    out << QDateTime::currentDateTime().toString("yyyy/MM/dd|hh:mm:ss").toStdString()+">>\t";
    out << url.toString().toStdString()+"\n";
    out.close();

    auto wUrl = this->cfg[QString::number((this->chk)+1)].toObject()["url"].toString();
    if (url.toString() == wUrl) {
        this->missionAccomplished();
    }
}


int MainWindow::missionAccomplished() {



    chk++;
    int prg = (chk/ (float) (tChk-1)) *100;
    ui->progressBar->setValue(prg);

    if (prg == 100) {
        timer->stop();
        std::string cTime = QTime::currentTime().toString("hh:mm:ss").toStdString();
        *dontKillMe = 1;
        QString c = QString::number(this->countdown);
        std::ofstream out("./wikiLYNX/"+instance+"/report.txt", std::ios_base::app);
        out << "Status: Passed\n";
        out << "Time Taken: "+c.toStdString()+"\n";
        out << "Start Time: "+aTime+"\n";
        out << "Finish Time: "+cTime+"\n";
        out.close();
        ui->field->printToPdf("./wikiLYNX/"+QString::fromStdString(instance)+"/fPage.pdf");
        congratsView.initialise(c, QString::fromStdString(this->aTime), QString::fromStdString(cTime), instance);
        QMessageBox::information(this, "wikiLYNX", "You Won!!!", QMessageBox::Ok);
        congratsView.show();
        //QMessageBox::information(this, "wikiLYNX", "Time Taken: "+c+" seconds", QMessageBox::Ok);
        close();
    }

    QApplication::processEvents();
    return 0;

}


int MainWindow::missionFailed(){

    QString c = QString::number(this->countdown);
    ui->field->printToPdf("./wikiLYNX/"+QString::fromStdString(instance)+"/fPage.pdf");
    std::ofstream out("./wikiLYNX/"+instance+"/report.txt", std::ios_base::app);
    out << "Status: Failed\n";
    out << "Time Taken: "+c.toStdString()+"\n";
    out << "Finish Time: "+QTime::currentTime().toString("hh:mm:ss").toStdString()+"\n";
    out.close();
    QMessageBox::critical(this, "wikiLYNX", "Timeout!", QMessageBox::Ok);
    close();
    return 0;
}


void MainWindow::launchLogs() {

    QFile f("./wikiLYNX/"+QString::fromStdString(instance)+"/log.txt");
    f.open(QIODevice::ReadOnly);
    auto logs = QString(f.readAll());
    f.close();
    historyView.dontKillMe = (this->dontKillMe);
    historyView.initialise(&logs);
    historyView.show();
}


void MainWindow::viewCheckPoints() {

    checkpointView.dontKillMe = (this->dontKillMe);
    checkpointView.initialise(&cfg, &tChk, &endTime, &this->chk);
    checkpointView.show();
}
