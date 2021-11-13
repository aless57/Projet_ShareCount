#ifndef SHARECOUNT_H
#define SHARECOUNT_H

#include <iostream>
#include <QString>
#include <QList>
#include "Utilisateur.h"

/**
 * @brief The ShareCount class
 * @param listeUtilisateur l'ensemble des utlisateurs de l'application
 */

class ShareCount
{
private:
    QList<Utilisateur> listeUtilisateur;

public:

    /**
     * @brief constructeur de la classe ShareCount
     */
    ShareCount();

    /**
     * @brief ajoute un utilisateur à la collection
     * @param u un utilisateur
     */
    void ajouterUtilisateur(Utilisateur u);

    /**
     * @brief verifie le format d'un mail
     * @param m un mail
     */
    void verifierFormatMail(QString m);

    /**
     * @brief verifie le format d'un numero de telephone
     * @param tel un numero de telephone
     */
    void verifierFormatTelephone(QString tel);

    /**
     * @brief verifie si le mail donné en parametre est deja utilise par un autre utilisateur
     * @param m un mail
     */
    void mailEstLibre(QString m);




};

#endif // SHARECOUNT_H
