#ifndef FACTEUR_H
#define FACTEUR_H

#include "SymboleSimple.h"


class Facteur : public SymboleSimple
{
    public:
        Facteur(int id) : SymboleSimple(id) {};
        virtual ~Facteur();
    protected:
    private:
};

#endif // FACTEUR_H
