
#ifndef COMPTECOMMUN_H
#define COMPTECOMMUN_H

#include <iostream>
#include <QList>
#include <QSharedPointer>

class Utilisateur;
using namespace std;

/**
 * @brief le classe qui représente un compte commun
 * @param contributeurs, la liste des utilisateurs ayant accès au compte commun
 * @param solde, le solde du compte commun, initialisé à 0
 */
class CompteCommun
{
private:
    QList<Utilisateur> contributeurs;
    int solde;
public:

    /**
     * @brief CompteCommun, le constructeur de la classe compte commun
     * @param u une réference vers l'utilisateur qui va créer le compte commun
    */
    CompteCommun(Utilisateur& u);

    /**
     * @brief ajouterContributeur, fonction qui va ajouter un contributeur dans la liste du compte commun
     * @param u Utilisateur à rajouter
     */
    void ajouterContributeur(Utilisateur& u);

};

#endif // COMPTECOMMUN_H
