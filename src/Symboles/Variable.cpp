#include "Variable.h"

void Variable::print()
{
    cout << "var ";
    m_listIdentificateur->print();
    cout << ";" << endl;
}

void Variable::staticCheck()
{
    m_listIdentificateur->staticCheck();
}


void Variable::execute()

{
	
	m_listIdentificateur->execute();
}

void Variable::transformation()
{
    m_listIdentificateur->transformation();
}


