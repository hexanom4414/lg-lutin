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
    else if (m_identificateur.compare("") != 0)
    {
        if(!DeclMap::Instance().checkIdent(m_identificateur))
        {
            print();
            cout << endl << ">>>> err : " << m_identificateur << " declaration manquante" << endl;
        }
        else
        {
            DeclMap::Instance().setUsed(m_identificateur);
        }
    }
}

bool Facteur::isConst()
{
    if(m_isAnExpression)
    {
        if(m_expression->isConst())
        {
            m_isAnExpression = false;
            m_valeur = m_expression->eval();
            return true;
        }
        return false;
    }
    else if (m_identificateur.compare("") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
