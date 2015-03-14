#ifndef SYMBOLESIMPLE_H
#define SYMBOLESIMPLE_H

#include "Symbole.h"


class SymboleSimple : public Symbole
{
    public:
        SymboleSimple(int id) : Symbole(id) {};
        virtual ~SymboleSimple() {};
    protected:
    private:
};

#endif // SYMBOLESIMPLE_H
