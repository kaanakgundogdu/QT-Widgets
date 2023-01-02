#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item_ptr=ui->listWidget->item(i);
        item_ptr->setToolTip("This is a tooltip for no. "+QString::number(i));
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_list_item_button_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item_ptr=ui->listWidget->item(i);
        QVariant data=item_ptr->data(Qt::ToolTipRole);
        qDebug()<<data.toString();
    }
}


void Widget::on_add_item_button_clicked()
{
    ui->listWidget->addItem("Random char");

}

