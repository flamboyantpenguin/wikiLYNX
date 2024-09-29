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
    int countdown = 0;
    std::string instance;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QJsonObject cfg;
    int initalise(QJsonObject*);


private:
    Ui::MainWindow *ui;

private slots:
    void updateCountdown();
    void initAction();
    //void endGame();
};
#endif // MAINWINDOW_H
