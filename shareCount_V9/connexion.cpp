#include "connexion.h"
#include "ui_connexion.h"

Connexion::Connexion(BaseDeDonnees bdd, ShareCount s, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion),
    shareC(s),
    basedd(bdd)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButton_clicked()
{
    QString mail = ui->lineEdit->text();
    QString mdp = ui->lineEdit_2->text();
    if(shareC.verifierFormatMail(mail)) {
        if(basedd.connexionReussie(mail,mdp)){
            std::cout<<"hooolaaaaa"<<std::endl;
            this->close();
            AffBudget *affb = new AffBudget();
            affb->show();
        }
    }

}

