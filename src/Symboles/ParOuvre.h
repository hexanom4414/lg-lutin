#ifndef PAROUVRE_H
#define PAROUVRE_H

#include "SymboleSimple.h"


class ParOuvre : public SymboleSimple
{
    public:
        ParOuvre() : Symbole(PAROUVRE) {}
        virtual ~ParOuvre();
    protected:
    private:
};

#endif // PAROUVRE_H
