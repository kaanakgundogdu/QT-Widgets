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
    void on_change_textcolor_button_clicked();

    void on_change_bgcolor_button_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
