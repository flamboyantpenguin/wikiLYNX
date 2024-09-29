#include "viewhistory.h"
#include "ui_viewhistory.h"

viewHistory::viewHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewHistory)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(close()));

}

viewHistory::~viewHistory()
{
    delete ui;
}


int viewHistory::initialise(QString *data) {
    ui->textBrowser->setText(*data);
    return 0;
}
