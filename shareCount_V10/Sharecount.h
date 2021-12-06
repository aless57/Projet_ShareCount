

#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <iostream>
#include <QString>
#include <QList>
#include <QRegularExpression>
#include "Utilisateur.h"
#include "Basededonnees.h"

/**
 * @brief The ShareCount class
 * @param listeUtilisateur l'ensemble des utlisateurs de l'application
 */

class ShareCount
{
protected:
    QList<Utilisateur> listeUtilisateur;
    BaseDeDonnees baseDeDonnees;

public:

    /**
     * @brief constructeur de la classe ShareCount
     */
    ShareCount(BaseDeDonnees bdd);

    /**
     * @brief getter de la liste des utilisateurs
     * @return la liste des utilisateurs
     */
    QList<Utilisateur> getListeUtilisateur();

    /**
     * @brief ajout d'un utilisateur dans la liste des utilisateurs sans le faire dans la base de données
     * @param l'utilisateur à ajouter
     */
    void setUtilisateur(Utilisateur u);

    /**
    * @brief ajoute un utilisateur à la collection et à la base de données
    * @param u l'utilisateur à ajouter
    */
    bool ajouterUtilisateur(Utilisateur u);

    /**
    * @brief vérifie le format d'un mail
    * le format accepté est
    * aa@bb.cc
    * @param m un mail
    */
    bool verifierFormatMail(QString m);

    /**
    * @brief vérifie le format d'un numero de telephone
    * les formats acceptés sont:
    *  0 + 9 chiffres
    * ou +33 + 8 chiffres
    * @param tel, un numero de telephone
    */
    bool verifierFormatTelephone(QString tel);

    /**
    * @brief verifie si le mail donné en paramètre est déjà utilisé par un autre utilisateur
    * @param m un mail
    */
    void mailEstLibre(QString m);





};

#endif // SHARECOUNT_H
