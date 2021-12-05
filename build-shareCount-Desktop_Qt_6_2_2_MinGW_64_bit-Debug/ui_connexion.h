/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Connexion
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *imageShareCount;

    void setupUi(QDialog *Connexion)
    {
        if (Connexion->objectName().isEmpty())
            Connexion->setObjectName(QString::fromUtf8("Connexion"));
        Connexion->resize(450, 450);
        pushButton = new QPushButton(Connexion);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 340, 191, 91));
        lineEdit = new QLineEdit(Connexion);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 180, 161, 41));
        lineEdit_2 = new QLineEdit(Connexion);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 250, 161, 41));
        label = new QLabel(Connexion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 200, 47, 13));
        label_2 = new QLabel(Connexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(66, 260, 81, 20));
        imageShareCount = new QLabel(Connexion);
        imageShareCount->setObjectName(QString::fromUtf8("imageShareCount"));
        imageShareCount->setGeometry(QRect(120, 10, 341, 171));

        retranslateUi(Connexion);

        QMetaObject::connectSlotsByName(Connexion);
    } // setupUi

    void retranslateUi(QDialog *Connexion)
    {
        Connexion->setWindowTitle(QCoreApplication::translate("Connexion", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Connexion", "Connect", nullptr));
        label->setText(QCoreApplication::translate("Connexion", "EMail : ", nullptr));
        label_2->setText(QCoreApplication::translate("Connexion", "Mot de passe :", nullptr));
        imageShareCount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connexion: public Ui_Connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
