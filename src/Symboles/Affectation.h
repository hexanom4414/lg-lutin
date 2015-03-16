#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expression.h"
#include "Valeur.h"
#include "Identificateur.h"

class Affectation : public Instruction
{
    public:
        Affectation() : Instruction(AFFECTATION) , id(aId) , expToAffect(aExp) {}
        virtual ~Affectation();

        bool do(); //méthode pour lier un id avec une expression dans une map

    protected:
    	Identificateur *id;
    	Expression *expToAffect;
    private:
};

#endif // AFFECTATION_H
