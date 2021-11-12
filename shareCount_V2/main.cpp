#include "mainwindow.h"
#include "Utilisateur.h"
#include <QApplication>
#include <stdio.h>
#include <QtDebug>

int main(int argc, char *argv[])
{
    Utilisateur u("DEMANGE","Alessi","demangealessi@gmail.com","0666442119","alessi");
    printf("%s\n",u.getNom().toStdString().c_str());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
