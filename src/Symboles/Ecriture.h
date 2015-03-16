#ifndef ECRITURE
#define ECRITURE

#include <Instruction.h>
#include "Expression.h"

class Ecriture : public Instruction
{
    public:
        Ecriture();
        virtual ~Ecriture();

        bool do(&exp);
    protected:
    	Expression *exp;
    private:
};

#endif // ECRITURE