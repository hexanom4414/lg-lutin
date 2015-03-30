#include "Constante.h"

void Constante::print()
{
    cout << "const ";
    m_listAffectation->print();
    cout << ";" << endl;
}

void Constante::staticCheck()
{
    m_listAffectation->staticCheck();
}

void Constante::execute()

{
	
  m_listAffectation->execute();

}

void Constante::transformation()
{
    m_listAffectation->transformation();
}


