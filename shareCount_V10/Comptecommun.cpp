#include "Comptecommun.h"
#include "Utilisateur.h"


/**
 * @brief CompteCommun, le constructeur de la classe compte commun
 * @param u une réference vers l'utilisateur qui va créer le compte commun
*/
CompteCommun::CompteCommun(Utilisateur& u)
{
    contributeurs=QList<Utilisateur>(); ///création de la liste de contributeurs
    contributeurs.append(u);  /// ajout du premier contributeur (le créateur du compte) à la liste des contributeurs
    solde=0;    /// initialisation du solde initial
}

/**
 * @brief ajouterContributeur, fonction qui va ajouter un contributeur dans la liste du compte commun
 * @param u Utilisateur à rajouter
 */
void CompteCommun::ajouterContributeur(Utilisateur& u){
    contributeurs.append(u);
}
