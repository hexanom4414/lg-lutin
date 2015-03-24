#include "ListIdentificateur.h"

void ListIdentificateur::setAttribute(ListIdentificateur * p_listIdentificateur)
{
    while (!p_listIdentificateur->isEmpty())
    {
            setAttribute(p_listIdentificateur->getFront());
            p_listIdentificateur->popFront();
    }
    delete p_listIdentificateur;
}

void ListIdentificateur::setAttribute(Identificateur * p_Identificateur)
{
    m_listIdentificateur.push_back(p_Identificateur);
}

bool ListIdentificateur::isEmpty()
{
    return m_listIdentificateur.empty();
}

void ListIdentificateur::popFront()
{
    m_listIdentificateur.pop_front();
}

Identificateur * ListIdentificateur::getFront()
{
    return m_listIdentificateur.front();
}

void ListIdentificateur::print()
{
    for (list<Identificateur *>::iterator it=m_listIdentificateur.begin(); it != m_listIdentificateur.end(); ++it)
        (*it)->print();
}
