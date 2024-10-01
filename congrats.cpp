#include "congrats.h"
#include "ui_congrats.h"

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


void congrats::initialise(QString c, QString sTime, QString eTime, std::string instance, int win) {

    QString m = QString::number(c.toInt()/(60.0));
    this->instanceName = instance;
    ui->timeTaken->setText(m+" minutes ("+c+") seconds");
    ui->startTime->setText(sTime);
    ui->endTime->setText(eTime);

    if (!win) {
        ui->mainLabel->setText(QString("Mission Failed"));
        ui->message->setText(QString("Oops. Seems you couldn't complete the challenge in time. Try again!"));
    }

}


void congrats::viewhistory() {

    int t;
    QFile lFile("./wikiLYNX/"+QString::fromStdString(this->instanceName)+"/log.txt");
    lFile.open(QIODevice::ReadOnly);
    auto logs = QString(lFile.readAll());
    lFile.close();
    hView.dontKillMe = (&t);
    hView.initialise(&logs);
    hView.show();
}
