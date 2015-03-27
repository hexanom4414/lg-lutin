#include "Terme.h"
#include "Facteur.h"

void Terme::print()
{
    if(!m_isFacteur)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}

int Terme::eval()
{
    if(!m_isFacteur)
    {
    }
    return m_expDroite->eval();
}
