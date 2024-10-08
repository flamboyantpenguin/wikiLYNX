#include <json/value.h>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QResource>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QDesktopServices>
#include <QDir>


#include "help.h"
#include "about.h"
#include "editlevel.h"
#include "mainwindow.h"

namespace Ui {
class welcomeDialog;
}

class welcomeUI : public QDialog
{
    Q_OBJECT


public:
    explicit welcomeUI(QDialog *parent = nullptr);

    int initialise(int*);

    int *dontKillParse0;
    int aRD = 0;
    int *totemofUndying;
    QJsonObject data, cfg;
    //Json::Value cfg;


private slots:
    void showAbout();
    void showLogs();
    void clearLogs();
    int startGame();
    void updateUI();
    void loadSettings();
    void updateSettings();
    void saveSettings();
    void checkCustom();
    void addCustom();
    void showLevelInfo();
    void showRules();


private:
    MainWindow game;
    help helpDialog;
    about aboutDialog;
    editLevel editDialog;
    Ui::welcomeDialog *ui;

};
