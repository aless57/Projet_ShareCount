#ifndef CREATEUSER_H
#define CREATEUSER_H
#include <QPushButton>
#include "affbudget.h"
#include <QLabel>
#include <QDialog>

namespace Ui {
class createUser;
}

class createUser : public QDialog
{
    Q_OBJECT

public:
    explicit createUser(QWidget *parent = nullptr);
    ~createUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createUser *ui;
};

#endif // CREATEUSER_H
