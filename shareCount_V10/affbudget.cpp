#include "affbudget.h"
#include "ui_affbudget.h"

/**
 * @brief AffBudget::AffBudget le constructeur de la classe
 * @param user l'utilisateur duquel les informations affichées sont issues
 * @param bdd la base de données où se trouvent les informations de l'utilisateur
 * @param sc classe ShareCount qui va effectuer des actions sur l'utilisateur
 * @param parent
 */
AffBudget::AffBudget(Utilisateur user, BaseDeDonnees bdd, ShareCount sc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AffBudget),
    u(user),
    basedd(bdd),
    shareC(sc)
{
    ui->setupUi(this); /// mise en place de l'ui

    QPixmap pix(":/image/logoShareCount.png"); ///va chercher l'image dans les ressources
    int w = ui->imageShareCount->width();  ///récupère la largeur de l'image
    int h = ui->imageShareCount->height(); /// récupère la hauteur de l'image
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); /// met en place l'image
    ui->nom->setText(u.getNom()); ///récupère le nom de l'utilisateur
    ui->prenom->setText(u.getPrenom()); ///récupère le prénom de l'utilisateur
}

AffBudget::~AffBudget()
{
    delete ui;
}

/**
 * @brief on_pushButton_3_clicked, la fonction qui gère l'évenement lorsque l'on clique sur le bouton Déconnection
 */
void AffBudget::on_pushButton_3_clicked()
{
    this->close(); /// ferme la fenêtre de l'interface utilisateur
    FenetrePrincipale *fe = new FenetrePrincipale(basedd, shareC); /// création d'une nouvelle fenêtre representant la fenêtre d'accueil
    fe->show(); /// affiche la fenêtre d'accueil
}



