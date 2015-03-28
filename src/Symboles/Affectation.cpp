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
}

void Affectation::staticCheck()
{
    if(!DeclMap::Instance().checkIdent(m_ident))
    {
        print();
        cout << ">>>> err : " << m_ident << " declaration manquante" << endl;
    }
    else if (DeclMap::Instance().getIsConst(m_ident))
    {
        print();
        cout << ">>>> err : affectation sur constante" << endl;
    }
    m_expression->staticCheck();
}
