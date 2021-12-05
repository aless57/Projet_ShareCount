#include "affbudget.h"
#include "ui_affbudget.h"

AffBudget::AffBudget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AffBudget)
{
    ui->setupUi(this);


}

AffBudget::~AffBudget()
{
    delete ui;
}
