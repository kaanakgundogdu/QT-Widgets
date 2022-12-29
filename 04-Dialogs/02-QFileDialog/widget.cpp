#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QDebug>

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

void Widget::on_dir_button_clicked()
{
    QString dir=QFileDialog::getExistingDirectory(this,("Select Directory"),
                                                  QString(),
                                                  QFileDialog::ShowDirsOnly |
                                                  QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
}

void Widget::on_images_button_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,("Select An Image"),
                                                  QString(),
                                                   tr("Images(*.png *.jpg *xpm)"));
    qDebug()<<file_name;
}

void Widget::on_multiple_images_button_clicked()
{
    QStringList files_name=QFileDialog::getOpenFileNames(this,("Select Multiple Images"),
                                                  QString(),
                                                   tr("Images(*.png *.jpg *xpm)"));
    qDebug()<<files_name;
}

void Widget::on_get_save_name_buton_clicked()
{
    QString file_name=QFileDialog::getSaveFileName(this,("Save Filef"),
                                                  QString(),
                                                   tr("Images(*.png *.jpg *xpm)"));
    qDebug()<<file_name;
}












