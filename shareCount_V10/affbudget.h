#ifndef AFFBUDGET_H
#define AFFBUDGET_H
#include "Utilisateur.h"
#include "fenetreprincipale.h"
#include "Sharecount.h"
#include "Basededonnees.h"
#include <QDialog>

namespace Ui {
class AffBudget;
}

class AffBudget : public QDialog
{
    Q_OBJECT

public:
    explicit AffBudget(Utilisateur user, BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~AffBudget();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::AffBudget *ui;
    Utilisateur u;
    BaseDeDonnees basedd;
    ShareCount shareC;
};

#endif // AFFBUDGET_H
