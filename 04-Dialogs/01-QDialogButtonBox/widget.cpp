#include "widget.h"
#include "./ui_widget.h"
#include "characterdialog.h"

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


void Widget::on_pushButton_clicked()
{
    CharacterDialog* dialog=new CharacterDialog(this);
    dialog->exec();
}

