#ifndef ECRITURE_H
#define ECRITURE_H

#include "Instruction.h"
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture() : Instruction (ECRITURE) {}
        virtual ~Ecriture();

        bool do(&exp);
    protected:
    	Expression *exp;
    private:
};

#endif // ECRITURE_H