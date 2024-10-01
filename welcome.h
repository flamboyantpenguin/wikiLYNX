#include <json/value.h>
#include <fstream>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QResource>
#include <QMessageBox>
#include <QDesktopServices>
#include <QString>

#include "ui_welcome.h"
#include "mainwindow.h"


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
    void showRules();
    void showTerms();
    void editSettings();
    void launchFeedback();


private:
    MainWindow game;
    Ui::welcomeDialog ui;

};
