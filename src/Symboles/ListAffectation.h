#ifndef LISTAFFECTATION_H
#define LISTAFFECTATION_H

#include <list>

#include "SymboleComplexe.h"
#include "Affectation.h"
#include "Valeur.h"
#include "Egal.h"
#include "Identificateur.h"
#include "Virgule.h"

class ListAffectation : public SymboleComplexe
{
public:
    ListAffectation(int id) : SymboleComplexe(id) {};
    virtual ~ListAffectation() {};

    void addToList(ListAffectation * p_listAffectation);
    void addToList(Affectation * p_affectation);
    bool isEmpty();
    void popFront();
    Affectation * getFront();
    virtual void print();

    void setAttribute(Valeur * p_valeur) {m_valeur = p_valeur;};
    void setAttribute(Egal * p_egal) {m_egal = p_egal;};
    void setAttribute(Identificateur * p_identificateur) {m_identificateur = p_identificateur;};
    void setAttribute(Virgule * p_virgule) {m_virgule = p_virgule;};

protected:
    list<Affectation *> m_listAffectation;
    Valeur * m_valeur;
    Egal * m_egal;
    Identificateur * m_identificateur;
    Virgule * m_virgule;
private:
};

#endif // LISTAFFECTATION_H
