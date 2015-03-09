#ifndef ECRITURE
#define ECRITURE

#include <Instruction.h>
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture();
        virtual ~Ecriture();
    protected:
    	Expression *exp;
    private:
};

#endif // ECRITURE