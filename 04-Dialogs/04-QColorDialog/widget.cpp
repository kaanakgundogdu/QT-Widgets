#include "widget.h"
#include "./ui_widget.h"
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->text_label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_change_textcolor_button_clicked()
{
    QPalette palette=ui->text_label->palette();
    QColor text_color= palette.color(QPalette::WindowText);
    QColor chosen_color= QColorDialog::getColor(text_color,this,"Set Text Color");

    if (chosen_color.isValid()) {
        palette.setColor(QPalette::WindowText,chosen_color);
        ui->text_label->setPalette(palette);
    }else{
        qInfo()<<"Invalid Color!";
    }

}


void Widget::on_change_bgcolor_button_clicked()
{
    QPalette palette=ui->text_label->palette();
    QColor bg_color= palette.color(QPalette::Window);
    QColor chosen_color= QColorDialog::getColor(bg_color,this,"Set Background Color");

    if (chosen_color.isValid()) {
        palette.setColor(QPalette::Window,chosen_color);
        ui->text_label->setPalette(palette);
    }else{
        qInfo()<<"Invalid Color!";
    }
}

