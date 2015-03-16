#ifndef AFFECTATION
#define AFFECTATION

#include "Instruction.h"
#include "Valeur.h"
#include "Identificateur.h"

class Affectation : public Instruction
{
    public:
        Affectation();
        virtual ~Affectation();
    protected:
    	Identificateur *id;
    	Valeur *valToAffect;
    private:
};

#endif // AFFECTATION
