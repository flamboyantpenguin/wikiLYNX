#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filesystem>
#include <fstream>
#include <QJsonObject>
#include <QMessageBox>
#include <QFile>
#include <QTimer>

#include "congrats.h"
#include "viewhistory.h"
#include "viewcheckpoint.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


    int chk = 0;
    int alD = 1;
    int tChk = 0;
    std::string domain;
    int endTime = 0;
    int cCount = 0;
    float countdown = 0;
    std::string aTime;
    std::string cTime;
    QTimer *timer = new QTimer(this);
    std::string instance;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QJsonObject cfg;
    int *dontKillMe;
    int initialise(QJsonObject*, int*, QString, int);


private:
    Ui::MainWindow *ui;
    congrats congratsView;
    viewHistory historyView;
    viewcheckpoint checkpointView;

private slots:
    void launchLogs();
    void viewCheckPoints();
    int missionAccomplished();
    int missionFailed();
    void updateCountdown();
    void initAction();
    void endGame();

};

#endif // MAINWINDOW_H
