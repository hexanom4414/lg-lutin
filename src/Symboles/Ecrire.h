#ifndef ECRIRE_H
#define ECRIRE_H

#include "SymboleSimple.h"


class Ecrire : public SymboleSimple
{
    public:
        Ecrire(int id) : SymboleSimple(id) {};
        virtual ~Ecrire() {};
    protected:
    private:
};

#endif // ECRIRE_H
