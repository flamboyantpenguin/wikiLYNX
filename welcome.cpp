#include "welcome.h"
//#include "./ui_mainwindow.h"


welcomeUI::welcomeUI(QDialog *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.initButton, &QPushButton::clicked, this, &welcomeUI::startGame);
    connect(ui.termsButton, &QPushButton::clicked, this, &welcomeUI::showTerms);
    connect(ui.rulesButton, &QPushButton::clicked, this, &welcomeUI::showRules);
    connect(ui.settingsButton, &QPushButton::clicked, this, &welcomeUI::editSettings);
    connect(ui.feedbackButton, &QPushButton::clicked, this, &welcomeUI::launchFeedback);
    connect(ui.passcodeInput, &QLineEdit::returnPressed, this, &welcomeUI::startGame);
    //QFont fnt("Mukta", 24, QFont::Bold);
    //ui.label->setFont(fnt);
    //ui.label->setText(QString("yyyyy"));

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
    int ald = data["allowOtherDomains"].toInt();
    //auto domain = data["domain"].toString();
    auto domain = QString::fromStdString("https://en.wikipedia.org");
    auto temp = data["data"].toObject()[passcode].toObject();
    game.initialise(&temp, dontKillParse0, domain, ald);
    *dontKillParse0 = 0;
    game.showFullScreen();
    QApplication::processEvents();
    return 0;

}


void welcomeUI::showRules(){
    QMessageBox::information(this, "wikiLYNX", "Ask the invigilator mate!", QMessageBox::Ok);
}


void welcomeUI::showTerms() {
    QMessageBox::information(this, "wikiLYNX", "We are not sponsored by a lawyer!", QMessageBox::Ok);
}


void welcomeUI::editSettings() {
    QMessageBox::information(this, "wikiLYNX", "Coming soon...", QMessageBox::Ok);
}


void welcomeUI::launchFeedback() {
    QDesktopServices::openUrl(QUrl(QString("https://forms.gle/DgXAhsqZ2ct7D6dM6")));
}
