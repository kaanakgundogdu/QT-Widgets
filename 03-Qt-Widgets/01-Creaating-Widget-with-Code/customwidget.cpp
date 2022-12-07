#include "customwidget.h"
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>


CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{
    QLabel *label =  new QLabel(this);
    label->setText("Kaan Akg\nThis is a label");

    label->move(100,100);

    QPalette label1_palette;
    label1_palette.setColor(QPalette::Window,Qt::yellow);
    label1_palette.setColor(QPalette::WindowText,Qt::red);

    QFont label1Font("Times", 20,QFont::Bold);

    QLabel *label1 =  new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("New colored label");
    label1->setFont(label1Font);
    label1->setPalette(label1_palette);
    label1->move(200,200);

    QPushButton *button= new QPushButton(this);
    QFont button_font("Times", 30,QFont::Bold);
    button->setText("I'm a Button!");
    button->setFont(button_font);
    button->move(100,250);
    connect(button,&QPushButton::clicked,
            this,&CustomWidget::button_clicked);
}

void CustomWidget::button_clicked()
{
    QMessageBox::information(this, "Message", "Button Clicked");
}

QSize CustomWidget::sizeHint() const
{
    return QSize(500,500);
}
