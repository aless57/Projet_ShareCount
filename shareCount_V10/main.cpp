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
#include <QString>
#include "Basededonnees.h"
#include "fenetreprincipale.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //création de la base de données
    BaseDeDonnees bdd;
    ShareCount sc(bdd);
    int r=bdd.creerBDD();
    if(r==1){
        std::cout << "Erreur lors de la création de la table Utilisateur" << std::endl;
        return 1;
    }else if (r==2) {
        std::cout << "Erreur lors de l'ouverture de la base de données" << std::endl;
        return 1;
    }



    FenetrePrincipale *mainW = new FenetrePrincipale(bdd,sc);
    mainW->show();
    return app.exec();

}

