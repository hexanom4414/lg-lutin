#ifndef LISTAFFECTATION_H
#define LISTAFFECTATION_H

#include "SymboleComplexe.h"

class ListAffectation : public SymboleComplexe
{
    public:
        ListAffectation(int id) : SymboleComplexe(id) {};
        virtual ~ListAffectation() {};

        void print() {};

    protected:
    private:
};

#endif // LISTAFFECTATION_H
