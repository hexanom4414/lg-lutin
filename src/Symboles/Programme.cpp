#include "Programme.h"

void Programme::print()
{
    m_listDeclaration->print();
    m_listInstruction->print();
}

void Programme::staticCheck()
{
    m_listDeclaration->staticCheck();
    m_listInstruction->staticCheck();
}

Programme::Programme (const Programme & p) : SymboleComplexe (p)

{
	m_listInstruction = p.m_listInstruction;
	m_listDeclaration = p.m_listDeclaration;
}

void Programme::execute()

{
	// Here we fill in the map
	m_listDeclaration->execute();

	//Here we execute the instructions
	m_listInstruction->execute();
}

void Programme::transformation()
{
    m_listDeclaration->transformation();
    m_listInstruction->transformation();
}
