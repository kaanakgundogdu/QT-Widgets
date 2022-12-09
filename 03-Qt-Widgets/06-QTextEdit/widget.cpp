#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setup_ui();
    setFixedSize(400,400);
}

Widget::~Widget()
{
}

void Widget::setup_ui()
{
    QFont label_font("Times",10,QFont::Bold);
    QLabel *title_label=new QLabel("Text Area:",this);
    title_label->setFont(label_font);
    title_label->move(100,25);

    QTextEdit *text_area=new  QTextEdit(this);
    text_area->move(70,55);

    connect(text_area,&QTextEdit::textChanged,[=]() {
       qDebug()<<"Text Changed";
    });

    QPushButton *copy_button= new QPushButton("Copy",this);
    copy_button->setMinimumSize(50,30);
    copy_button->move(10,250);
    connect(copy_button,&QPushButton::clicked,[=](){
     text_area->copy();
    });


    QPushButton *cut_button= new QPushButton("Cut",this);
    cut_button->setMinimumSize(50,30);
    cut_button->move(100,250);
    connect(cut_button,&QPushButton::clicked,[=](){
     text_area->cut();
    });


    QPushButton *paste_button= new QPushButton("Paste",this);
    paste_button->setMinimumSize(50,30);
    paste_button->move(200,250);
    connect(paste_button,&QPushButton::clicked,[=](){
     text_area->paste();
    });



    QPushButton *undo_button= new QPushButton("Undo",this);
    undo_button->setMinimumSize(50,30);
    undo_button->move(10,300);
    connect(undo_button,&QPushButton::clicked,[=](){
     text_area->undo();
    });


    QPushButton *redo_button= new QPushButton("Redo",this);
    redo_button->setMinimumSize(50,30);
    redo_button->move(100,300);
    connect(redo_button,&QPushButton::clicked,[=](){
     text_area->redo();
    });



}

