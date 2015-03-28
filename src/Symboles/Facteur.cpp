#include "Facteur.h"
#include "Expression.h"

void Facteur::print()
{
    if(m_isAnExpression)
    {
        cout << "( ";
        m_expression->print();
        cout << ") ";
    }
    else if (m_identificateur.compare("") == 0)
    {
        cout << m_valeur << " ";
    }
    else
    {
        cout << m_identificateur << " ";
    }
}

int Facteur::eval()
{
    if(m_isAnExpression)
    {
        return m_expression->eval();
    }
    else if (m_identificateur.compare("") == 0)
    {
        return m_valeur;
    }
    else
    {
        return DeclMap::Instance().getValue(m_identificateur);
    }
}

void Facteur::staticCheck()
{
    if(m_isAnExpression)
    {
        m_expression->staticCheck();
    }
}
