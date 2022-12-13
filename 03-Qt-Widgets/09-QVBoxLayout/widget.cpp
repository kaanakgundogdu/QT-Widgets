#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *vbox_layout= new QVBoxLayout();

    vbox_layout->addWidget(ui->first_button);
    vbox_layout->addWidget(ui->second_button);
    vbox_layout->addWidget(ui->third_button);
    vbox_layout->addWidget(ui->forth_button);
    vbox_layout->addWidget(ui->fifth_button);
    vbox_layout->addWidget(ui->sixth_button);
    vbox_layout->addWidget(ui->seventh_button);
    setLayout(vbox_layout);

}

Widget::~Widget()
{
    delete ui;
}

