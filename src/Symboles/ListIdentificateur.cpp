#include "ListIdentificateur.h"

void ListIdentificateur::addToList(ListIdentificateur * p_listIdentificateur)
{
    while (!p_listIdentificateur->isEmpty())
    {
            addToList(p_listIdentificateur->getFront());
            p_listIdentificateur->popFront();
    }
    delete p_listIdentificateur;
}

void ListIdentificateur::addToList(Identificateur * p_Identificateur)
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
