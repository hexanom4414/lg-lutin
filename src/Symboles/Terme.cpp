#include "Terme.h"
#include "Facteur.h"

void Terme::print()
{
    if(m_expGauche)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}
