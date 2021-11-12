#include "mainwindow.h"
#include "Utilisateur.h"
#include <QApplication>
#include <stdio.h>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
   // Utilisateur u("nom","prenom","mail","num","mdp");
    //printf("%s\n",u.getNom().toStdString().c_str());
}
