#include "Ecriture.h"

void Ecriture::setExpression(Expression * p_expression)
{
    m_expression = p_expression;
}

void Ecriture::print()
{
    cout << "�crire ";
    m_expression->print();
}
