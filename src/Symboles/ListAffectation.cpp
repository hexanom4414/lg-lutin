#include "ListAffectation.h"

void ListAffectation::setAttribute(const string & ident, int value)
{

}

void ListAffectation::setAttribute(ListAffectation * p_listAffectation)
{
    while (!p_listAffectation->isEmpty())
    {
        addToList(p_listAffectation->getFront());
        p_listAffectation->popFront();
    }
//    delete p_listAffectation;
}

void ListAffectation::addToList(const string & ident, int value)
{
    m_listAffectation.push_back(make_pair(ident, value));
}

void ListAffectation::addToList(pair<string,int> p_affectation)
{
    m_listAffectation.push_back(p_affectation);
}

bool ListAffectation::isEmpty()
{
    return m_listAffectation.empty();
}

void ListAffectation::popFront()
{
    m_listAffectation.pop_front();
}

pair<string,int> ListAffectation::getFront()
{
    return m_listAffectation.front();
}

void ListAffectation::print()
{
    unsigned int i = m_listAffectation.size();
    for (list<pair<string,int> >::iterator it=m_listAffectation.begin(); it != m_listAffectation.end(); ++it)
    {
        cout << it->first << " = " << it->second;
        if(i != 1)
            cout << " , ";
        else
            cout << " ; " << endl;
    }
}
