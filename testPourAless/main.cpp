#include "mainwindow.h"
#include "Utilisateur.h"
#include "Sharecount.h"
#include "widget.h"
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
    Utilisateur u("demangealessi@gmail.com","Demange","Alessi","YO57","066644442187");
    Utilisateur u2("bernardroxane","Bernard","Roxane","YO54","077777422187");
    Utilisateur u3("noelvictor@gmail.com","Noel","Victor","YO88","088888422187");
    u.ajouterIBAN("123");
    u2.ajouterIBAN("456");
    u3.ajouterIBAN("789");
    sc.ajouterUtilisateur(u);
    sc.ajouterUtilisateur(u2);
    sc.ajouterUtilisateur(u3);
    QString n=u.getIBAN();
    std::cout << n.toStdString() << std::endl;
    bdd.ajouterCoordonneesBancaires(u);
    bdd.ajouterCoordonneesBancaires(u2);
    bdd.ajouterCoordonneesBancaires(u3);

    int n2 = sc.getListeUtilisateur().size();
    cout << n2 << endl;
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

    Widget w;
    w.show();
    //QObject:connect(buttonCreationCompte, SIGNAL(clicked()),fenetre, SLOT(cout << "YIIII" << endl));

    //Creation de l'image pour le logo ShareCount
    QImage image(":/image/logoShareCount.png");
    QImage newImage = image.scaled(256, 256, Qt::KeepAspectRatio);
    QLabel label("test", &fenetre);
    label.setGeometry(97, 0, 256, 256);
    label.setPixmap(QPixmap::fromImage(newImage));

    //Affichage de la fenetre
    fenetre.show();

    return app.exec();


    MainWindow w2;
    w2.show();

}

