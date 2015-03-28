#include "Expression.h"

void Expression::print()
{
    if(!m_isTerme)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}

int Expression::eval()
{
    if(!m_isTerme)
    {

    }
    return m_expDroite->eval();
}

void Expression::staticCheck()
{
    if(!m_isTerme)
    {
        m_expGauche->staticCheck();
    }
    m_expDroite->staticCheck();
}
