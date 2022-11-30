#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_submit_button_clicked()
{
    qInfo()<<"First Name: " << ui->first_name_le->text();
    qInfo()<<"Laat Name: " << ui->last_name_le->text();
    qInfo()<<"Message: " << ui->message_te->toPlainText();
}

