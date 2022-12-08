#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button= new QPushButton("Click Me For Message Box!",this);
    button->move(250,250);

    connect(button,&QPushButton::clicked, [=](){
        int ret = QMessageBox::warning(this, "Kaan Akgundogdu",
                                       "You clicked button.\nDo you want to close this window?",
                                       QMessageBox::Ok | QMessageBox::Cancel);

        if(ret==QMessageBox::Ok)
            qDebug()<<"User clicked OK! button.";
        if(ret==QMessageBox::Cancel)
            qDebug()<<"User Clicked Cancel Button.";
    });



}

Widget::~Widget()
{
}

