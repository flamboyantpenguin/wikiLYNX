#include "include/viewstats.h"
#include "ui/ui_viewstats.h"

viewStats::viewStats(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewStats)
{
    ui->setupUi(this);
    this->initialise();
    connect(ui->closeButton, &QPushButton::clicked, this, &viewStats::close);
    connect(ui->levelSelect, &QComboBox::currentIndexChanged, this, &viewStats::loadData);
}

viewStats::~viewStats()
{
    delete ui;
}


int viewStats::initialise() {

    QFile statFile("./gData/.stat");
    statFile.open(QIODevice::ReadOnly);
    this->data = QJsonDocument::fromJson(statFile.readAll()).object();
    ui->levelSelect->addItems(data.keys());
    statFile.close();
    return 0;
}


void viewStats::loadData() {

    auto level = ui->levelSelect->currentText();

    QJsonObject leaderBoard = this->data.value(level).toObject();


    //ui->table->clear();
    //*(dontKillMe) = 1;
    ui->table->setRowCount(leaderBoard.count());
    //auto header = ui->table->horizontalHeader();

    //ui->table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    int i = 0;
    QStringList keys = leaderBoard.keys();
    for (const QString& key : keys) {
        QTableWidgetItem* timeTaken = new QTableWidgetItem();
        QTableWidgetItem* playerName = new QTableWidgetItem();
        timeTaken->setText(key);
        playerName->setText(leaderBoard[key].toString());
        ui->table->setItem(i, 0, timeTaken);
        ui->table->setItem(i, 1, playerName);
        i++;
        //qDebug() << key << ": " << value;
    }

    ui->table->sortByColumn(ui->table->columnAt(0), Qt::AscendingOrder);

}
