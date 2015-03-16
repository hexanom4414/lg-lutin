#ifndef ECRITURE
#define ECRITURE

#include <Instruction.h>
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture() : Symbole (ECRITURE) {}
        virtual ~Ecriture();

        bool do(&exp);
    protected:
    	Expression *exp;
    private:
};

#endif // ECRITURE