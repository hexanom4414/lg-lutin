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

<<<<<<< HEAD
void Constante::execute()

{
	
  m_listAffectation->execute();

=======
void Constante::transformation()
{
    m_listAffectation->transformation();
}

void Constante::execute()
{
    m_listAffectation->execute();
>>>>>>> 58805c03a0325602104eb02ed4357644bd60daad
}
