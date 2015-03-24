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

void ListIdentificateur::setAttribute(const string & identificateur)
{
    m_listIdentificateur.push_back(identificateur);
}

bool ListIdentificateur::isEmpty()
{
    return m_listIdentificateur.empty();
}

void ListIdentificateur::popFront()
{
    m_listIdentificateur.pop_front();
}

string ListIdentificateur::getFront()
{
    return m_listIdentificateur.front();
}

void ListIdentificateur::print()
{
    unsigned int i = m_listIdentificateur.size();
    for (list<string>::iterator it=m_listIdentificateur.begin(); it != m_listIdentificateur.end(); ++it)
    {
        cout << *it << " ";
        if(i != 1)
            cout << ", ";
        i--;
    }
}
