#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *firstname_label=new QLabel("First Name:",this);
    firstname_label->setMinimumSize(70,50);
    firstname_label->move(10,10);

    QLineEdit *fn_line_edit=new QLineEdit(this);
    fn_line_edit->setMinimumSize(150,30);
    fn_line_edit->move(100,25);

    QLabel *lastname_label=new QLabel("Last Name:",this);
    lastname_label->setMinimumSize(70,50);
    lastname_label->move(10,60);

    QLineEdit *ln_line_edit=new QLineEdit(this);
    ln_line_edit->setMinimumSize(150,30);
    ln_line_edit->move(100,75);


    QLabel *city_label=new QLabel("City:",this);
    city_label->setMinimumSize(70,50);
    city_label->move(10,110);

    QLineEdit *city_line_edit=new QLineEdit(this);
    city_line_edit->setMinimumSize(150,30);
    city_line_edit->move(100,125);


    QFont button_font("Times",14,QFont::StyleItalic);
    QPushButton *submit_button= new QPushButton("Submit",this);
    submit_button->setMinimumSize(50,30);
    submit_button->setFont(button_font);
    submit_button->move(75,180);

    connect(submit_button,&QPushButton::clicked,this, [=](){
       QString first_name_text=fn_line_edit->text();
       QString last_name_text=ln_line_edit->text();
       QString city_text=city_line_edit->text();

       if(!first_name_text.isEmpty() && !last_name_text.isEmpty() && !city_text.isEmpty()){
           qInfo()<<"First name: "<<first_name_text;
           qInfo()<<"Last name: "<<last_name_text;
           qInfo()<<"City: "<<city_text;
       }else{
           qDebug()<<"There is a empty area.";
       }
    });


    connect(fn_line_edit,&QLineEdit::cursorPositionChanged,[=](){
       qDebug()<<"Cursor position is: "<<fn_line_edit->cursorPosition();
    });

    connect(ln_line_edit,&QLineEdit::editingFinished,[=](){
       qDebug()<<"Editing finished for last name.";
    });

    connect(fn_line_edit,&QLineEdit::returnPressed,[=](){
       qDebug()<<"Pressed enter(return).";
    });

    connect(city_line_edit,&QLineEdit::textChanged,[=](){
       qDebug()<<"Text changed: "<<city_line_edit->text();
    });

    fn_line_edit->setPlaceholderText("First Name");
    ln_line_edit->setPlaceholderText("Last Name");
    city_line_edit->setPlaceholderText("City Name");
}

Widget::~Widget()
{
}

