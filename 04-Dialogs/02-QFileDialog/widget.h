#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_dir_button_clicked();
    void on_images_button_clicked();

    void on_multiple_images_button_clicked();

    void on_get_save_name_buton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
