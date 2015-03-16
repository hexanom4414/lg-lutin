#ifndef ECRIRE_H
#define ECRIRE_H

#include "SymboleSimple.h"


class Ecrire : public SymboleSimple
{
    public:
        Ecrire() : Symbole(ECRIRE) {}
        virtual ~Ecrire();
    protected:
    private:
};

#endif // ECRIRE_H
