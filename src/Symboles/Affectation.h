#ifndef AFFECTATION
#define AFFECTATION

#include <Instruction.h>
#include "Expression.h"
#include "Identificateur.h"

class Affectation : public Instruction
{
    public:
        Affectation() : Symbole(AFFECTATION) , id(aId) , expToAffect(aExp) {}
        virtual ~Affectation();

        bool do(); //méthode pour lier un id avec une expression dans une map

    protected:
    	Identificateur *id;
    	Expression *expToAffect;
    private:
};

#endif // AFFECTATION