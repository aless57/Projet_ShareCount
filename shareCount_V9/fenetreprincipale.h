#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include "fenetrecreationutilisateur.h"
#include "connexion.h"
#include "Basededonnees.h"
#include "Sharecount.h"
#include <QDialog>

namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QDialog
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~FenetrePrincipale();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FenetrePrincipale *ui;
    BaseDeDonnees basedd;
    ShareCount Sharec;
};

#endif // FENETREPRINCIPALE_H
