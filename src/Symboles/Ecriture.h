#ifndef ECRITURE_H
#define ECRITURE_H

#include "Instruction.h"
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture(int id) : Instruction(id) {}
        virtual ~Ecriture() {};

        void setAttribute(Expression * p_expression) {m_expression = p_expression;};
        virtual void execute();
        void print();
        void staticCheck();
        void transformation();
    protected:
    	Expression * m_expression;
    private:
};

#endif // ECRITURE_H
