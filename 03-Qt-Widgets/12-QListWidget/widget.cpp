#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->list_of_items->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->list_of_items->addItem("Item1");
    ui->list_of_items->addItem("Item2");
    QStringList list_of_strings;
    list_of_strings<<"Item3"<<"Item4"<<"Item5";
    ui->list_of_items->addItems(list_of_strings);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_add_item_button_clicked()
{
    int index=ui->list_of_items->count()+1;
    QString item_name= "Item" + QString::number(index);
    ui->list_of_items->addItem(item_name);
}

void Widget::on_remove_item_button_clicked()
{
    ui->list_of_items->takeItem(ui->list_of_items->currentRow());
}
void Widget::on_selected_items_button_clicked()
{
    QList<QListWidgetItem *> selected_items=ui->list_of_items->selectedItems();

    for (auto a : selected_items) {
        qDebug()<<"Selected item is "<< a->text();
    }

}

