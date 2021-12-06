#ifndef AFFBUDGET_H
#define AFFBUDGET_H
#include "Utilisateur.h"
#include "fenetreprincipale.h"
#include "Sharecount.h"
#include "Basededonnees.h"
#include <QDialog>


namespace Ui {

/**
 *@brief la classe qui gère les affichages dans la fenêtre les données de l'utilisateur
 *@param ui la fenêtre d'affichage
 *@param u l'utilisateur auquel on affiche les informations
 *@param basedd la base de données où se trouve l'utilisateur
 *@param shareC le shareCount de l'application
 */

class AffBudget;
}

class AffBudget : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AffBudget::AffBudget le constructeur de la classe
     * @param user l'utilisateur duquel les informations affichées sont issues
     * @param bdd la base de données où se trouvent les informations de l'utilisateur
     * @param sc classe ShareCount qui va effectuer des actions sur l'utilisateur
     * @param parent
     */
    explicit AffBudget(Utilisateur user, BaseDeDonnees bdd, ShareCount sc, QWidget *parent = nullptr);
    ~AffBudget();

private slots:
    /**
     * @brief on_pushButton_3_clicked, la fonction qui gère l'évenement lorsque l'on clique sur le bouton Déconnection
     */
    void on_pushButton_3_clicked();

private:
    Ui::AffBudget *ui;
    Utilisateur u;
    BaseDeDonnees basedd;
    ShareCount shareC;
};

#endif // AFFBUDGET_H
