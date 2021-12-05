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
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AffBudget
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AffBudget)
    {
        if (AffBudget->objectName().isEmpty())
            AffBudget->setObjectName(QString::fromUtf8("AffBudget"));
        AffBudget->resize(450, 450);
        progressBar = new QProgressBar(AffBudget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 120, 281, 31));
        progressBar->setValue(24);
        label = new QLabel(AffBudget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 120, 171, 31));
        textBrowser = new QTextBrowser(AffBudget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(80, 30, 256, 51));
        pushButton = new QPushButton(AffBudget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 210, 281, 81));
        pushButton_2 = new QPushButton(AffBudget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 330, 271, 81));

        retranslateUi(AffBudget);

        QMetaObject::connectSlotsByName(AffBudget);
    } // setupUi

    void retranslateUi(QDialog *AffBudget)
    {
        AffBudget->setWindowTitle(QCoreApplication::translate("AffBudget", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AffBudget", "CAGNOTTE", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AffBudget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">PROJET</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("AffBudget", "GESTION MEMBRES", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AffBudget", "GESTION ARGENT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AffBudget: public Ui_AffBudget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFBUDGET_H
