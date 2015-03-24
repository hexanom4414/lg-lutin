#include "OpM.h"

void OpM::print()
{
    if(m_type == MULT)
        cout << "* ";
    else if(m_type == DIV)
        cout << "/ ";
}
