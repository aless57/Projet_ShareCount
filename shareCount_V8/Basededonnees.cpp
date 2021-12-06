#include "Basededonnees.h"
#include "QSqlError"

/**
 * @brief Constructeur de la classe BaseDeDonnees
*/
BaseDeDonnees::BaseDeDonnees()
{}

/**
 * @brief BaseDeDonnees::creerBDD la fonction qui crée la base de données associée à l'application si elle n'existe pas déjà et la table Utilisateur
 * @return le code d'erreur
 * 0 si tout est okay
 * 1 si la table n'a pas pu être crée
 * 2 si la bdd a rencontrée un problème lors de l'ouverture
 */
int BaseDeDonnees::creerBDD(){
    int r=0;
    ///cré la base de données dans le répertoire
    QSqlDatabase bdd=QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("../bdd.db");
    if(bdd.open()){ ///ouvre la base de données
        std::cout <<"Le fichier de la bdd est ouvert" << std::endl;
        QSqlQuery query(bdd);
        ///crée la table utilisateur si elle n'existe pas déjà
        if(query.exec("CREATE TABLE IF NOT EXISTS Utilisateur(mail VARCHAR(50) NOT NULL,nom VARCHAR(50) NOT NULL,prenom VARCHAR(50) NOT NULL,motDePasse VARCHAR(50) NOT NULL,numeroTelephone VARCHAR(50) NOT NULL,iban VARCHAR(100),PRIMARY KEY(mail));"
                      )){
            std::cout << "Table Utilisateur créée " << std::endl;
        }else{  ///la reqête de création de table à échouée
            r=1;
        }
    }else{
        r=2;    ///l'ouverture de la base de données à échouée
    }
    return r;   ///le code d'erreur
}

/**
 * @brief ajouterDonnees la fonction qui ajoute les donnees rentrées par l'utilisateur dans la base de données
 * @param u l'utilisateur
 */
void BaseDeDonnees::ajouterDonnees(Utilisateur u){
    QSqlQuery query;
    ///la requete sql pour ajouter un utilisateur dans la table Utilisateur
    QString requete="INSERT INTO UTILISATEUR (mail,nom,prenom,motDePasse,numeroTelephone) VALUES ('"+u.getMail()+"','"+u.getNom()+"','"+u.getPrenom()+"','"+u.getMotDePasse()+"','"+u.getNumeroTelephone()+"');";
    ///execution de la requête
    if(query.exec(requete)){
        std::cout << "utilisateur bien ajouté" << std::endl;
    }else{ ///l'execution de la requête à échouée
        string s = query.lastError().text().toStdString();
        std::cout << "erreur dans l'ajout de l'utilisateur : " << s << std::endl;
    }
}
/**
* @brief ajoute les coordonnées bancaires rentrées par l'utilisateur u
* @param u l'utilisateur qui rentre ses coordonnées
*/
void BaseDeDonnees::ajouterCoordonneesBancaires(Utilisateur u){
    QSqlQuery query;
    ///la requête sql pour ajouter les coordonnées bancaires de l'utilisateur u
    QString requete="UPDATE Utilisateur SET iban='"+u.getIBAN()+"' WHERE mail LIKE '"+u.getMail()+"';";
    ///execution de la requête
    if(query.exec(requete)){
        std::cout << "coordonnées bancaires bien ajoutées" << std::endl;
    }else{ ///l'execution de la requête à échouée
        string s = query.lastError().text().toStdString();
        std::cout << "erreur dans l'ajout des coordonnées bancaires : " << s << std::endl;
    }
}

/**
 * @brief connexionReussi, test si l'utilisateur correspondant aux données rentrées en paramètre
 * @param mail, le mail rentré par l'utilisateur
 * @param mdp, le mot de passe rentré par l'utilisateur
 * @return true (1) si  l'utilisateur correspondant au mail et au mdp rentrés en paramètre
 *         false (0)  si aucun utilisateur correspond
 */
bool BaseDeDonnees::connexionReussie(QString mail, QString mdp){
    bool resultat_sql=false;
    QSqlQuery query;
    ///la requête sql pour trouver un utilisateur avec les paramètres de la fonction
    QString requete="SELECT * FROM UTILISATEUR WHERE mail LIKE '"+mail+"' AND motDePasse LIKE '"+mdp+"';";
    ///execution de la requête
    if(query.exec(requete)){
        resultat_sql=true;
        std::cout << "la requête de connexion a marché " << std::endl;
    }else{ ///l'execution de la requête à échouée
        string s = query.lastError().text().toStdString();
        std::cout << "la requête de connexion a échoué" << s << std::endl;
    }
    return resultat_sql;
}

/**
 * @brief creerTableCompteCommun, la fonction qui crée la table CompteCommun dans la bdd
 */
void BaseDeDonnees::creerTableCompteCommun(){
    QSqlQuery query;
    ///la requête qui crée la table CompteCommun
    QString requete="CREATE TABLE IF NOT EXISTS CompteCommun(id_Compte NUMBER(50) NOT NULL AUTO_INCREMENT , iban VARCHAR(100) as Iban Createur NOT NULL,  solde NUMBER(50) DEFAULT 0, PRIMARY KEY (id_Compte));";
    ///execution de la requête
    if(query.exec(requete)){
        std::cout << "la requête d'ajout de la table CompteCommun a réussi " << std::endl;
    }else{ ///l'execution de la requête à échouée
        string s = query.lastError().text().toStdString();
        std::cout << "la requête d'ajout de la table CompteCommun a échoué" << s << std::endl;
    }
}

/**
 * @brief ajouterCompteCommun, ajoute un champ et un compte commun à la table Utilisateur, à la ligne de u
 * @param u l'utilistateur auquel on ajoute un compte commun
 */
void BaseDeDonnees::ajouterCompteCommun(Utilisateur u){
    QSqlQuery query;
    ///la requête qui ajoute un nouveau compte commun à l'utilisateur u
    QString requete="INSERT INTO CompteCommun (iban) VALUES (" + u.getIBAN() + ");";
    ///execution de la requête
    if(query.exec(requete)){
        std::cout << "la requête de modification de la table CompteCommun a réussi " << std::endl;
    }else{ ///l'execution de la requête à échouée
        string s = query.lastError().text().toStdString();
        std::cout << "la requête de modification de la table CompteCommun a échoué" << s << std::endl;
    }
}

/**
 * @brief ajouterContributeur, ajoute un champ et un utilisateur (contributeur) à la table CompteCommun, à la ligne de c
 * @param c le compte commun auquel on ajute un contributeur u
 */
void BaseDeDonnees::ajouterContributeur(CompteCommun c, Utilisateur u){}


