#include "include/mainwindow.h"
#include "include/welcome.h"
#include "ui/ui_welcome.h"

#include <fstream>
#include <QDialog>
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDesktopServices>


int totem = 0;
int dontKill = 1;
QApplication *temp;
std::string lVersion("1.1.0");
std::string version("1.1.0");


void checkUpdate();
void downloadUpdate();
void onFocusChanged(QWidget *oldFocus, QWidget *newFocus);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    temp = &a;

    QFontDatabase::addApplicationFont(":/base/fonts/CourierPrime-Bold.ttf");
    QFontDatabase::addApplicationFont(":/base/fonts/CourierPrime-Regular.ttf");
    QFontDatabase::addApplicationFont(":/base/fonts/NotoSans-VariableFont_wdth,wght.ttf");
    QFontDatabase::addApplicationFont(":/base/fonts/NotoSans-Regular.ttf");


    //MainWindow game;

    welcomeUI dialog;
    QObject::connect(&a, &QApplication::focusChanged, onFocusChanged);
    //dialog.setWindowFlag(Qt::FramelessWindowHint);

    checkUpdate();
    dialog.dontKillParse0 = &dontKill;
    dialog.initialise(&totem);
    dialog.show();

    return a.exec();
}


void checkUpdate() {
    QNetworkAccessManager manager;
    QUrl url("https://archive.pcland.co.in/DAWN/Projects/wikiLYNX/.info/version.txt");

    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    temp->connect(reply, &QNetworkReply::finished, [&reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            lVersion = QString::fromLocal8Bit(data).toStdString();

        } else {
            qDebug() << "Error fetching latest version information:" << reply->errorString();
        }

        reply->deleteLater();
    });

    if (strcmp(version.c_str(), lVersion.c_str()) > 0) {
        downloadUpdate();
    }
}


void downloadUpdate() {

    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "wikiLYNX", "New Update Available. Do you want to download?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl("https://archive.pcland.co.in/DAWN/Projects/wikiLYNX"));
    }
}

void onFocusChanged(QWidget *oldFocus, QWidget* newFocus) {
    if(newFocus == nullptr && !dontKill && !totem) {
        //QMessageBox::critical(nullptr, "wikiLYNX", "Game Rule Violiation! You're not allowed to switch windows during game session", QMessageBox::Ok);
        //std::ofstream out("./gData/"+instance+"/report.txt", std::ios_base::app);
        //out << "Status: Policy Violation\n";
        //out.close();
        QApplication::quit();
        return;
    }
}
