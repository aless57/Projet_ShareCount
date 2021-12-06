#ifndef FENETRECREATIONUTILISATEUR_H
#define FENETRECREATIONUTILISATEUR_H

#include <QPushButton>
#include "affbudget.h"
#include <QLabel>
#include <QDialog>
#include "Basededonnees.h"
#include "Utilisateur.h"
#include "Sharecount.h"

namespace Ui {
class FenetreCreationUtilisateur;
}

class FenetreCreationUtilisateur : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreCreationUtilisateur(BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~FenetreCreationUtilisateur();

private slots:
    void on_pushButton_clicked();

private:
    BaseDeDonnees basedd;
    ShareCount Sharec;
    Ui::FenetreCreationUtilisateur *ui;
};

#endif // FENETRECREATIONUTILISATEUR_H
