#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_person.set_weight(ui->weight_spinbox->value());
    m_time=ui->time_spinbox->value();
    m_speed=ui->speed_spinbox->value();

    connect(ui->weight_spinbox,&QDoubleSpinBox::valueChanged,
            this,&Widget::weight_changed);
    connect(ui->speed_spinbox,&QDoubleSpinBox::valueChanged,
            this,&Widget::speed_changed);
    connect(ui->time_spinbox,&QDoubleSpinBox::valueChanged,
            this,&Widget::time_changed);

    connect(this,&Widget::calorie_count_changed,
            [=](){
        ui->calorie_value_text->setText(QString::number(m_calorie_count));
    });

    calculate_calories();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_calories(){
    m_calorie_count=((0.0215 * (m_speed*m_speed*m_speed)) - (0.1765*(m_speed*m_speed))
                     + (0.8710 *m_speed) + 1.4577) * m_person.get_weight()*m_time;
    emit calorie_count_changed();
}
void Widget::weight_changed(double weight){
    m_person.set_weight(weight);
    calculate_calories();
}
void Widget::time_changed(double time){
    m_time=time;
    calculate_calories();
}
void Widget::speed_changed(double speed ){
    m_speed=speed;
    calculate_calories();
}




