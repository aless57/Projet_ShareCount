#include <iostream>
#include <QList>
#include <QSharedPointer>
#include "Utilisateur.h"

#ifndef COMPTECOMMUN_H
#define COMPTECOMMUN_H

/**
 * @brief le classe qui représente un compte commun
 * @param contributeurs, la liste des utilisateurs ayant accès au compte commun
 * @param solde, le solde du compte commun, initialisé à 0 au début
 */
class CompteCommun
{
private:
    QList<Utilisateur> contributeurs;
    int solde;
public:

    /**
     * @brief CompteCommun, le constructeur de la classe compte commun
     * @param u une réference vers l'utilisateur qui crée le compte commun
     */
    CompteCommun(Utilisateur& u);

};

#endif // COMPTECOMMUN_H
