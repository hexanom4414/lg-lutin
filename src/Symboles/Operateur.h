#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "SymboleComplexe.h"


class Operateur : public SymboleComplexe
{
    public:
        Operateur(int id) : SymboleComplexe(id) {};
		void print() = 0;
        virtual ~Operateur() {};
    protected:
    private:
};

#endif // OPERATEUR_H
