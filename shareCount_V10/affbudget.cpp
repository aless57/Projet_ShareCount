#include "affbudget.h"
#include "ui_affbudget.h"

AffBudget::AffBudget(Utilisateur user, BaseDeDonnees bdd, ShareCount sc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AffBudget),
    u(user),
    basedd(bdd),
    shareC(sc)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->nom->setText(u.getNom());
    ui->prenom->setText(u.getPrenom());
}

AffBudget::~AffBudget()
{
    delete ui;
}

void AffBudget::on_pushButton_3_clicked()
{
    this->close();
    FenetrePrincipale *fe = new FenetrePrincipale(basedd, shareC);
    fe->show();
}



