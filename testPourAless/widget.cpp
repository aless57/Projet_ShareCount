#include "widget.h"
#include "ui_widget.h"

#include <QtGui>

Widget::~Widget()
{
    delete ui;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}
