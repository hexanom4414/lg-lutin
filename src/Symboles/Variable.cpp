#include "Variable.h"

void Variable::print()
{
    cout << "var ";
    m_listIdentificateur->print();
    cout << ";" << endl;
}

void Variable::staticCheck()
{
    m_listIdentificateur->staticCheck();
}
