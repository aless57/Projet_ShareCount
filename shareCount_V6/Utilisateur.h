#include <iostream>
#include <QString>

#ifndef UTILISATEUR_H
#define UTILISATEUR_H



/**
 * @brief La classe représentant un utilisateur de l'application
 * @param nom de l'utilisatur
 * @param prenom de l'utilisateur
 * @param iban du compte bancaire de l'utilisateur
 * @param mail de l'utilisateur
 * @param numeroTelephone de l'utilisateur
 * @param motDePasse de l'utilisateur
 * @param shareCount
 */

class Utilisateur{

private:
    QString nom;
    QString prenom;
    QString iban;
    QString mail;
    QString numeroTelephone;
    QString motDePasse;

public:

    /**
     * @brief Constructeur de la classe Utilisateur
     * @param n : le nom de l'utilisateur
     * @param p : le prenom de l'utilisateur
     * @param m : le mail de l'utilisateur
     * @param num : le numero de telephone de l'utilisateur
     * @param mdp : mot de passe de l'utilisateur
     */

    Utilisateur(QString n,QString p,QString m,QString num,QString mdp);

    /**
     * @brief getNom, retourne le nom de l'utilisateur
     * @return nom, le nom de l'utilisateur
     */
    QString getNom(){return nom;}

    /**
     * @brief getPrenom, retourne le prenom de l'utilisateur
     * @return prenom, le prenom de l'utilisateur
     */
    QString getPrenom(){return prenom;}

    /**
     * @brief getMail, retourne le mail de l'utilisateur
     * @return mail, le mail de l'utilisateur
     */
    QString getMail(){return mail;}

    /**
     * @brief getNumeroTelephone, retourne le numero de telephone de l'utilisateur
     * @return numeroTelephone, le numero de telephone de l'utilisateur
     */
    QString getNumeroTelephone(){return numeroTelephone;}

    /**
     * @brief getMotDePasse, retourne le mot de passe de l'utilisateur
     * @return motDePasse, le mot de passe de l'utilisateur
     */
    QString getMotDePasse(){return motDePasse;}

    /**
     * @brief ajouterIBAN ajoute l'iban de l'utilisateur
     * @param ib l'iban de l'utilisateur
     */
    void ajouterIBAN(QString ib);


    /**
     * @brief getIBAN, retourne l'iban de l'utilisateur
     * @return iban,l'iban de l'utilisateur
     */
    QString getIBAN(){return iban;}


};

#endif // UTILISATEUR_H
