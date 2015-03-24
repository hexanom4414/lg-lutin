#include "Constante.h"

void Constante::print()
{
    cout << "const ";
    m_listAffectation->print();
    cout << ";" << endl;
}
