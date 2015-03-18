#ifndef LIRE_H
#define LIRE_H

#include "SymboleSimple.h"


class Lire : public SymboleSimple
{
    public:
        Lire() : SymboleSimple(LIRE) {};
        virtual ~Lire();
        void print();
    protected:
    private:
};

#endif // LIRE_H
