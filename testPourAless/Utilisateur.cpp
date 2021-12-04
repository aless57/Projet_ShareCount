#include "Utilisateur.h"

/**
 * @brief Constructeur de la classe Utilisateur
 * @param n : le nom de l'utilisateur
 * @param p : le prenom de l'utilisateur
 * @param m : le mail de l'utilisateur
 * @param num : le numero de telephone de l'utilisateur
 * @param mdp : mot de passe de l'utilisateur
 */
Utilisateur::Utilisateur(QString m,QString n,QString p,QString mdp,QString num){
    nom=n;
    prenom=p;
    mail=m;
    numeroTelephone=num;
    motDePasse=mdp;
}

/**
 * @brief ajouterIBAN ajoute l'iban de l'utilisateur
 * @param ib l'iban de l'utilisateur
 */
void Utilisateur::ajouterIBAN(QString ib){
    iban=ib;
}
