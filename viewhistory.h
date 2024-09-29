#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H

#include <QDialog>

namespace Ui {
class viewHistory;
}

class viewHistory : public QDialog
{
    Q_OBJECT

public:
    explicit viewHistory(QWidget *parent = nullptr);
    ~viewHistory();
    int initialise(QString*);

private:
    Ui::viewHistory *ui;
};

#endif // VIEWHISTORY_H
