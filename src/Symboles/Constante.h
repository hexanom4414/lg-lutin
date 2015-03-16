#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "SymboleSimple.h"


class Constante : public SymboleSimple
{
    public:
        Constante(int id) : SymboleSimple(id) {}
        virtual ~Constante();
    protected:
    private:
};

#endif // CONSTANTE_H
