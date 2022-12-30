#include "widget.h"
#include "./ui_widget.h"

#include <QSettings>
#include <QColorDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i = 0; i < 4; ++i) {
        m_color_list.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button1_clicked()
{
    open_color_dialog(ui->button1,0);
}

void Widget::on_button2_clicked()
{
    open_color_dialog(ui->button2,1);
}

void Widget::on_button3_clicked()
{
    open_color_dialog(ui->button3,2);
}

void Widget::on_button4_clicked()
{
    open_color_dialog(ui->button4,3);
}


void Widget::on_save_button_clicked()
{
    for (int i = 0; i < 4; ++i) {
        QString name= "button" +QString::number(i+1);
        save_color(name,m_color_list[i]);
    }
}


void Widget::on_laod_button_clicked()
{
    set_loaded_color("button1",0,ui->button1);
    set_loaded_color("button2",1,ui->button2);
    set_loaded_color("button3",2,ui->button3);
    set_loaded_color("button4",3,ui->button4);
}

void Widget::save_color(QString key, QColor color)
{
    int red= color.red();
    int green=color.green();
    int blue = color.blue();

    QSettings settings("Kaan", "Color Settings");

    settings.beginGroup("ButtonColor");

    settings.setValue(key + "r",red);
    settings.setValue(key + "g",green);
    settings.setValue(key + "b",blue);
    settings.endGroup();


}

QColor Widget::load_color(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("Kaan", "Color Settings");

    settings.beginGroup("ButtonColor");

    red = settings.value(key + "r",QVariant(0)).toInt();
    green = settings.value(key + "g",QVariant(0)).toInt();
    blue = settings.value(key + "b",QVariant(0)).toInt();
    settings.endGroup();

    return QColor(red,green,blue);
}

void Widget::set_loaded_color(QString key, int index, QPushButton *button)
{
    QColor color=load_color(key);
    m_color_list[index]=color;
    QString css=QString("background-color:%1").arg(color.name());
    button->setStyleSheet(css);
}

void Widget::open_color_dialog(QPushButton *button, int index)
{
    QColor color= QColorDialog::getColor(m_color_list[index],this,"Choose button bg color");
    if (color.isValid()) {
        m_color_list[index]=color;
        QString css=QString("background-color:%1").arg(color.name());
        button->setStyleSheet(css);
    }

}







