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

    void print();
    void staticCheck();
    bool isConst();
    double eval();
    void setAttribute(Terme * p_terme) {m_expGauche = p_terme;};
    void setAttribute(OpM * p_opM) {m_operateur = p_opM;};
    void setAttribute(Facteur * p_facteur, bool isFacteur) {m_expDroite = p_facteur;m_isFacteur = isFacteur;};
    void setFacteurVal(double val);
    void setFacteurExp(Expression * p_exp);
    void elementNeutre();
protected:
    Terme * m_expGauche;
    OpM * m_operateur;
    Facteur * m_expDroite;
    bool m_isFacteur;
private:
};

#endif // TERME_H
