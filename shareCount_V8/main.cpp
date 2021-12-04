#include "mainwindow.h"
#include "Utilisateur.h"
#include "Sharecount.h"
#include <stdio.h>
#include <QtDebug>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QLabel>
#include "Basededonnees.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //création de la base de données
    BaseDeDonnees bdd;
    int r=bdd.creerBDD();
    if(r==1){
        std::cout << "Erreur lors de la création de la table Utilisateur" << std::endl;
        return 1;
    }else if (r==2) {
        std::cout << "Erreur lors de l'ouverture de la base de données" << std::endl;
        return 1;
    }


    ShareCount sc(bdd);
    Utilisateur u("n","p","m","num","mdp");
    Utilisateur u1("n1","p1","m1","num1","mdp1");
   // u.ajouterIBAN("123");
    //sc.ajouterUtilisateur(u);
    //sc.ajouterUtilisateur(u1);
    //bdd.ajouterCoordonneesBancaires(u);

    //sc.ajouterUtilisateur(u1);
   /* int n;
    n=sc.getListeUtilisateur().size();
    cout << n << endl;
    sc.verifierFormatMail(QString("r"));
    sc.verifierFormatTelephone(QString("0777777777"));
    sc.mailEstLibre(QString("m"));



    //Creation d'un widget qui sert de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(450,450);

    //Creation d'un bouton qui servira de connexion à l'application
    QPushButton buttonConnexion ("Connexion",&fenetre);
    buttonConnexion.setFont(QFont("Lato",14));
    buttonConnexion.setGeometry(165,250,120,50);

    //met une icone sur le bouton
    buttonConnexion.setIcon(QIcon(":/image/connexion.png"));

    //Creation d'un bouton qui servira de création de compte dans l'application
    QPushButton buttonCreationCompte("Créer un compte", &fenetre);
    buttonCreationCompte.setFont(QFont("Lato",14));
    buttonCreationCompte.setGeometry(135,320,180,50);

    //Creation de l'image pour le logo ShareCount
    QImage image(":/image/logoShareCount.png");
    QImage newImage = image.scaled(256, 256, Qt::KeepAspectRatio);
    QLabel label("test", &fenetre);
    label.setGeometry(97, 0, 256, 256);
    label.setPixmap(QPixmap::fromImage(newImage));

    //Affichage de la fenetre
    fenetre.show();

    return app.exec();


    MainWindow w;
    w.show();
    */
}

