#ifndef LIRE_H
#define LIRE_H

#include "SymboleSimple.h"


class Lire : public SymboleSimple
{
    public:
        Lire() : Symbole (LIRE) {}
        virtual ~Lire();
    protected:
    private:
};

#endif // LIRE_H
