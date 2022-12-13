#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *box_layout= new QHBoxLayout();

    box_layout->addWidget(ui->first_button);
    box_layout->addWidget(ui->second_button);
    box_layout->addWidget(ui->third_button);
    box_layout->addWidget(ui->forth_button);
    box_layout->addWidget(ui->fifth_button);

    setLayout(box_layout);


}

Widget::~Widget()
{
    delete ui;
}

