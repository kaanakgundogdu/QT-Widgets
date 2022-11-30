#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <stdlib.h>
#include <time.h>
#include <QDebug>


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
    void set_game();
    void on_guess_button_clicked();
    void on_restart_button_clicked();

private:
    Ui::Widget *ui;
    int guessed_number;
    int secret_number;
};
#endif // WIDGET_H
