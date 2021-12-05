#include "connexion.h"
#include "ui_connexion.h"

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
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
    this->close();
    AffBudget *affb = new AffBudget();
    affb->show();
}

