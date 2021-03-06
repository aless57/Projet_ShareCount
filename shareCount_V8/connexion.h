#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "affbudget.h"

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    ~Connexion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Connexion *ui;
};

#endif // CONNEXION_H
