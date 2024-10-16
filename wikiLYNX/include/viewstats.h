#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class viewStats;
}

class viewStats : public QDialog
{
    Q_OBJECT

public:
    explicit viewStats(QWidget *parent = nullptr);
    ~viewStats();

private:
    QJsonObject data;
    int initialise();
    Ui::viewStats *ui;

private slots:
    void loadData();
};

#endif // VIEWSTATS_H
