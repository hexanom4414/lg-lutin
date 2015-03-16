#include "Facteur.h"

void Facteur::print()
{
    if(m_identificateur)
        m_identificateur->print();
    else if(m_valIsValid)
        cout << m_val << " ";
    else
        cout << "( ";
}

void Facteur::setAttribute(Valeur * p_valeur)
{
    m_val = p_valeur->getValue();
    m_valIsValid = true;
}
