
#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>
#include "affbudget.h"
#include "Basededonnees.h"
#include "Sharecount.h"

namespace Ui {
class Connexion;
}
/**
 * @brief Connexion, la classe qui gère le cas où un utilisateur se connecte à l'application
 * @param ui, la fenêtre
 * @param shareC, shareCount
 * @param basebdd, la base de donnée où se trouve le compte de l'utilisateur
 */
class Connexion : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Connexion::Connexion le constructeur de la classe
     * @param bdd, la base de données sur laquelle l'utilisateur se connecte
     * @param s, classe ShareCount qui va effectuer des actions sur l'utilisateur
     * @param parent
     */
    explicit Connexion(BaseDeDonnees bdd, ShareCount s, QWidget *parent = nullptr);
    ~Connexion();

private slots:
    /**
     * @brief on_pushButton_clicked, la fonction qui gère l'évenement lorsque l'on clique sur le bouton Connect
     */
    void on_pushButton_clicked();

private:
    Ui::Connexion *ui;
    ShareCount shareC;
    BaseDeDonnees basedd;
};

#endif // CONNEXION_H
