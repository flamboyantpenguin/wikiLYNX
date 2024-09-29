#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <filesystem>
#include <fstream>
#include <QJsonObject>
#include <QMessageBox>
#include <QThread>
#include <QFile>

#include "viewhistory.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


    int chk = 0;
    int tChk = 0;
    int endTime = 0;
    int countdown = 0;
    QTimer *timer = new QTimer(this);
    std::string instance;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QJsonObject cfg;
    int initialise(QJsonObject*);


private:
    Ui::MainWindow *ui;
    viewHistory historyView;

private slots:
    int launchLogs();
    int missionAccomplished();
    int missionFailed();
    void updateCountdown();
    void initAction();
    //void endGame();
};
#endif // MAINWINDOW_H
