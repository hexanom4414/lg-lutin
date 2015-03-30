#include "Ecriture.h"

void Ecriture::print()
{
    cout << "ecrire ";
    m_expression->print();
    cout << ";" << endl;
}

void Ecriture::staticCheck()
{
    m_expression->staticCheck();
}


void Ecriture::execute()
{			
	cout<<"ecriture "<< m_expression->eval()<<endl;
	
}
