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
	
	
	    for (list<Declaration *>::reverse_iterator it=m_listDeclaration.m_listDeclaration.rbegin(); it != m_listDeclaration.m_listDeclaration.rend(); ++it)
	    {
			(*it)->execute();
		}

	
	
	//Here we execute the instructions
	
    for (list<Instruction *>::reverse_iterator it=m_listInstruction.m_listInstruction.rbegin(); it != m_listInstruction.m_listInstruction.rend(); ++it)
    
    {
		
		(*it)->execute;
	}

	
	
}

void Programme::transformation()
{
    m_listInstruction->transformation();
}
