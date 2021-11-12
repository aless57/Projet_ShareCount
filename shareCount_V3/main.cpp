#include "mainwindow.h"
#include "Utilisateur.h"
#include <stdio.h>
#include <QtDebug>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QLabel>

int main(int argc, char *argv[])
{
//    Utilisateur u("DEMANGE","Alessi","demangealessi@gmail.com","0666666666","alessi");
//    printf("%s\n",u.getNom().toStdString().c_str());

    QApplication app(argc, argv);

    //Creation d'un widget qui sert de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(450,450);

    //Creation d'un bouton qui servira de connexion à l'application
    QPushButton buttonConnexion ("Connexion",&fenetre);
    buttonConnexion.setFont(QFont("Lato",14));
    buttonConnexion.setGeometry(165,250,120,50);

    //Essaie de mettre une icone (ça ne fonctionne pas encore)
    buttonConnexion.setIcon(QIcon("./connexion.png"));

    //Creation d'un bouton qui servira de création de compte dans l'application
    QPushButton buttonCreationCompte("Créer un compte", &fenetre);
    buttonCreationCompte.setFont(QFont("Lato",14));
    buttonCreationCompte.setGeometry(135,320,180,50);

    //Creation de l'image pour le logo ShareCount
    //faire le chemin relatif au niveau du dossier a destination svp je n'y arrive pas
    QImage image("c:\\logoShareCount.png");
    QImage newImage = image.scaled(256, 256, Qt::KeepAspectRatio);
    QLabel label("test", &fenetre);
    label.setGeometry(97, 0, 256, 256);
    label.setPixmap(QPixmap::fromImage(newImage));

    //Affichage de la fenetre
    fenetre.show();

    return app.exec();


//    MainWindow w;
//    w.show();
}
