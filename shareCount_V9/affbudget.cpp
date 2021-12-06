#include "affbudget.h"
#include "ui_affbudget.h"

AffBudget::AffBudget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AffBudget)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

AffBudget::~AffBudget()
{
    delete ui;
}
