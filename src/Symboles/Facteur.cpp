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
        if(DeclMap::Instance().getVarIsReaded(m_identificateur))
            cout << m_identificateur << " ";
        else if(!DeclMap::Instance().getIsInitialized(m_identificateur))
            cout << m_identificateur << " ";
        else
            cout << DeclMap::Instance().getValue(m_identificateur) << " ";
    }
}

double Facteur::eval()
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
            cout << endl << ">>>> err : " << m_identificateur << " declaration manquante" << endl;
        }
        else if(!DeclMap::Instance().getIsInitialized(m_identificateur))
        {
            cout << endl << ">>>> err : " << m_identificateur << " initialisation manquante" << endl;
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
            m_isAnExpression == false;
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
        if(
            DeclMap::Instance().getIsConst(m_identificateur) ||
            (!DeclMap::Instance().getVarIsReaded(m_identificateur) &&
             DeclMap::Instance().getIsInitialized(m_identificateur))
        )
        {
            m_valeur = DeclMap::Instance().getValue(m_identificateur);
            m_identificateur = "";
            return true;
        }
        else
            return false;
    }
}
