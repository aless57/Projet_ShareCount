/********************************************************************************
** Form generated from reading UI file 'fenetreprincipale.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALE_H
#define UI_FENETREPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FenetrePrincipale
{
public:
    QPushButton *pushButton;
    QLabel *imageShareCount;
    QPushButton *pushButton_2;

    void setupUi(QDialog *FenetrePrincipale)
    {
        if (FenetrePrincipale->objectName().isEmpty())
            FenetrePrincipale->setObjectName(QString::fromUtf8("FenetrePrincipale"));
        FenetrePrincipale->resize(450, 450);
        pushButton = new QPushButton(FenetrePrincipale);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 320, 171, 91));
        imageShareCount = new QLabel(FenetrePrincipale);
        imageShareCount->setObjectName(QString::fromUtf8("imageShareCount"));
        imageShareCount->setGeometry(QRect(100, 30, 301, 231));
        pushButton_2 = new QPushButton(FenetrePrincipale);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 320, 171, 91));

        retranslateUi(FenetrePrincipale);

        QMetaObject::connectSlotsByName(FenetrePrincipale);
    } // setupUi

    void retranslateUi(QDialog *FenetrePrincipale)
    {
        FenetrePrincipale->setWindowTitle(QCoreApplication::translate("FenetrePrincipale", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FenetrePrincipale", "CONNEXION", nullptr));
        imageShareCount->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("FenetrePrincipale", "CREATION COMPTE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetrePrincipale: public Ui_FenetrePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALE_H
