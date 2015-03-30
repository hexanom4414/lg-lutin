#include "ListDeclaration.h"

void ListDeclaration::print()
{
    for (list<Declaration *>::reverse_iterator it=m_listDeclaration.rbegin(); it != m_listDeclaration.rend(); ++it)
        (*it)->print();
}

void ListDeclaration::setAttribute(ListDeclaration * p_listDeclaration)
{
    while (!p_listDeclaration->isEmpty())
    {
        setAttribute(p_listDeclaration->getFront());
        p_listDeclaration->popFront();
    }
//    delete p_listDeclaration;
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

void ListDeclaration::staticCheck()
{
    for (list<Declaration *>::reverse_iterator it=m_listDeclaration.rbegin(); it != m_listDeclaration.rend(); ++it)
        (*it)->staticCheck();
}


void ListDeclaration::execute()
{
    for (list<Declaration *>::reverse_iterator it=m_listDeclaration.rbegin(); it != m_listDeclaration.rend(); ++it)
        (*it)->execute();


}


void ListDeclaration::transformation()
{
    for (list<Declaration *>::reverse_iterator it=m_listDeclaration.rbegin(); it != m_listDeclaration.rend(); ++it)
        (*it)->transformation();
}
