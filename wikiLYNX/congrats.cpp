#include "include/congrats.h"
#include "ui/ui_congrats.h"

//#include "ui_congrats.h"

congrats::congrats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::congrats)
{
    ui->setupUi(this);
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->viewHistory, SIGNAL(clicked()), this, SLOT(viewhistory()));
}

congrats::~congrats()
{
    delete ui;
}


void congrats::initialise(QString c, QString sTime, QString eTime, std::string instance, int *chk, int win) {

    //this->chk = *c;
    //this->tChk = *chk;

    QString m = QString::number(c.toInt()/(60.0));
    this->instanceName = instance;
    ui->timeTaken->setText(m+" minutes ("+c+" seconds) ");
    ui->startTime->setText(sTime);
    ui->endTime->setText(eTime);
    ui->chkCleared->setText(QString::number(*chk));

    if (!win) {
        ui->mainLabel->setText(QString("Mission Failed"));
        ui->message->setText(QString("Oops. Seems you couldn't complete the challenge in time. Try again!"));
    }
    else if (win == 2) {
        ui->mainLabel->setText(QString("Mission Aborted"));
        ui->message->setText(QString("Game ended abruptly."));
    }

}


void congrats::viewhistory() {

    int t;
    QFile lFile("./gData/logs/"+QString::fromStdString(this->instanceName)+"/log.txt");
    lFile.open(QIODevice::ReadOnly);
    auto logs = QString(lFile.readAll());
    lFile.close();
    hView.dontKillMe = (&t);
    hView.initialise(&logs);
    hView.show();
}


void congrats::viewCheckPoints() {

    int t;
    //checkpointView.dontKillMe = (&t);
    //checkpointView.initialise(&cfg, &this->chk, &this->tChk);
    //checkpointView.show();
}
