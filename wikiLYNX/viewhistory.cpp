#include "include/viewhistory.h"
#include "ui/ui_viewhistory.h"


viewHistory::viewHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewHistory)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));

}


viewHistory::~viewHistory()
{
    delete ui;
}


void viewHistory::initialise(QString *data) {
    ui->textBrowser->setText(*data);
}
