#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    double get_weight()const{return m_weight;}
    void set_weight(double weight);


signals:
    void weight_changed();

private:
    double m_weight=0.0;

};

#endif // PERSON_H
