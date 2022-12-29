#include "widget.h"
#include "./ui_widget.h"
#include <QFontDialog>
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


void Widget::on_change_font_button_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
        ui->text_to_change->setFont(font);
    } else {
        qInfo()<<"You didn't choose a valid font";
    }

}

