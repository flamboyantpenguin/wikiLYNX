#include "include/about.h"
#include "ui/ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &about::close);
    connect(ui->showLicense, &QPushButton::clicked, this, &about::showTerms);
}

about::~about()
{
    delete ui;
}


void about::showTerms() {
    termsDialog.show();
}
