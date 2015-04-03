#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "SymboleComplexe.h"
#include "Terme.h"
#include "OpA.h"

class Expression : public SymboleComplexe
{
    public:
        Expression(int id) : SymboleComplexe(id) {};
        virtual ~Expression();
        void print();
        void staticCheck();
        bool isConst();
        Expression * elementNeutre();
        void setAttribute(Expression * p_expression) {m_expGauche = p_expression;};
        void setAttribute(OpA * p_opA) {m_operateur = p_opA;};
        void setAttribute(Terme * p_terme, bool isTerme) {m_expDroite = p_terme;m_isTerme = isTerme;};
        double eval();
    protected:
    private:
        Expression * m_expGauche;
        OpA * m_operateur;
        Terme * m_expDroite;
        bool m_isTerme;
};

#endif // EXPRESSION
