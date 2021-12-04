#include "Comptecommun.h"


/**
 * @brief CompteCommun, le constructeur de la classe compte commun
 * @param u une réference vers l'utilisateur qui crée le compte commun
*/
CompteCommun::CompteCommun(Utilisateur& u)
{
    contributeurs=QList<Utilisateur>(); ///crée la liste de contributeurs
    contributeurs.append((&u));  ///ajoute le premier contributeur (le créateur du compte) à la liste des contributeurs
    solde=0;    ///le solde initial
}
