#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "SymboleSimple.h"


class Operateur : public SymboleSimple
{
    public:
        Operateur(int id);
		void print() {};
        virtual ~Operateur()  {};
    protected:
    private:
};

#endif // OPERATEUR_H
