#include "widget.h"
#include "./ui_widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup *button_group= new QButtonGroup(this);
    button_group->addButton(ui->windows_checkBox);
    button_group->addButton(ui->mac_checkBox);
    button_group->addButton(ui->linux_checkBox);
    button_group->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_windows_checkBox_toggled(bool checked)
{
    if (checked) {
        qDebug()<<"Windows checkbox is checked.";
    }else{
        qDebug()<<"Windows checkbox is unchecked.";
    }
}


void Widget::on_get_data_button_clicked()
{
    qDebug()<<"Getting data of Milk....";
    if (ui->milk_checkBox->isChecked()) {
        qDebug()<<"milk checkbox is checked.";
    }else{
        qDebug()<<"milk checkbox is unchecked.";
    }
}


void Widget::on_set_data_button_clicked()
{
    qDebug()<<"Setting data of Tea....";
    ui->tea_checkBox->toggle();
}

