#ifndef SYMBOLESIMPLE_H
#define SYMBOLESIMPLE_H

#include "Symbole.h"


class SymboleSimple : public Symbole
{
    public:
        SymboleSimple(int id) : Symbole(id) {};
		void print() {};
        virtual ~SymboleSimple() {};
    protected:
    private:
};

#endif // SYMBOLESIMPLE_H
