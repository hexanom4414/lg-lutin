#include "Expression.h"

void Expression::print()
{
    if(m_expression)
    {
        m_expression->print();
        m_opA->print();
    }
    m_terme->print();
}

void Expression::setAttribute(OpA * p_opA)
{
    m_opA = p_opA;
}

void Expression::setAttribute(Terme * p_terme)
{
    m_terme = p_terme;
}

void Expression::setAttribute(Expression * p_expression)
{
    m_expression = p_expression;
}
