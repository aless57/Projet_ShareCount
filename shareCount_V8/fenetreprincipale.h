#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include "createuser.h"
#include "connexion.h"
#include <QDialog>

namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QDialog
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FenetrePrincipale *ui;
};

#endif // FENETREPRINCIPALE_H
