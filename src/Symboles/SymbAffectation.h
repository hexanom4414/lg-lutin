#ifndef SYMBAFFECTATION_H
#define SYMBAFFECTATION_H

#include "SymboleSimple.h"


class SymbAffectation : public SymboleSimple
{
    public:
        SymbAffectation() : Symbole(SymbAffectation) {}
        virtual ~SymbAffectation();
    protected:
    private:
};

#endif // SYMBAFFECTATION_H
