#include "Automate.h"

Automate::Automate()
{
    cout << "Automate created" << endl;
}

Automate::~Automate()
{
    //dtor
}

void Automate::shift(AbstractEtat * etat)
{
    m_pileEtats.push(etat);
}
