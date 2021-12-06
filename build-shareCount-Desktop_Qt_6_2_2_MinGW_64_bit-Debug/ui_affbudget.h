/********************************************************************************
** Form generated from reading UI file 'affbudget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFBUDGET_H
#define UI_AFFBUDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AffBudget
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *nom;
    QLabel *prenom;
    QLabel *imageShareCount;
    QLabel *label_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *AffBudget)
    {
        if (AffBudget->objectName().isEmpty())
            AffBudget->setObjectName(QString::fromUtf8("AffBudget"));
        AffBudget->resize(450, 450);
        progressBar = new QProgressBar(AffBudget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(150, 180, 281, 31));
        progressBar->setValue(2);
        label = new QLabel(AffBudget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 180, 171, 31));
        pushButton = new QPushButton(AffBudget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 230, 271, 81));
        pushButton_2 = new QPushButton(AffBudget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 330, 271, 81));
        nom = new QLabel(AffBudget);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(30, 100, 91, 31));
        nom->setAlignment(Qt::AlignCenter);
        prenom = new QLabel(AffBudget);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(30, 140, 91, 31));
        prenom->setAlignment(Qt::AlignCenter);
        imageShareCount = new QLabel(AffBudget);
        imageShareCount->setObjectName(QString::fromUtf8("imageShareCount"));
        imageShareCount->setGeometry(QRect(-10, 220, 171, 211));
        label_2 = new QLabel(AffBudget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 101, 31));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(AffBudget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 50, 141, 71));

        retranslateUi(AffBudget);

        QMetaObject::connectSlotsByName(AffBudget);
    } // setupUi

    void retranslateUi(QDialog *AffBudget)
    {
        AffBudget->setWindowTitle(QCoreApplication::translate("AffBudget", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AffBudget", "CAGNOTTE", nullptr));
        pushButton->setText(QCoreApplication::translate("AffBudget", "GESTION MEMBRES", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AffBudget", "GESTION ARGENT", nullptr));
        nom->setText(QString());
        prenom->setText(QString());
        imageShareCount->setText(QString());
        label_2->setText(QCoreApplication::translate("AffBudget", "Bonjour", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AffBudget", "Deconnection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AffBudget: public Ui_AffBudget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFBUDGET_H
