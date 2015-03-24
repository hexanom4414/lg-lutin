#ifndef TERME_H
#define TERME_H

#include "OpM.h"
#include "Facteur.h"
#include "SymboleComplexe.h"

class Terme : public SymboleComplexe
{
public:
    Terme(int id) : SymboleComplexe(id) {};
    virtual ~Terme() {};

    virtual void print();
    void setAttribute(Terme * p_terme) {m_expGauche = p_terme;};
    void setAttribute(OpM * p_opM) {m_operateur = p_opM;};
    void setAttribute(Facteur * p_facteur) {m_expDroite = p_facteur;};
protected:
    Terme * m_expGauche;
    OpM * m_operateur;
    Facteur * m_expDroite;
private:
};

#endif // TERME_H
