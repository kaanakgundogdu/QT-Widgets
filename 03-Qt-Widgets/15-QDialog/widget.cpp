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


void Widget::on_provide_button_clicked()
{
    CharacterDialog* character_dialog= new CharacterDialog(this);




    connect(character_dialog,&CharacterDialog::accepted,[=](){
       QString name=character_dialog->name();
       QString fav=character_dialog->fav_char();

       ui->info_area->setText("Your name is "+ name + " and your favorite char is " +fav);

    });

    connect(character_dialog,&CharacterDialog::rejected,[=](){
        ui->info_area->setText("Your infos rejected! Try again.");
    });
    character_dialog->show();
}

