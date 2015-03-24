#include "OpA.h"

void OpA::print()
{
    if(m_type == PLUS)
        cout << "+ ";
    else if(m_type == MOINS)
        cout << "- ";
}
