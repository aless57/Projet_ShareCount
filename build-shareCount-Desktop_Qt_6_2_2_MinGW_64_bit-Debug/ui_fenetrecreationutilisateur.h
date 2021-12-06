/********************************************************************************
** Form generated from reading UI file 'fenetrecreationutilisateur.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETRECREATIONUTILISATEUR_H
#define UI_FENETRECREATIONUTILISATEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FenetreCreationUtilisateur
{
public:
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *imageShareCount;

    void setupUi(QDialog *FenetreCreationUtilisateur)
    {
        if (FenetreCreationUtilisateur->objectName().isEmpty())
            FenetreCreationUtilisateur->setObjectName(QString::fromUtf8("FenetreCreationUtilisateur"));
        FenetreCreationUtilisateur->resize(450, 450);
        lineEdit_5 = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(160, 310, 151, 21));
        lineEdit = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 190, 151, 21));
        lineEdit_4 = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 280, 151, 21));
        pushButton = new QPushButton(FenetreCreationUtilisateur);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 380, 201, 51));
        lineEdit_6 = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(160, 340, 151, 21));
        lineEdit_3 = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 250, 151, 21));
        lineEdit_2 = new QLineEdit(FenetreCreationUtilisateur);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 220, 151, 21));
        imageShareCount = new QLabel(FenetreCreationUtilisateur);
        imageShareCount->setObjectName(QString::fromUtf8("imageShareCount"));
        imageShareCount->setGeometry(QRect(160, 50, 221, 131));

        retranslateUi(FenetreCreationUtilisateur);

        QMetaObject::connectSlotsByName(FenetreCreationUtilisateur);
    } // setupUi

    void retranslateUi(QDialog *FenetreCreationUtilisateur)
    {
        FenetreCreationUtilisateur->setWindowTitle(QCoreApplication::translate("FenetreCreationUtilisateur", "Dialog", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "Numero de T\303\251l\303\251phone", nullptr));
        lineEdit->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "Mail", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "Mot de passe", nullptr));
        pushButton->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "CREATION COMPTE", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "IBAN", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "Prenom", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("FenetreCreationUtilisateur", "Nom", nullptr));
        imageShareCount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FenetreCreationUtilisateur: public Ui_FenetreCreationUtilisateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRECREATIONUTILISATEUR_H
