#include "Affectation.h"

void Affectation::print()
{
    cout << m_ident << " := ";
    m_expression->print();
    cout << ";" << endl;
}

void Affectation::execute()
{
    global_declMap->setValue(m_ident, m_expression->eval());
}
