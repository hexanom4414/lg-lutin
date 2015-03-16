#ifndef ECRITURE_H
#define ECRITURE_H

#include "Instruction.h"
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture(int id) : Instruction(id) {}
        virtual ~Ecriture() {};

        void setExpression(Expression * p_expression);
        void print();
    protected:
    	Expression * m_expression;
    private:
};

#endif // ECRITURE_H
