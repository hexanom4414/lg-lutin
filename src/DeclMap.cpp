#include "DeclMap.h"

DeclMap DeclMap::m_instance=DeclMap();

DeclMap::DeclMap()
{
}

DeclMap::~DeclMap()
{
}

DeclMap& DeclMap::Instance()
{
    return m_instance;
}

bool DeclMap::checkIdent(const string & ident)
{
    if(m_declMap.find(ident) == m_declMap.end())
        return false;
    else
        return true;
}

int DeclMap::getValue(const string & ident)
{
    return m_declMap.find(ident)->second.value;
}

bool DeclMap::getIsConst(const string & ident)
{
    return m_declMap.find(ident)->second.isConst;
}

bool DeclMap::getIsInitialized(const string & ident)
{
    return m_declMap.find(ident)->second.isInitialized;
}

bool DeclMap::getVarIsReaded(const string & ident)
{
    return m_declMap.find(ident)->second.varIsReaded;
}

void DeclMap::setValue(const string & ident, int val)
{
    if(checkIdent(ident))
    {
        m_it = m_declMap.find(ident);
        if(!m_it->second.isConst)
        {
            m_it->second.value = val;
            m_it->second.isInitialized = true;
        }
        else
            cout << "!!! setValue on const !!!" << endl;
    }
}

void DeclMap::addIdent(const string & ident, bool isConst, int value)
{
    if(!checkIdent(ident))
    {
        IdentValue t_identValue;
        t_identValue.isConst = isConst;
        t_identValue.isInitialized = isConst;
        t_identValue.isUsed = false;
        t_identValue.value = value;
        t_identValue.varIsReaded = false;
        m_declMap[ident] = t_identValue;
    }
}

void DeclMap::print()
{
    for (m_it=m_declMap.begin(); m_it!=m_declMap.end(); ++m_it)
        cout << m_it->first <<
             " -> value : " << m_it->second.value <<
             ", const : " << m_it->second.isConst <<
             ", initialized : " << m_it->second.isInitialized <<
             ", used : " << m_it->second.isUsed <<
             ", readed : " << m_it->second.varIsReaded <<
             endl;
    cout << endl;
}

void DeclMap::staticCheck()
{
    for (m_it=m_declMap.begin(); m_it!=m_declMap.end(); ++m_it)
    {
        if(!m_it->second.isUsed)
        {
            cout << m_it->first << " n'est pas utilise" << endl;
        }
        if(!m_it->second.isInitialized)
        {
            cout << m_it->first << " n'est pas affecte" << endl;
        }
    }
}

void DeclMap::setUsed(const string & ident)
{
    m_declMap.find(ident)->second.isUsed = true;
}

void DeclMap::setInitialized(const string & ident)
{
    m_declMap.find(ident)->second.isInitialized = true;
}

void DeclMap::setVarIsReaded(const string & ident)
{
    m_declMap.find(ident)->second.varIsReaded = true;
}
