#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->slider,&QSlider::valueChanged,
            this,&Widget::change_progress_bar);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_progress_bar(int val)
{
    ui->progress_bar->setValue(val);
}

