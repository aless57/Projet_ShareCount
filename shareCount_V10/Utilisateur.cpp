#include "Utilisateur.h"
#include "Comptecommun.h"
#include "Basededonnees.h"

/**
 * @brief Constructeur de la classe Utilisateur
 * @param n : le nom de l'utilisateur
 * @param p : le prenom de l'utilisateur
 * @param m : le mail de l'utilisateur
 * @param num : le numero de telephone de l'utilisateur
 * @param mdp : mot de passe de l'utilisateur
 */
Utilisateur::Utilisateur(QString n,QString p,QString m,QString num,QString mdp, BaseDeDonnees bdd){
    nom=n;
    prenom=p;
    mail=m;
    numeroTelephone=num;
    motDePasse=mdp;
    comptesCommuns=QList<CompteCommun>();
    baseDeDonnees=bdd;
}

/**
 * @brief ajouterIBAN ajoute l'iban de l'utilisateur
 * @param ib l'iban de l'utilisateur
 */
void Utilisateur::ajouterIBAN(QString ib){
    iban=ib;
}

/**
 * @brief ajouterContributeur,
 * @param u
 */
void Utilisateur::ajouterContributeur(Utilisateur& u,CompteCommun& c){
    c.ajouterContributeur(u);
    baseDeDonnees.ajouterContributeur(c,u);
}

/**
 * @brief freeListeComptesCommuns, la fonction qui libère l'espace mémoire utilisée par la liste de comptes communs
 */
void Utilisateur::freeListeComptesCommuns(){
    if(!comptesCommuns.isEmpty()){  ///si la liste n'est pas vide, on la libère
        comptesCommuns.clear();
    }
}

/**
 * @brief creerCompteCommun, la fonction qui permet à l'utilisateur de créer un compte commun
 */
void Utilisateur::creerCompteCommun(){
    comptesCommuns.append(*new CompteCommun(*this));///ajoute le compte commun crée à la liste des comptes communs de l'utilisateur
    baseDeDonnees.ajouterCompteCommun(*this);
}

