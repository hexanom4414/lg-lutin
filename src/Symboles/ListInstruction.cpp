#include "ListInstruction.h"

void ListInstruction::print()
{
    for (list<Instruction *>::reverse_iterator it=m_listInstruction.rbegin(); it != m_listInstruction.rend(); ++it)
        (*it)->print();
}

void ListInstruction::staticCheck()
{
    for (list<Instruction *>::reverse_iterator it=m_listInstruction.rbegin(); it != m_listInstruction.rend(); ++it)
        (*it)->staticCheck();
}

void ListInstruction::transformation()
{
    for (list<Instruction *>::reverse_iterator it=m_listInstruction.rbegin(); it != m_listInstruction.rend(); ++it)
        (*it)->transformation();
}

void ListInstruction::execute()
{
    for (list<Instruction *>::reverse_iterator it=m_listInstruction.rbegin(); it != m_listInstruction.rend(); ++it)
        (*it)->execute();
}


void ListInstruction::setAttribute(ListInstruction * p_listInstruction)
{
    while (!p_listInstruction->isEmpty())
    {
        setAttribute(p_listInstruction->getFront());
        p_listInstruction->popFront();
    }
//    delete p_listInstruction;
}

void ListInstruction::setAttribute(Instruction * p_Instruction)
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
