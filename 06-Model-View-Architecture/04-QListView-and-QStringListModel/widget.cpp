#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model =  new QStringListModel(this);

    QStringList list{"Luffy","Zoro","Sanji","Usopp","Brook","Franky"};

    model->setStringList(list);

    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_show_items_button_clicked()
{
    QStringList list=model->stringList();
    qDebug()<<list;
    for (int i = 0; i < model->rowCount(QModelIndex()); ++i) {
        auto index=model->index(i,0,QModelIndex());
        auto data =index.data();
        //or
        //auto data=model->data(index);
        qDebug()<<data.toString();
    }
}

