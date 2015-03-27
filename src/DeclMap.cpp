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
    return m_declMap.find(ident)->second.value;
}

void DeclMap::setValue(const string & ident, int val)
{
    if(checkIdent(ident))
    {
        m_it = m_declMap.find(ident);
        m_it->second.value = val;
        m_it->second.isInitialized = true;
    }
}

void DeclMap::addIdent(const string & ident, bool isConst, int value)
{
    if(checkIdent(ident))
    {
        IdentValue t_identValue;
        t_identValue.isConst = isConst;
        t_identValue.isInitialized = isConst;
        t_identValue.value = value;
        m_declMap[ident] = t_identValue;
    }
}

void DeclMap::print()
{
    for (m_it=m_declMap.begin(); m_it!=m_declMap.end(); ++m_it)
        cout << m_it->first << " := " << m_it->second.value << endl;
}
