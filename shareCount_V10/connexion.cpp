#include "connexion.h"
#include "ui_connexion.h"
/**
 * @brief Connexion::Connexion le constructeur de la classe
 * @param bdd, la base de données sur laquelle l'utilisateur se connecte
 * @param s, classe ShareCount qui va effectuer des actions sur l'utilisateur
 * @param parent
 */
Connexion::Connexion(BaseDeDonnees bdd, ShareCount s, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion),
    shareC(s),
    basedd(bdd)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logoShareCount.png");///va chercher dans ressources l'image
    int w = ui->imageShareCount->width();///récupère la largeur de l'image
    int h = ui->imageShareCount->height();///récupère la hauteur de l'image
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));///met l'image
}

Connexion::~Connexion()
{
    delete ui;
}
/**
 * @brief on_pushButton_clicked, la fonction qui gère l'évenement lorsque l'on clique sur le bouton Connect
 */
void Connexion::on_pushButton_clicked()
{
    QString mail = ui->lineEdit->text();///récupère le mail rentré par l'utilisateur
    QString mdp = ui->lineEdit_2->text();///récupère le mot de passe rentré par l'utilisateur
        if(basedd.connexionReussie(mail,mdp)){///les informations rentrées par l'utilisateur correspond à un compte de la bdd
            this->close();///ferme la fenêtre de base
            AffBudget *affb = new AffBudget(basedd.trouverUtilisateur(mail,mdp), basedd, shareC);///crée une nouvelle fenêtre avec les informations de l'utilisateur
            affb->show();///affiche la nouvelle fenêtre avec les informations de l'utilisateur
        }

}

