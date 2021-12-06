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
/**
 * @brief The FenetrePrincipale class la classe qui gère la fenêtre principale
 * @param ui la fenêtre
 * @param basedd la base de donnée qui contient les utilisateurs
 * @param Sharec shareCount
 */
class FenetrePrincipale : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief FenetrePrincipale::FenetrePrincipale le constructeur
     * @param bdd la base de données où les utilisateurs se trouvent
     * @param sc shareCount
     * @param parent
     */
    explicit FenetrePrincipale(BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~FenetrePrincipale();

private slots:
    /**
     * @brief on_pushButton_2_clicked la fonction qui gère le clique du bouton création de compte
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_clicked la fonction qui gère le clique du bouton de connexion
     */
    void on_pushButton_clicked();

private:
    Ui::FenetrePrincipale *ui;
    BaseDeDonnees basedd;
    ShareCount Sharec;
};

#endif // FENETREPRINCIPALE_H
