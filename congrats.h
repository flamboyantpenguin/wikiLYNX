#ifndef CONGRATS_H
#define CONGRATS_H

#include <QFile>
#include <QDialog>

#include "viewhistory.h"

namespace Ui {
class congrats;
}

class congrats : public QDialog
{
    Q_OBJECT

public:
    explicit congrats(QWidget *parent = nullptr);
    ~congrats();
    int *dontKillMe;
    std::string instanceName;
    void initialise(QString, QString, QString, std::string, int);


private:
    viewHistory hView;
    Ui::congrats *ui;

private slots:
    void viewhistory();
};

#endif // CONGRATS_H
