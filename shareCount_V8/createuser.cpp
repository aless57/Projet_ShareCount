#include "createuser.h"
#include "ui_createuser.h"

createUser::createUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUser)
{
    ui->setupUi(this);

    QPixmap pix(":/image/logoShareCount.png");
    int w = ui->imageShareCount->width();
    int h = ui->imageShareCount->height();
    ui->imageShareCount->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

createUser::~createUser()
{
    delete ui;
}

void createUser::on_pushButton_clicked()
{
  this->close();
  AffBudget *affb = new AffBudget();
  affb->setFixedSize(450,450);
  affb->show();
}
