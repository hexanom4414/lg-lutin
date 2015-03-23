#ifndef DECLARATION_H
#define DECLARATION_H

#include "SymboleComplexe.h"
#include "ListIdentificateur.h"
#include "PointVirgule.h"
#include "Variable.h"
#include "ListAffectation.h"
#include "Constante.h"

class Declaration : public SymboleComplexe
{
public:
    Declaration(int id) : SymboleComplexe(id) {}
    virtual ~Declaration() {};

    void print() {};
    void setAttribute(PointVirgule * p_pointVirgule) {m_pointVirgule = p_pointVirgule;};
    void setAttribute(ListIdentificateur * p_listIdentificateur) {m_listIdentificateur = p_listIdentificateur;};
    void setAttribute(Variable * p_variable) {m_variable = p_variable;};

    void setAttribute(ListAffectation * p_listAffectation) {m_listAffectation = p_listAffectation;};
    void setAttribute(Constante * p_constante) {m_constante = p_constante;};

protected:
    PointVirgule * m_pointVirgule;
    ListIdentificateur * m_listIdentificateur;
    ListAffectation * m_listAffectation;
    Variable * m_variable;
    Constante * m_constante;
private:
};

#endif // DECLARATION_H
