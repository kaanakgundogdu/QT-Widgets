#include "widget.h"
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont button_font("Times",16,QFont::Bold);
    QPushButton *button_1= new QPushButton("Button_1",this);
    button_1->setMinimumSize(140,140);
    //button_1->setText();
    button_1->setFont(button_font);
    connect(button_1,&QPushButton::clicked,[](){
       qDebug()<<"Button Clicked.";
    });


    QPushButton *button_2= new QPushButton("Button_2",this);
    button_2->setMinimumSize(140,140);
    button_2->setFont(button_font);
    button_2->move(150,0);
    connect(button_2,&QPushButton::pressed,[](){
       qDebug()<<"Button Pressed.";
    });
    connect(button_2,&QPushButton::released,[](){
       qDebug()<<"Button Released.";
    });
}

Widget::~Widget()
{
}

