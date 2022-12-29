#include "widget.h"
#include "./ui_widget.h"
#include <QInputDialog>

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


void Widget::on_input_button_clicked()
{
    bool is_ok=false;
    double chosen_number=QInputDialog::getDouble(this,tr("Chose a number"),
                                     tr("Number:"),
                                     0.00,-100,100,2,&is_ok);
    if (is_ok) {
        qInfo()<<chosen_number;
    }
}

void Widget::on_choise_button_clicked()
{
    QStringList choises={"Zoro","Sanji","Luffy","Brook","Franky"};

    bool is_ok=false;
    QString chosen_item=QInputDialog::getItem(this,tr("Choose Your Favorite Character"),
                                     tr("Character:"),
                                     choises,0,false,&is_ok);
    if (is_ok && !chosen_item.isEmpty()) {
        qInfo()<<chosen_item;
    }
}



