#include "fenetrecreationutilisateur.h"
#include "ui_fenetrecreationutilisateur.h"

FenetreCreationUtilisateur::FenetreCreationUtilisateur(BaseDeDonnees bdd,ShareCount sc, QWidget *parent) :
    QDialog(parent),
    basedd(bdd),
    Sharec(sc),
    ui(new Ui::FenetreCreationUtilisateur)
{
    ui->setupUi(this);
    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

FenetreCreationUtilisateur::~FenetreCreationUtilisateur()
{
    delete ui;
}

void FenetreCreationUtilisateur::on_pushButton_clicked()
{
    QString NewMail = ui->lineEdit->text();
    QString NewNom = ui->lineEdit_2->text();
    QString NewPrenom = ui->lineEdit_3->text();
    QString NewMdp = ui->lineEdit_4->text();
    QString NewNumTel = ui->lineEdit_5->text();
    QString NewIBAN = ui->lineEdit_6->text();

    ShareCount sc(basedd);

    Utilisateur u(NewNom,NewPrenom,NewMail,NewNumTel,NewMdp, basedd);
    //Utilisateur u("n","p","m","num","mdp", basedd);
    u.ajouterIBAN(NewIBAN);

    if(sc.ajouterUtilisateur(u)){
        this->close();
        AffBudget *affb = new AffBudget();
        affb->show();
    }
}

