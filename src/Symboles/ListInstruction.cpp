#include "ListInstruction.h"

void ListInstruction::print()
{
    for (list<Instruction *>::iterator it=m_listInstruction.begin(); it != m_listInstruction.end(); ++it)
        (*it)->print();
}

void ListInstruction::addToList(ListInstruction * p_listInstruction)
{
    while (!p_listInstruction->isEmpty())
    {
            addToList(p_listInstruction->getFront());
            p_listInstruction->popFront();
    }
    delete p_listInstruction;
}

void ListInstruction::addToList(Instruction * p_Instruction)
{
    m_listInstruction.push_back(p_Instruction);
}

bool ListInstruction::isEmpty()
{
    return m_listInstruction.empty();
}

Instruction * ListInstruction::getFront()
{
    return m_listInstruction.front();
}

void ListInstruction::popFront()
{
    m_listInstruction.pop_front();
}
