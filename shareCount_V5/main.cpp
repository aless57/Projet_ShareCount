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

using namespace std;

int main(int argc, char *argv[])
{

    ShareCount sc;
    Utilisateur u("n","p","m","num","mdp");
    Utilisateur u1("n","p","m","num","mdp");
    sc.ajouterUtilisateur(u);
    sc.ajouterUtilisateur(u1);
    int n;
    n=sc.getListeUtilisateur().size();
    cout << n << endl;
    sc.verifierFormatMail(QString("r"));
    sc.verifierFormatTelephone(QString("0777777777"));
    sc.mailEstLibre(QString("m"));
/*
    QApplication app(argc, argv);

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

*/
   /* MainWindow w;
    w.show();*/

}
