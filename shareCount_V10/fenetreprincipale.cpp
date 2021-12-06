#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

/**
 * @brief FenetrePrincipale::FenetrePrincipale le constructeur
 * @param bdd la base de données où les utilisateurs se trouvent
 * @param sc shareCount
 * @param parent
 */
FenetrePrincipale::FenetrePrincipale(BaseDeDonnees bdd,ShareCount sc,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetrePrincipale),
    basedd(bdd),
    Sharec(sc)
{
    ui->setupUi(this);
    QPixmap pix(":/image/logoShareCount.png");///cherche l'image
    int w = ui->imageShareCount->width();///récupère la largeur de l'image
    int h = ui->imageShareCount->height();///récupère la hauteur de l'image
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));///met l'image
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}
/**
 * @brief on_pushButton_2_clicked la fonction qui gère le clique du bouton création de compte
 */
void FenetrePrincipale::on_pushButton_2_clicked()
{
    this->close(); ///fermeture de la fenêtre d'accueil
    FenetreCreationUtilisateur *fcu = new FenetreCreationUtilisateur(basedd,Sharec);///cration d'une fenêtre de création de compte
    fcu->show();///affichage de la fenêtre
}

/**
 * @brief on_pushButton_clicked la fonction qui gère le clique du bouton connexion
 */
void FenetrePrincipale::on_pushButton_clicked()
{
    this->close();///fermeture de la fenêtre principale
    Connexion *cx = new Connexion(basedd, Sharec);///création d'une nouvelle fenêtre de connexion
    cx->show();///affichage de la fenêtre
}

