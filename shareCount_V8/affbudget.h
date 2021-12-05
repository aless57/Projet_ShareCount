#ifndef AFFBUDGET_H
#define AFFBUDGET_H

#include <QDialog>

namespace Ui {
class AffBudget;
}

class AffBudget : public QDialog
{
    Q_OBJECT

public:
    explicit AffBudget(QWidget *parent = nullptr);
    ~AffBudget();

private:
    Ui::AffBudget *ui;
};

#endif // AFFBUDGET_H
