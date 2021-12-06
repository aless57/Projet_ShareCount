#include "Basededonnees.h"
#include "QSqlError"
/**
 * @brief Constructeur de la classe BaseDeDonnees
*/
BaseDeDonnees::BaseDeDonnees()
{}

/**
 * @brief BaseDeDonnees::creerBDD la fonction qui créée la base de données associée à l'application si elle n'existe pas déjà et la table Utilisateur
 * @return le code d'erreur
 * 0 si l'opération s'est bien déroulée
 * 1 si la table n'a pas pu être créée
 * 2 si la bdd a rencontrée un problême lors de l'ouverture
 */
int BaseDeDonnees::creerBDD(){
    /// initialisation de la variable de retour
    int r=0;
    ///création de la base de données
    QSqlDatabase bdd=QSqlDatabase::addDatabase("QSQLITE");
    /// mise en place de la base de données à partir du fichier d'installation
    bdd.setDatabaseName("../bdd.db");
    if(bdd.open()){ ///ouverture de la base de données
        std::cout <<"Le fichier de la bdd est ouvert" << std::endl;
        QSqlQuery query(bdd);
        ///création de la table utilisateur si cette dernière n'est pas déjà créée
        if(query.exec("CREATE TABLE IF NOT EXISTS Utilisateur(mail VARCHAR(50) NOT NULL,nom VARCHAR(50) NOT NULL,prenom VARCHAR(50) NOT NULL,motDePasse VARCHAR(50) NOT NULL,numeroTelephone VARCHAR(50) NOT NULL,iban VARCHAR(100),PRIMARY KEY(mail));"
                      )){
            std::cout << "Table Utilisateur créée " << std::endl;
        }else{
            ///la création de table a échouée
            r=1;
        }
    }else{
        ///l'ouverture de la base de données a échouée
        r=2;
    }
    /// retour du code d'erreur
    return r;
}

/**
 * @brief ajouterDonnees la fonction qui ajoute les données rentrées par l'utilisateur dans la base de données
 * @param u l'utilisateur
 * @return true (1) si la requête a été effectuée
 *         false (0) sinon
 */
bool BaseDeDonnees::ajouterDonnees(Utilisateur u){
    /// initialisation  de la variable de retour
    bool resultat_sql=false;
    QSqlQuery query;
    ///la requete sql pour ajouter un utilisateur dans la table Utilisateur
    QString requete="INSERT INTO UTILISATEUR (mail,nom,prenom,motDePasse,numeroTelephone) VALUES ('"+u.getMail()+"','"+u.getNom()+"','"+u.getPrenom()+"','"+u.getMotDePasse()+"','"+u.getNumeroTelephone()+"');";
    ///exécution de la requête
    if(query.exec(requete)){
        resultat_sql=true;
        std::cout << "utilisateur bien ajouté" << std::endl;
    }else{ ///l'éxécution de la requête a échouée
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "erreur dans l'ajout de l'utilisateur : " << s << std::endl;
    }
    /// retour du code d'erreur
    return resultat_sql;
}
/**
* @brief ajoute les coordonnées bancaires rentrées par l'utilisateur u
* @param u l'utilisateur qui rentre ses coordonnées
*/
void BaseDeDonnees::ajouterCoordonneesBancaires(Utilisateur u){
    QSqlQuery query;
    ///la requête sql pour ajouter les coordonnées bancaires de l'utilisateur u
    QString requete="UPDATE Utilisateur SET iban='"+u.getIBAN()+"' WHERE mail LIKE '"+u.getMail()+"';";
    ///exécution de la requête
    if(query.exec(requete)){
        std::cout << "coordonnées bancaires bien ajoutées" << std::endl;
    }else{ ///l'execution de la requête a échouée
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "erreur dans l'ajout des coordonnées bancaires : " << s << std::endl;
    }
}

/**
 * @brief connexionReussie, vérifie si l'utilisateur correspond aux données rentrées en paramètre
 * @param mail, le mail rentré par l'utilisateur
 * @param mdp, le mot de passe rentré par l'utilisateur
 * @return true (1) si  l'utilisateur a bien été trouvé grâce au mail et au mdp rentrés en paramètre
 *         false (0) sinon
 */
bool BaseDeDonnees::connexionReussie(QString mail, QString mdp){
    /// initialisation de la variable de retour
    bool resultat_sql=false;
    QSqlQuery query;
    ///la requête sql pour trouver un utilisateur avec les paramètres de la fonction
    QString requete="SELECT COUNT(*) FROM UTILISATEUR WHERE mail LIKE '" + mail + "' AND motDePasse LIKE '" + mdp + "';";
    /// exécution de la requête
    query.exec(requete);
    /// mise en place du premier résultat de la requête
    query.first();
    /// récupération du Count(*) soit le résultat de la requête
    int r = query.value(0).toInt();
    /// l'utilisateur a été trouvé
    if(r != 0){
        resultat_sql=true;
        std::cout << "la requête de connexion a marché : " << r << std::endl;
    }else{ /// l'utilisateur n'a pas été trouvé
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "la requête de connexion a échoué : " << s << std::endl;
    }
    /// retour du code d'erreur
    return resultat_sql;
}

/**
 * @brief creerTableCompteCommun, la fonction qui crée la table CompteCommun dans la bdd
 */
void BaseDeDonnees::creerTableCompteCommun(){
    QSqlQuery query;
    ///la requête qui créée la table CompteCommun
    QString requete="CREATE TABLE IF NOT EXISTS CompteCommun(id_Compte NUMBER(50) NOT NULL AUTO_INCREMENT , iban VARCHAR(100) as Iban Createur NOT NULL,  solde NUMBER(50) DEFAULT 0, PRIMARY KEY (id_Compte));";
    ///exécution de la requête
    if(query.exec(requete)){
        std::cout << "la requête d'ajout de la table CompteCommun a réussi " << std::endl;
    }else{ ///l'exécution de la requête a échouée
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "la requête d'ajout de la table CompteCommun a échoué" << s << std::endl;
    }
}

/**
 * @brief trouverUtilisateur, permet de récupérer et créer un utilisateur grâce à son mail et son mdp passés en paramètre
 * @param mail, le mail rentré par l'utilisateur
 * @param mdp, le mot de passe rentré par l'utilisateur
 * @return Utilisateur* u
 */
Utilisateur BaseDeDonnees::trouverUtilisateur(QString mail, QString mdp){
    /// initialisation des différentes variables nécessaires à la création d'un Utilisateur
    QSqlQuery query;
    Utilisateur *u;
    QString Nmail;
    QString nom;
    QString prenom;
    QString Nmdp;
    QString num;
    /// création de la requête
    QString requete="SELECT * FROM UTILISATEUR WHERE mail LIKE '" + mail + "' AND motDePasse LIKE '" + mdp + "';";
    /// exécution de la requête
    if(query.exec(requete)){
        /// récupération des données
        while (query.next()) {
                Nmail = query.value(0).toString();
                nom = query.value(1).toString();
                prenom = query.value(2).toString();
                Nmdp = query.value(3).toString();
                num = query.value(4).toString();
            }
        /// création de l'Utilisateur
          u = new Utilisateur(nom, prenom, Nmail, num, Nmdp,*this);
        std::cout << "le User est trouve " << std::endl;
    }else{
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "le User n'est pas trouve :" <<  s << std::endl;
    }
    /// retour de l'utilisateur crée
    return *u;
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
        /// récupération du message d'erreur
        string s = query.lastError().text().toStdString();
        std::cout << "la requête de modification de la table CompteCommun a échoué" << s << std::endl;
    }
}

/**
 * @brief ajouterContributeur, ajoute un champ et un utilisateur (contributeur) à la table CompteCommun, à la ligne de c
 * @param c le compte commun auquel on ajute un contributeur u
 */
void BaseDeDonnees::ajouterContributeur(CompteCommun c, Utilisateur u){}


