#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetrePrincipale)
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
    createUser *cu = new createUser();
    cu->setFixedSize(450,450);
    cu->show();
}


void FenetrePrincipale::on_pushButton_clicked()
{
    this->close();
    Connexion *cx = new Connexion();
    cx->show();
}

