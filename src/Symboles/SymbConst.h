#ifndef SYMBCONST_H
#define SYMBCONST_H

#include "SymboleSimple.h"

class SymbConst : public SymboleSimple
{
    public:
        SymbConst(int id) : SymboleSimple(id) {};
        virtual ~SymbConst() {};
    protected:
    private:
};

#endif // SYMBCONST_H
