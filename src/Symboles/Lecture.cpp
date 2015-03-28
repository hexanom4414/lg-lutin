#include "Lecture.h"

void Lecture::print()
{
    cout << "lire " << m_identificateur << " ;" << endl;
}

void Lecture::staticCheck()
{
    if(!DeclMap::Instance().checkIdent(m_identificateur))
    {
        print();
        cout << ">>>> err : " << m_identificateur << " declaration manquante" << endl;
    }
    else if (DeclMap::Instance().getIsConst(m_identificateur))
    {
        print();
        cout << ">>>> err : lecture sur constante" << endl;
    }
}
