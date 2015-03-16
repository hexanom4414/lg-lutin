#ifndef ECRIRE_H
#define ECRIRE_H

#include "SymboleSimple.h"


class Ecrire : public SymboleSimple
{
    public:
        Ecrire(int id) : SymboleSimple(id) {};
        virtual ~Ecrire();

        void print();
    protected:
    private:
};

#endif // ECRIRE_H
