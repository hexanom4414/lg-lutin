#include "Affectation.h"

void Affectation::print()
{
    cout << m_ident << " := ";
    m_expression->print();
    cout << ";" << endl;
}
