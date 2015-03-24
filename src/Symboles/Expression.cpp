#include "Expression.h"

void Expression::print()
{
    if(m_expGauche)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}
