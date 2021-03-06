#include "ListAffectation.h"

void ListAffectation::setAttribute(const string & ident, double value)
{
    m_listAffectation.push_back(make_pair(ident, value));
}

void ListAffectation::setAttribute(ListAffectation * p_listAffectation)
{
    while (!p_listAffectation->isEmpty())
    {
        m_listAffectation.push_back(p_listAffectation->getFront());
        p_listAffectation->popFront();
    }
//    delete p_listAffectation;
}

bool ListAffectation::isEmpty()
{
    return m_listAffectation.empty();
}

void ListAffectation::popFront()
{
    m_listAffectation.pop_front();
}

pair<string,double> ListAffectation::getFront()
{
    return m_listAffectation.front();
}

void ListAffectation::print()
{
    unsigned int i = m_listAffectation.size();
    for (list<pair<string,double> >::reverse_iterator it=m_listAffectation.rbegin(); it != m_listAffectation.rend(); ++it)
    {
        cout << it->first << " = " << it->second << " ";
        if(i != 1)
            cout << " , ";
        i--;
    }
}

void ListAffectation::staticCheck()
{
    for (list<pair<string,double> >::reverse_iterator it=m_listAffectation.rbegin(); it != m_listAffectation.rend(); ++it)
    {
        if(DeclMap::Instance().checkIdent(it->first))
        {
            cerr << it->first << " = " << it->second << endl;
            cerr << ">>>> err : " << it->first << " deja declare" << endl;
        }
        else
        {
            DeclMap::Instance().addIdent(it->first, true, it->second);
        }
    }
}

void ListAffectation::execute()
{


	for (list<pair<string,double> >::reverse_iterator it=m_listAffectation.rbegin(); it != m_listAffectation.rend(); ++it)
    {
        if(DeclMap::Instance().checkIdent(it->first))
        {
            cerr << ">>>> err : " << it->first << " deja declare" << endl;
        }
        else
        {
            DeclMap::Instance().addIdent(it->first, true, it->second);
        }
    }
}



void ListAffectation::transformation()
{
    execute();
}

