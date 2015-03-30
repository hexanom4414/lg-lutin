#include "Lecture.h"

void Lecture::print()
{
    cout << "lire " << m_identificateur << " ;" << endl;
}

void Lecture::staticCheck()
{
    if(!DeclMap::Instance().checkIdent(m_identificateur))
    {
        cout << ">>>> err : " << m_identificateur << " declaration manquante" << endl;
    }
    else if (DeclMap::Instance().getIsConst(m_identificateur))
    {
        cout << ">>>> err : lecture sur constante" << endl;
    }
    else
    {
        DeclMap::Instance().setInitialized(m_identificateur);
    }
}

void Lecture::transformation()
{
    DeclMap::Instance().setVarIsReaded(m_identificateur);
}
