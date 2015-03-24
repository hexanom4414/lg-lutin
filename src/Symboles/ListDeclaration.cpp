#include "ListDeclaration.h"

void ListDeclaration::print()
{
    for (list<Declaration *>::iterator it=m_listDeclaration.begin(); it != m_listDeclaration.end(); ++it)
        (*it)->print();
}

void ListDeclaration::setAttribute(ListDeclaration * p_listDeclaration)
{
    while (!p_listDeclaration->isEmpty())
    {
        setAttribute(p_listDeclaration->getFront());
        p_listDeclaration->popFront();
    }
    delete p_listDeclaration;
}

void ListDeclaration::setAttribute(Declaration * p_Declaration)
{
    m_listDeclaration.push_back(p_Declaration);
}

bool ListDeclaration::isEmpty()
{
    return m_listDeclaration.empty();
}

Declaration * ListDeclaration::getFront()
{
    return m_listDeclaration.front();
}

void ListDeclaration::popFront()
{
    m_listDeclaration.pop_front();
}
