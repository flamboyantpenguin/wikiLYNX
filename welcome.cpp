#include "welcome.h"

//#include "./ui_mainwindow.h"


welcomeUI::welcomeUI(QDialog *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.initButton, &QPushButton::clicked, this, &welcomeUI::startGame);
    connect(ui.passcodeInput, &QLineEdit::returnPressed, this, &welcomeUI::startGame);

}


int welcomeUI::startGame() {

    QFile cFile(":/cfg/gameData.json");
    cFile.open(QIODevice::ReadOnly);
    QString passcode = ui.passcodeInput->text();
    data = QJsonDocument::fromJson(cFile.readAll()).object();
    cFile.close();

    if (!data["data"].toObject().contains(passcode)) {
        QMessageBox::critical(this, "wikiLYNX", "Invalid Code!", QMessageBox::Ok);
        return 1;
    }

    this->grabKeyboard();
    this->hide();
    auto temp = data["data"].toObject()[passcode].toObject();
    game.initialise(&temp, dontKillParse0);
    *dontKillParse0 = 0;
    game.showFullScreen();
    //QApplication::setOverrideCursor(Qt::BusyCursor);
    QApplication::processEvents();
    return 0;

}
