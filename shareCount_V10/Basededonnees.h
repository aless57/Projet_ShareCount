#include"Utilisateur.h"
#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>


using namespace std;

/**
 * @brief The BaseDeDonnees class crée et gère les requêtes sql
 */
class BaseDeDonnees
{
public:
    /**
     * @brief Constructeur de la classe BaseDeDonnees
    */
    BaseDeDonnees();

    /**
     * @brief BaseDeDonnees::creerBDD la fonction qui créée la base de données associée à l'application si elle n'existe pas déjà et la table Utilisateur
     * @return le code d'erreur
     * 0 si l'opération s'est bien déroulée
     * 1 si la table n'a pas pu être créée
     * 2 si la bdd a rencontrée un problême lors de l'ouverture
     */
    int creerBDD();

    /**
     * @brief ajouterDonnees la fonction qui ajoute les données rentrées par l'utilisateur dans la base de données
     * @param u l'utilisateur
     * @return true (1) si la requête a été effectuée
     *         false (0) sinon
     */
    bool ajouterDonnees(Utilisateur u);

    /**
    * @brief ajoute les coordonnées bancaires rentrées par l'utilisateur u
    * @param u l'utilisateur qui rentre ses coordonnées
    */
    void ajouterCoordonneesBancaires(Utilisateur u);

    /**
     * @brief trouverUtilisateur, permet de récupérer et créer un utilisateur grâce à son mail et son mdp passés en paramètre
     * @param mail, le mail rentré par l'utilisateur
     * @param mdp, le mot de passe rentré par l'utilisateur
     * @return Utilisateur* u
     */
    Utilisateur trouverUtilisateur(QString mail, QString mdp);

    /**
     * @brief connexionReussie, vérifie si l'utilisateur correspond aux données rentrées en paramètre
     * @param mail, le mail rentré par l'utilisateur
     * @param mdp, le mot de passe rentré par l'utilisateur
     * @return true (1) si  l'utilisateur a bien été trouvé grâce au mail et au mdp rentrés en paramètre
     *         false (0) sinon
     */
    bool connexionReussie(QString mail, QString mdp);

    /**
     * @brief creerTableCompteCommun, la fonction qui crée la table CompteCommun dans la bdd
     */
    void creerTableCompteCommun();

    /**
     * @brief ajouterCompteCommun, ajoute un champ et un compte commun à la table Utilisateur, à la ligne de u
     * @param u l'utilistateur auquel on ajoute un compte commun
     */
    void ajouterCompteCommun(Utilisateur u);

    /**
     * @brief ajouterContributeur, ajoute un champ et un utilisateur (contributeur) à la table CompteCommun, à la ligne de c
     * @param c le compte commun auquel on ajute un contributeur u
     */
    void ajouterContributeur(CompteCommun c, Utilisateur u);
};

#endif // BASEDEDONNEES_H
