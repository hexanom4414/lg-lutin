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

void Programme::transformation()
{
    m_listInstruction->transformation();
}
