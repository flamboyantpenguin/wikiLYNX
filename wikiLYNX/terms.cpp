#include "include/terms.h"
#include "ui/ui_terms.h"


terms::terms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::terms)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &terms::close);
    this->initialise();

}


terms::~terms()
{
    delete ui;
}


void terms::initialise() {

    QFile f(":/base/info/LICENSE.txt");
    f.open(QIODevice::ReadOnly);
    auto license = QString(f.readAll());
    f.close();
    ui->licenseView->setText(license);

    QFile c(":/base/info/COPYING.txt");
    c.open(QIODevice::ReadOnly);
    auto copying = QString(c.readAll());
    c.close();
    ui->copyingView->setText(copying);

}
