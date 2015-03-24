#include "Facteur.h"
#include "Expression.h"

void Facteur::print()
{
    if(m_isAnExpression)
    {
        cout << "(";
        m_expression->print();
        cout << ") " << endl;
    }
    else if (m_identificateur.compare("") == 0)
    {
        cout << m_valeur << " " << endl;
    }
    else
    {
        cout << m_identificateur << " " << endl;
    }
}
