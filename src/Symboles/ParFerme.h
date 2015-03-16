#ifndef PARFERME_H
#define PARFERME_H

#include "SymboleSimple.h"


class ParFerme : public SymboleSimple
{
    public:
        ParFerme() : Symbole(PARFERME) {}
        virtual ~ParFerme();
    protected:
    private:
};

#endif // PARFERME_H
