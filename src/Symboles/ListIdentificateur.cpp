#include "ListIdentificateur.h"

void ListIdentificateur::setAttribute(ListIdentificateur * p_listIdentificateur)
{
    while (!p_listIdentificateur->isEmpty())
    {
        setAttribute(p_listIdentificateur->getFront());
        p_listIdentificateur->popFront();
    }
//    delete p_listIdentificateur;
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
    for (list<string>::reverse_iterator it=m_listIdentificateur.rbegin(); it != m_listIdentificateur.rend(); ++it)
    {
        cout << *it << " ";
        if(i != 1)
            cout << ", ";
        i--;
    }
}

void ListIdentificateur::staticCheck()
{
    for (list<string>::reverse_iterator it=m_listIdentificateur.rbegin(); it != m_listIdentificateur.rend(); ++it)
    {
        if(DeclMap::Instance().checkIdent(*it))
        {
            cout << ">>>> err : " << *it << " deja declare" << endl;
        }
        else
        {
            DeclMap::Instance().addIdent(*it, false);
        }
    }
}

void ListIdentificateur::transformation()
{
    execute();
}

void ListIdentificateur::execute()
{
    for (list<string>::reverse_iterator it=m_listIdentificateur.rbegin(); it != m_listIdentificateur.rend(); ++it)
    {
        DeclMap::Instance().addIdent(*it, false);
    }
}
