#include "ui_welcome.h"
#include "mainwindow.h"
#include <json/value.h>
#include <fstream>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QResource>


class welcomeUI : public QDialog
{
    Q_OBJECT

public:
    explicit welcomeUI(QDialog *parent = nullptr);

    int *dontKillParse0;
    QJsonObject data, instance;
    //Json::Value cfg;

private slots:
   int startGame();

private:
    MainWindow game;
    Ui::welcomeDialog ui;

};
