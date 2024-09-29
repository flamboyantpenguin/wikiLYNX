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
    //timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::initialise(QJsonObject *cfgData) {

    countdown = 0;
    this->cfg = (*cfgData)["data"].toObject();
    this->tChk = (*cfgData)["checkpoints"].toInt();
    this->endTime = (*cfgData)["time"].toInt();
    QUrl url(this->cfg[QString::number(chk)].toObject()["url"].toString());
    void showHistory();
    ui->field->load(url);
    ui->progressBar->setValue(0);

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
        auto c = QString::number(this->countdown);
        std::ofstream out("./wikiLYNX/"+instance+"/report.txt", std::ios_base::app);
        out << "Status: Passed\n";
        out << "Time Taken: "+c.toStdString()+"\n";
        out << "Finish Time: "+QTime::currentTime().toString("hh:mm:ss").toStdString()+"\n";
        out.close();
        ui->field->printToPdf("./wikiLYNX/"+QString::fromStdString(instance)+"/fPage.pdf");
        QMessageBox::information(this, "wikiLYNX", "You Won!!!", QMessageBox::Ok);
        QMessageBox::information(this, "wikiLYNX", "Time Taken: "+c, QMessageBox::Ok);
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


int MainWindow::launchLogs() {

    QFile lFile("./wikiLYNX/"+QString::fromStdString(instance)+"/log.txt");
    lFile.open(QIODevice::ReadOnly);
    auto logs = QString(lFile.readAll());
    lFile.close();
    historyView.initialise(&logs);
    historyView.show();
    return 0;
}
