#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    set_game();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_game()
{
    srand (time(NULL));
    secret_number= rand() % 10 + 1;
    qDebug()<< "Secret number is "<<QString::number(secret_number);
    ui->guess_button->setDisabled(false);
    ui->restart_button->setDisabled(true);
    ui->message_label->setText("");
    ui->guess_spinbox->setValue(1);
}


void Widget::on_guess_button_clicked()
{
    guessed_number=ui->guess_spinbox->value();
    if(guessed_number==secret_number){
        ui->message_label->setText("CONGRATS YOU GUESS THE NUMBER" + QString::number(guessed_number));
        ui->guess_button->setDisabled(true);
        ui->restart_button->setDisabled(false);
    }else{
        if(guessed_number>secret_number){
            ui->message_label->setText("Your number is greater than secret number");
        }else{
            ui->message_label->setText("Your number is lower than secret number");
        }
    }
}


void Widget::on_restart_button_clicked()
{
    set_game();
}

