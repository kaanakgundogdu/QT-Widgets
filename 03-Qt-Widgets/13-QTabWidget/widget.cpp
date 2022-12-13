#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QWidget *widget= new QWidget(this);
    QVBoxLayout *vbox=new QVBoxLayout(this);

    vbox->addWidget(new QPushButton("Button1",this));
    vbox->addWidget(new QPushButton("Button2",this));
    vbox->addWidget(new QPushButton("Button3",this));
    vbox->addWidget(new QPushButton("Button4",this));
    QPushButton *button_4=new QPushButton("Button4",this);
    connect(button_4,&QPushButton::clicked,[=](){
       qDebug()<< "Button 4 from custom tab clicked";
    });

    vbox->addWidget(button_4);
    vbox->addSpacerItem(new QSpacerItem(100,200));
    widget->setLayout(vbox);

    int index_tab = ui->tabWidget->count()+1;
    ui->tabWidget->insertTab(index_tab,widget,"Tab 4");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_3_clicked()
{
    qDebug()<<"Button 3 clicked";
}

