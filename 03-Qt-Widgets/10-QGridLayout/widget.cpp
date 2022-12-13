#include "widget.h"
#include "./ui_widget.h"
#include <QGridLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout *grid_layout= new QGridLayout(this);

    //first row
    grid_layout->addWidget(ui->button_one,0,0);
    grid_layout->addWidget(ui->button_two,0,1);
    grid_layout->addWidget(ui->button_three,0,2,2,1); //row:0 column:2 rowspan:2,columnspan:1

    //second row
    grid_layout->addWidget(ui->button_four,1,0);
    grid_layout->addWidget(ui->button_five,1,1);

    //third row
    grid_layout->addWidget(ui->button_six,2,0,1,2); //row:0 column:2 rowspan:2,columnspan:1
    grid_layout->addWidget(ui->button_seven,2,2);

}

Widget::~Widget()
{
    delete ui;
}

