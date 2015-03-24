#include "DeclMap.h"

DeclMap::DeclMap()
{
}

DeclMap::~DeclMap()
{
}

bool DeclMap::checkIdent(const string & ident)
{
    if(m_declMap.find(ident) == m_declMap.end())
        return true;
    else
        return false;
}

int DeclMap::getValue(const string & ident)
{
    return m_declMap.find(ident)->second.first;
}

void DeclMap::setValue(const string & ident, int val)
{
    if(checkIdent(ident))
    {
        m_it = m_declMap.find(ident);
        m_it->second.first = val;
        m_it->second.second = true;
    }
}

void DeclMap::addIdent(const string & ident)
{
    if(checkIdent(ident))
    {
        m_declMap[ident] = make_pair(0, false);
    }
}

void DeclMap::print()
{
    for (m_it=m_declMap.begin(); m_it!=m_declMap.end(); ++m_it)
        cout << m_it->first << " := " << m_it->second.first << endl;
}
