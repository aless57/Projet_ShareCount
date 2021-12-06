#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(BaseDeDonnees bdd,ShareCount sc,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetrePrincipale),
    basedd(bdd),
    Sharec(sc)
{
    ui->setupUi(this);
    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

void FenetrePrincipale::on_pushButton_2_clicked()
{
    this->close();
    FenetreCreationUtilisateur *fcu = new FenetreCreationUtilisateur(basedd,Sharec);
    fcu->show();
}


void FenetrePrincipale::on_pushButton_clicked()
{
    this->close();
    Connexion *cx = new Connexion(basedd, Sharec);
    cx->show();
}

