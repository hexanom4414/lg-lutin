#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "SymboleSimple.h"


class Constante : public SymboleSimple
{
    public:
        Constante() : Symbole(CONSTANTE) {}
        virtual ~Constante();
    protected:
    private:
};

#endif // CONSTANTE_H
