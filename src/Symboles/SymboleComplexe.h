#ifndef SYMBOLECOMPLEXE_H
#define SYMBOLECOMPLEXE_H

#include "Symbole.h"

class SymboleComplexe : public Symbole
{
    public:
        SymboleComplexe(int id) : Symbole(id) {} ;
		void print() = 0;
        virtual ~SymboleComplexe() {};
    protected:
    private:
};

#endif // SYMBOLECOMPLEXE_H
