#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->title_label->move(100,30);

    QPixmap vegeta_image(":/images/vgt.jpg");

    ui->image_label->move(0,70);
    ui->image_label->setPixmap(vegeta_image.scaled(325,500));
}

Widget::~Widget()
{
    delete ui;
}

