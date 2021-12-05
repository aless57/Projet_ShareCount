/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_createUser
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit;
    QLabel *imageShareCount;

    void setupUi(QDialog *createUser)
    {
        if (createUser->objectName().isEmpty())
            createUser->setObjectName(QString::fromUtf8("createUser"));
        createUser->resize(450, 450);
        buttonBox = new QDialogButtonBox(createUser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 450, 450, 450));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_3 = new QLineEdit(createUser);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 240, 151, 21));
        lineEdit_4 = new QLineEdit(createUser);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 270, 151, 21));
        pushButton = new QPushButton(createUser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 370, 201, 51));
        lineEdit_2 = new QLineEdit(createUser);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 210, 151, 21));
        lineEdit_5 = new QLineEdit(createUser);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(160, 300, 151, 21));
        lineEdit_6 = new QLineEdit(createUser);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(160, 330, 151, 21));
        lineEdit = new QLineEdit(createUser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 180, 151, 21));
        imageShareCount = new QLabel(createUser);
        imageShareCount->setObjectName(QString::fromUtf8("imageShareCount"));
        imageShareCount->setGeometry(QRect(160, 40, 221, 131));

        retranslateUi(createUser);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, createUser, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, createUser, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(createUser);
    } // setupUi

    void retranslateUi(QDialog *createUser)
    {
        createUser->setWindowTitle(QCoreApplication::translate("createUser", "Dialog", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("createUser", "Prenom", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("createUser", "Mot de passe", nullptr));
        pushButton->setText(QCoreApplication::translate("createUser", "CREATION COMPTE", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("createUser", "Nom", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("createUser", "Numero de T\303\251l\303\251phone", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("createUser", "IBAN", nullptr));
        lineEdit->setText(QCoreApplication::translate("createUser", "Mail", nullptr));
        imageShareCount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class createUser: public Ui_createUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
