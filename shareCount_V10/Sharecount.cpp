#include "Sharecount.h"
using namespace std;
/**
 * @brief constructeur de la classe ShareCount
 */
ShareCount::ShareCount(BaseDeDonnees bdd){
    listeUtilisateur=QList<Utilisateur>();
    baseDeDonnees=bdd;
}

/**
 * @brief getter de la liste des utilisateurs
 * @return la liste des utilisateurs
 */
QList<Utilisateur> ShareCount::getListeUtilisateur(){
    return listeUtilisateur;
}


/**
* @brief ajoute un utilisateur à la collection et à la base de données
* @param u l'utilisateur à ajouter
*/
bool ShareCount::ajouterUtilisateur(Utilisateur u){
    bool test = baseDeDonnees.ajouterDonnees(u);

    if(test){
        listeUtilisateur.append(u); ///ajoute l'utilisateur u à la liste d'utilisateur
    }
    return test;

}

/**
* @brief ajout d'un utilisateur dans la liste des utilisateurs sans le faire dans la base de données
* @param l'utilisateur à ajouter
*/
void ShareCount::setUtilisateur(Utilisateur u) {
    listeUtilisateur.append(u); ///ajoute l'utilisateur u à la liste d'utilisateur
}

/**
* @brief vérifie le format d'un mail
* le format accepté est
* aa@bb.cc
* @param m un mail
*/
bool ShareCount::verifierFormatMail(QString m){
    /// initialisation de la variable de retours
    bool res = false;
    ///Regex correspondant au format d'un mail
    QRegularExpression mailRegex("[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}");

    if(m.contains(mailRegex)){ ///le mail a le bon format
        std::cout << "email valide" << std::endl;
        res = true;
    }else{ ///le mail n'a pas le bon format
        std::cout << "email non valide" << std::endl;
    }
    return res;
}

/**
* @brief vérifie le format d'un numero de telephone
* les formats acceptés sont:
*  0 + 9 chiffres
* ou +33 + 8 chiffres
* @param tel, un numero de telephone
*/
bool ShareCount::verifierFormatTelephone(QString tel){
    bool res = false;
    ///Regex correspondant au format de téléphone accepté
    QRegularExpression telRegex("(0|\\+33)[1-9][0-9]{8}");

    if(tel.contains(telRegex)){ ///le numéro a le bon format
        res = true;
        std::cout << "numéro de téléphone valide" << std::endl;
    }else{ ///le numéro n'a pas le bon format
        std::cout <<"numéro de téléphone non valide" << std::endl;
    }
    return res;
}

/**
* @brief verifie si le mail donné en paramètre est déjà utilisé par un autre utilisateur
* @param m un mail
*/
void ShareCount::mailEstLibre(QString m){
    foreach (Utilisateur u, listeUtilisateur) {
        if(u.getMail().contains(m)){
            std::cout << "l'adresse mail est déjà utilisée" << std::endl;
        }
    }

}
