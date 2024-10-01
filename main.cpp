#include "mainwindow.h"
#include "ui_welcome.h"
#include "welcome.h"

#include <QDialog>
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>


int dontKill = 1;


void onFocusChanged(QWidget *oldFocus, QWidget *newFocus);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/*.ttf");
    //MainWindow game;

    welcomeUI dialog;
    QObject::connect(&a, &QApplication::focusChanged, onFocusChanged);
    //dialog.setWindowFlag(Qt::FramelessWindowHint);
    dialog.dontKillParse0 = &dontKill;
    dialog.show();

    return a.exec();
}


void onFocusChanged(QWidget *oldFocus, QWidget* newFocus) {
    if(newFocus == nullptr && !dontKill) {
        //QMessageBox::critical(nullptr, "wikiLYNX", "Game Rule Violiation! You're not allowed to switch windows during game session", QMessageBox::Ok);
        QApplication::quit();
        return;
    }
}
