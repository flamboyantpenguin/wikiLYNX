#include "include/terms.h"
#include "ui/ui_terms.h"


terms::terms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::terms)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &terms::close);
    QFile f(":/base/info/wikipedia.txt");
    f.open(QIODevice::ReadOnly);
    auto terms = QString(f.readAll());
    f.close();
    QFile t(":/base/info/license.txt");
    t.open(QIODevice::ReadOnly);
    terms += "\n\n"+QString(t.readAll());
    t.close();
    ui->mainView->setText(terms);
}


terms::~terms()
{
    delete ui;
}
