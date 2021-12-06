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

/*
    ShareCount sc(bdd);
    Utilisateur u("n","p","m","num","mdp", bdd);
    Utilisateur u1("n1","p1","m1","num1","mdp1", bdd);
    u.ajouterIBAN("123");
    sc.ajouterUtilisateur(u);
    sc.ajouterUtilisateur(u1);
    bdd.ajouterCoordonneesBancaires(u);

    sc.ajouterUtilisateur(u1);
    int n;
    n=sc.getListeUtilisateur().size();
    cout << n << endl;
    sc.verifierFormatMail(QString("r"));
    sc.verifierFormatTelephone(QString("0777777777"));
    sc.mailEstLibre(QString("m"));

    u.creerCompteCommun();*/




}

