#include <QDialog>
#include "affbudget.h"
#include "Basededonnees.h"
#include "Sharecount.h"
#ifndef CONNEXION_H
#define CONNEXION_H



namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(BaseDeDonnees bdd, ShareCount s, QWidget *parent = nullptr);
    ~Connexion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Connexion *ui;
    ShareCount shareC;
    BaseDeDonnees basedd;
};

#endif // CONNEXION_H
