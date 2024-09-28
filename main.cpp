#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    QWidget widget;
    widget.show();
    widget.grabKeyboard();
    return a.exec();
}
