#ifndef EXPCOMPLEXE_H
#define EXPCOMPLEXE_H

#include "Expression.h"
#include "Operateur.h"

class ExpComplexe : public Expression
{
    public:
        ExpComplexe(): Expression (EXPCOMPLEXE) {};
        virtual ~ExpComplexe();

        void setExpGauche(Expression * p_expGauche);
        void setExpDroite(Expression * p_expDroit);
        void setOperateur(Operateur * p_operateur);
        void print();
    protected:
    	Expression * m_expGauche;
    	Expression * m_expDroite;
    	Operateur * m_operateur;
    private:
};

#endif // EXPCOMPLEXE_H
