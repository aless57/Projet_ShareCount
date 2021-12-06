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
/**
 * @brief The FenetreCreationUtilisateur class la classe qui gère la fenêtre de la création d'un compte
 * @param basebdd la base de données où on va ajouter les données d'un nouvel utilisateur
 * @param Sharec shareCount
 * @param ui la fenêtre representant la création de compte
 */
class FenetreCreationUtilisateur : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief FenetreCreationUtilisateur::FenetreCreationUtilisateur le constructeur de la classe
     * @param bdd la base de données où on ajoute les données du nouvel utilisateur
     * @param sc shareCount
     * @param parent
     */
    explicit FenetreCreationUtilisateur(BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~FenetreCreationUtilisateur();

private slots:
    /**
     * @brief on_pushButton_clicked la fonction qui gère le clique du bouton
     */
    void on_pushButton_clicked();

private:
    BaseDeDonnees basedd;
    ShareCount Sharec;
    Ui::FenetreCreationUtilisateur *ui;
};

#endif // FENETRECREATIONUTILISATEUR_H
