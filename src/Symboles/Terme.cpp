#include "Terme.h"

void Terme::print()
{
    if(m_terme)
    {
        m_terme->print();
        m_opM->print();
    }
    m_facteur->print();
}
