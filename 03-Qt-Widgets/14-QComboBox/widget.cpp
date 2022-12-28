#include "widget.h"
#include "./ui_widget.h"

#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Red");
    ui->comboBox->addItem("White");
    ui->comboBox->addItem("Black");
    ui->comboBox->addItem("Green");
    ui->comboBox->addItem("Gray");
    ui->comboBox->addItem("Yellow");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_capture_button_clicked()
{
    qDebug()<<"Currently selected item is: "<<ui->comboBox->currentText()<<" index is: "<<
              QString::number(ui->comboBox->currentIndex());
}


void Widget::on_set_button_clicked()
{
    ui->comboBox->setCurrentIndex(5);
}


void Widget::on_list_button_clicked()
{
    qDebug()<<"Total element count is" << ui->comboBox->count();
    for (int i = 0; i < ui->comboBox->count(); ++i) {
        qDebug()<<"Index: "<< QString::number(i)<<". Element is:" << ui->comboBox->itemText(i);
    }
}

