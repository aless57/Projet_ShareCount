#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include "Utilisateur.h"

#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

using namespace std;

/**
 * @brief The BaseDeDonnees class crée et gère les requêtes sql
 */
class BaseDeDonnees
{
public:
    /**
     * @brief Constructeur de la classe BaseDeDonnees
    * Crée la base de données associée à l'application si elle n'existe pas déjà et la table Utilisateur
    */
    BaseDeDonnees();

    /**
     * @brief BaseDeDonnees::creerBDD la fonction qui crée la base de données associée à l'application si elle n'existe pas déjà et la table Utilisateur
     * @return le code d'erreur
     * 0 si tout est okay
     * 1 si la table n'a pas pu être crée
     * 2 si la bdd a rencontrée un problème lors de l'ouverture
     */
    int creerBDD();

    /**
     * @brief ajouterDonnees la fonction qui ajoute les donnees rentrées par l'utilisateur dans la base de données
     * @param u l'utilisateur
     */
    void ajouterDonnees(Utilisateur u);

    /**
     * @brief ajoute les coordonnées bancaires rentrées par l'utilisateur u
     * @param u l'utilisateur qui rentre ses coordonnées
     */
    void ajouterCoordonneesBancaires(Utilisateur u);
};

#endif // BASEDEDONNEES_H
