#ifndef EDITLEVEL_H
#define EDITLEVEL_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <QFile>

#include "editchk.h"

namespace Ui {
class editLevel;
}

class editLevel : public QDialog
{
    Q_OBJECT

public:
    explicit editLevel(QWidget *parent = nullptr);
    ~editLevel();
    //std::map<QString, QJsonObject> uData;
    QJsonObject cfg, data, uData;
    void saveData();
    //void collectData();
    void initialise();


protected:
    void closeEvent(QCloseEvent *event) override {
        this->saveData();
        QDialog::closeEvent(event);

    }

private:
    Ui::editLevel *ui;
    editChk editChkDialog;


private slots:
    void editChkPoint();
    void addLevel();
    void removeLevel();

};

#endif // EDITLEVEL_H
