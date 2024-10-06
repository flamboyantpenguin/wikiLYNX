#ifndef EDITCHK_H
#define EDITCHK_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QJsonObject>

namespace Ui {
class editChk;
}

class editChk : public QDialog
{
    Q_OBJECT

public:
    explicit editChk(QWidget *parent = nullptr);
    QString code;
    QJsonObject *chkData;
    void saveData();
    void initialise(QJsonObject *, QString);
    ~editChk();

protected:
    void closeEvent(QCloseEvent *event) override {
        this->saveData();
        QDialog::closeEvent(event);

    }


private:
    Ui::editChk *ui;

private slots:
    void addChk();
    void removeChk();

};

#endif // EDITCHK_H
