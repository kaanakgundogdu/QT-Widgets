#include "widget.h"
#include "./ui_widget.h"

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


void Widget::on_list_items_button_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
            QTableWidgetItem* item_ptr= ui->tableWidget->item(i,j);
            if (item_ptr) {
                QVariant data=item_ptr->data(Qt::DisplayRole);
                qDebug()<<data.toString();
            }
            else
                qDebug()<<"Empty";
        }
    }
}

void Widget::on_add_items_button_clicked()
{
    int row_c=ui->tableWidget->rowCount();
    int col_c=ui->tableWidget->columnCount();

    ui->tableWidget->insertRow(row_c);
    ui->tableWidget->insertColumn(col_c);

    row_c=ui->tableWidget->rowCount();
    col_c=ui->tableWidget->columnCount();

    //table widget handles memory as a parent
    QTableWidgetItem* new_item=new QTableWidgetItem("I'm new");
    ui->tableWidget->setItem(row_c-1,col_c-1,new_item);
}

