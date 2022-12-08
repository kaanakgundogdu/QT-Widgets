#include "person.h"


void Person::set_weight(double weight)
{
    if(m_weight!=weight){
        m_weight=weight;
        emit weight_changed();
    }
}
