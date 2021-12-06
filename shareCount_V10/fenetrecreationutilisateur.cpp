#include "fenetrecreationutilisateur.h"
#include "ui_fenetrecreationutilisateur.h"

/**
 * @brief FenetreCreationUtilisateur::FenetreCreationUtilisateur le constructeur de la classe
 * @param bdd, la base de données où on ajoute les données du nouvel utilisateur
 * @param s, classe ShareCount qui va effectuer des actions sur l'utilisateur
 * @param parent
 */
FenetreCreationUtilisateur::FenetreCreationUtilisateur(BaseDeDonnees bdd,ShareCount sc, QWidget *parent) :
    QDialog(parent),
    basedd(bdd),
    Sharec(sc),
    ui(new Ui::FenetreCreationUtilisateur)
{
    ui->setupUi(this);
    QPixmap pix(":/image/logoShareCount.png");///récupération de l'image dans les ressources
    int w = ui->imageShareCount->width();///récupération de la largeur de l'image
    int h = ui->imageShareCount->height();///récupération de la hauteur de l'image
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); ///mise en place de l'image
}

FenetreCreationUtilisateur::~FenetreCreationUtilisateur()
{
    delete ui;
}

/**
 * @brief on_pushButton_clicked, la fonction qui gère l'évenement lorsque l'on clique sur le bouton Création Compte
 */
void FenetreCreationUtilisateur::on_pushButton_clicked()
{
    ///Récupération les données rentrées par l'utilisateur lors de la création du compte
    QString NewMail = ui->lineEdit->text(); ///initialisation du mail
    QString NewNom = ui->lineEdit_2->text();///initialisation du nom
    QString NewPrenom = ui->lineEdit_3->text();///initialisation du prénom
    QString NewMdp = ui->lineEdit_4->text();///initialisation du mot de passe
    QString NewNumTel = ui->lineEdit_5->text();///initialisation du numéro de téléphone
    QString NewIBAN = ui->lineEdit_6->text();///initialisation de l'iban

    ShareCount sc(basedd); ///liaison de la base de données à shareCount

    Utilisateur u(NewNom,NewPrenom,NewMail,NewNumTel,NewMdp, basedd); ///création du nouvel utilisateur
    /// ajout de l'IBAN après l'avoir vérifié
    u.ajouterIBAN(NewIBAN);

    if(sc.ajouterUtilisateur(u)){///ajoute l'utilisateur à la base de données
        this->close();///ferme la fenêtre principale
        AffBudget *affb = new AffBudget(u, basedd, Sharec);///crée une nouvelle fenêtre de la création
        affb->show();///affiche la nouvelle fenêtre
    }
}

