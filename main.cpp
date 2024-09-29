#include "mainwindow.h"
#include "ui_welcome.h"
#include "welcome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow game;

    welcomeUI dialog;
    dialog.setWindowFlag(Qt::FramelessWindowHint);
    dialog.show();
    //game.showFullScreen();
    //QDialog dialog;
    //Ui::welcomeDialog wld;
    //wld.setupUi(&dialog);


    //dialog.grabKeyboard();
    return a.exec();
}


