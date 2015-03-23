#include "ListAffectation.h"

void ListAffectation::addToList(ListAffectation * p_listAffectation)
{
    while (!p_listAffectation->isEmpty())
    {
        addToList(p_listAffectation->getFront());
        p_listAffectation->popFront();
    }
    delete p_listAffectation;
}

void ListAffectation::addToList(Affectation * p_affectation)
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

Affectation * ListAffectation::getFront()
{
    return m_listAffectation.front();
}

void ListAffectation::print()
{
    for (list<Affectation *>::iterator it=m_listAffectation.begin(); it != m_listAffectation.end(); ++it)
        (*it)->print();
    /*
    m_virgule->print();
    m_identificateur->print();
    m_egal->print();
    m_valeur->print();
    */
}
