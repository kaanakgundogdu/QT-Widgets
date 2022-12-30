#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>
#include <QPushButton>

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

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_save_button_clicked();

    void on_laod_button_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> m_color_list;

    void save_color(QString key, QColor color);
    QColor load_color(QString key);
    void set_loaded_color(QString key, int index, QPushButton* button);
    void open_color_dialog(QPushButton* button,int index);
};
#endif // WIDGET_H
