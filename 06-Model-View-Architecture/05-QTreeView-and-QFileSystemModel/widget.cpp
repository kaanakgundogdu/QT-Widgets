#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString path=QDir::currentPath();
    dir_model=new QFileSystemModel(this);
    dir_model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    dir_model->setRootPath(path);

    ui->treeView->setModel(dir_model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_read_data_button_clicked()
{
    qDebug()<<"Row Count: "<<dir_model->rowCount(QModelIndex());
    qDebug()<<"Column Count: "<<dir_model->columnCount(QModelIndex());

    QModelIndex index=dir_model->index(0,0,QModelIndex());
    QVariant data=index.data();
    qDebug()<<"Data: "<<data;
}







