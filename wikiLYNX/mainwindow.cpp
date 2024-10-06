#include "include/mainwindow.h"
#include "ui/ui_mainwindow.h"


namespace fs = std::filesystem;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);




    ui->clock->setAlignment(Qt::AlignCenter);
    ui->counter->setAlignment(Qt::AlignCenter);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    connect(ui->field, &QWebEngineView::urlChanged, this, &MainWindow::initAction);
    connect(ui->exitButton, SIGNAL(clicked(bool)), this, SLOT(endGame()));
    connect(ui->showHistory, SIGNAL(clicked(bool)), this, SLOT(launchLogs()));
    connect(ui->viewChkButton, SIGNAL(clicked(bool)), this, SLOT(viewCheckPoints()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::initialise(QJsonObject *cfgData, int *c, QString allowedDomain, int aRD) {

    instance = "instance"+QDateTime::currentDateTime().toString("yyyyMMddHHmmss").toStdString();
    fs::create_directories("./gData/logs/"+instance);
    aTime = QTime::currentTime().toString("hh:mm:ss.zzz").toStdString();
    this->cfg = (*cfgData)["data"].toObject();
    this->tChk = (*cfgData)["checkpoints"].toInt();
    this->endTime = (*cfgData)["time"].toInt();
    this->alD = aRD;
    this->cCount = this->endTime;
    this->domain = allowedDomain.toStdString();
    countdown = this->endTime;
    this->dontKillMe = c;
    QUrl url(this->cfg[QString::number(chk)].toObject()["url"].toString());
    ui->field->load(url);
    ui->progressBar->setValue(0);
    QApplication::processEvents();

    timer->start(100);
    return 0;
}


void MainWindow::updateCountdown()
{
    countdown = countdown - 0.1;
    ui->clock->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->counter->setText(QString::number(countdown, 'f', 2));

    if (countdown < 0.099) {
        this->missionFailed();
    }

}


void MainWindow::initAction() {

    auto url = ui->field->page()->url();
    std::ofstream out("./gData/logs/"+instance+"/log.txt", std::ios_base::app);
    out << QDateTime::currentDateTime().toString("yyyy/MM/dd|hh:mm:ss.zzz").toStdString()+">>\t";
    out << url.toString().toStdString()+"\n";
    out.close();

    if (!alD) {
        std::string u = url.toString().toStdString();
        if (u.substr(0, 24) != domain) {
            *dontKillMe = 1;
            QMessageBox::critical(this, "wikiLYNX", "Rule Violation! You're not allowed to visit sites other domain in this game", QMessageBox::Ok);
            *dontKillMe = 0;
            QUrl url(this->cfg[QString::number(chk)].toObject()["url"].toString());
            ui->field->load(url);
        }
    }


    auto wUrl = this->cfg[QString::number((this->chk)+1)].toObject()["url"].toString();
    if (url.toString() == wUrl) {
        this->missionAccomplished();
    }
    else {
        ui->statusbar->showMessage("Next Checkpoint: "+wUrl);
    }
}


int MainWindow::missionAccomplished() {

    chk++;
    int prg = (chk/ (float) (tChk-1)) *100;
    ui->progressBar->setValue(prg);
    this->cCount = this->countdown;
    this->cTime = QTime::currentTime().toString("hh:mm:ss.zzz").toStdString();

    if (prg == 100) {
        timer->stop();
        ui->statusbar->showMessage("You won!!!");
        *dontKillMe = 1;
        QString c = QString::number(endTime-cCount);
        std::ofstream out("./gData/logs/"+instance+"/report.txt", std::ios_base::app);
        out << "Status: Passed\n";
        out << "Time Taken: "+c.toStdString()+"\n";
        out << "Start Time: "+aTime+"\n";
        out << "CheckPoint Time: "+cTime+"\n";
        out.close();
        ui->field->printToPdf("./gData/logs/"+QString::fromStdString(instance)+"/fPage.pdf");
        congratsView.initialise(c, QString::fromStdString(this->aTime), QString::fromStdString(cTime), instance, &(this->chk), 1);
        QMessageBox::information(this, "wikiLYNX", "You Won!!!", QMessageBox::Ok);
        congratsView.show();
        close();
    }

    QApplication::processEvents();
    return 0;

}


int MainWindow::missionFailed(){

    timer->stop();
    *dontKillMe = 1;
    QString c = QString::number(endTime-cCount);
    ui->field->printToPdf("./gData/logs/"+QString::fromStdString(instance)+"/fPage.pdf");
    std::ofstream out("./gData/logs/"+instance+"/report.txt", std::ios_base::app);
    out << "Status: Failed\n";
    out << "Time Taken: "+c.toStdString()+"\n";
    out << "CheckPointTime Time: "+cTime+"\n";
    out.close();
    QMessageBox::critical(this, "wikiLYNX", "Timeout!", QMessageBox::Ok);
    congratsView.initialise(c, QString::fromStdString(this->aTime), QString::fromStdString(cTime), instance, &(this->chk), 0);
    congratsView.show();
    close();
    return 0;
}


void MainWindow::launchLogs() {

    QFile f("./gData/logs/"+QString::fromStdString(instance)+"/log.txt");
    f.open(QIODevice::ReadOnly);
    auto logs = QString(f.readAll());
    f.close();
    historyView.dontKillMe = (this->dontKillMe);
    historyView.initialise(&logs);
    historyView.show();
}


void MainWindow::viewCheckPoints() {

    checkpointView.dontKillMe = (this->dontKillMe);
    checkpointView.initialise(&cfg, &this->tChk, &this->chk);
    checkpointView.show();
}


void MainWindow::endGame() {

    timer->stop();
    *dontKillMe = 1;
    QString c = QString::number(endTime-cCount);
    ui->field->printToPdf("./gData/logs/"+QString::fromStdString(instance)+"/fPage.pdf");
    std::ofstream out("./gData/logs/"+instance+"/report.txt", std::ios_base::app);
    out << "Status: Game Ended Abruptly\n";
    out << "Time Taken: "+c.toStdString()+"\n";
    out << "Start Time: "+aTime+"\n";
    out << "CheckPoint Time: "+cTime+"\n";
    out.close();
    congratsView.initialise(c, QString::fromStdString(this->aTime), QString::fromStdString(cTime), instance,  &(this->chk), 2);
    congratsView.show();
    close();
}
