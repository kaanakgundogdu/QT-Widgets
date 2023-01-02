#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList()<< "ID"<<"Genre");

    QTreeWidgetItem* tree_item_1=new QTreeWidgetItem(ui->treeWidget);
    tree_item_1->setText(0,"01");
    tree_item_1->setText(1,"Seinen");

    QTreeWidgetItem* tree_item_2=new QTreeWidgetItem(ui->treeWidget);
    tree_item_2->setText(0,"02");
    tree_item_2->setText(1,"Shounen");

    QTreeWidgetItem* tree_item_3=new QTreeWidgetItem();
    tree_item_3->setText(0,"01");
    tree_item_3->setText(1,"One Piece");

    QTreeWidgetItem* tree_item_4=new QTreeWidgetItem();
    tree_item_4->setText(0,"02");
    tree_item_4->setText(1,"Naruto");

    QTreeWidgetItem* tree_item_5=new QTreeWidgetItem();
    tree_item_5->setText(0,"03");
    tree_item_5->setText(1,"Bleach");

    tree_item_2->addChild(tree_item_3);
    tree_item_2->addChild(tree_item_4);
    tree_item_2->addChild(tree_item_5);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_list_items_button_clicked()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);

        if (item) {
            qDebug()<<item->data(0,Qt::DisplayRole).toString()<<", "
                   <<item->data(1,Qt::DisplayRole).toString();

            if (item->childCount()!=0) {
                for (int j = 0; j < item->childCount(); ++j) {
                    auto child=item->child(j);
                    if (child) {
                        qDebug()<<child->data(0,Qt::DisplayRole).toString()<<", "
                               <<child->data(1,Qt::DisplayRole).toString();
                    }
                }
            }
        }
    }
}
