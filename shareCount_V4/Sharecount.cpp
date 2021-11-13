#include "Sharecount.h"
using namespace std;
/**
 * @brief constructeur de la classe ShareCount
 */
ShareCount::ShareCount(){}

/** @brief ajoute un utilisateur à la collection
* @param u un utilisateur
*/
void ajouterUtilisateur(Utilisateur u){
   // listeUtilisateur.append(u); ///ajoute l'utilisateur u à la liste d'utilisateur

}

/**
* @brief verifie le format d'un mail
* le format accepté est
* aa@bb.cc
* @param m un mail
*/
void verifierFormatMail(QString m){
    ///Regex correspondant au format d'un mail
    /*QRegExp mailRegex("[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}");

    if(m.contains(mailRegex)){ //le mail a le bon format
        std::cout << "email valide" << std::endl;
    }else{ ///le mail n'a pas le bon format
        std::cout << "email non valide" << std::endl;
    }*/
}

/**
* @brief verifie le format d'un numero de telephone
* les formats acceptés sont:
*  0 + 9 chiffres
* ou +33 + 8 chiffres
* @param tel un numero de telephone
*/
void verifierFormatTelephone(QString tel){
    ///Regex correspondant au format de téléphone accepté
    /*QRegExp telRegex("(0|\\+33)[1-9][0-9]{8}");

    if(tel.contains(telRegex)){ //le numéro a le bon format
        std::cout << "numéro de téléphone valide" << std::endl;
    }else{ ///le numéro n'a pas le bon format
        std::cout <<"numéro de téléphone non valide" << std::endl;
    }*/

}

/**
* @brief verifie si le mail donné en parametre est deja utilise par un autre utilisateur
* @param m un mail
*/
void mailEstLibre(QString m){
   /* foreach (Utilisateur u, listeUtilisateur) {
        if(u.getMail().contains(m)){
            std::cout << "l'adresse mail est déjà utilisée" << std::endl;
        }
    }*/

}
