#include "Affectation.h"

void Affectation::print()
{
    cout << m_ident << " := ";
    m_expression->print();
    cout << ";" << endl;
}

void Affectation::execute()
{
    DeclMap::Instance().setValue(m_ident, m_expression->eval());
    DeclMap::Instance().setInitialized(m_ident);
}

void Affectation::staticCheck()
{
    if(!DeclMap::Instance().checkIdent(m_ident))
    {
        cerr << ">>>> err : " << m_ident << " declaration manquante" << endl;
    }
    else if (DeclMap::Instance().getIsConst(m_ident))
    {
        cerr << ">>>> err : affectation sur constante" << endl;
    }
    else
    {
        DeclMap::Instance().setInitialized(m_ident);
    }
    m_expression->staticCheck();
}

void Affectation::transformation()
{
    if(m_expression->isConst())
    {
        execute();
    }
    while(m_expression != m_expression->elementNeutre()) // Point fixe
        m_expression =  m_expression->elementNeutre();
}
