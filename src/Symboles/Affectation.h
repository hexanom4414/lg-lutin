#ifndef AFFECTATION
#define AFFECTATION

#include <Instruction.h>
#include "Expression.h"
#include "Identificateur.h"

class Affectation : public Instruction
{
    public:
        Affectation();
        virtual ~Affectation();

        bool do(&id, &expToAffect);

    protected:
    	Identificateur *id;
    	Expression *expToAffect;
    private:
};

#endif // AFFECTATION