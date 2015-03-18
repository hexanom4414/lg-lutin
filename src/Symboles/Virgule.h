#ifndef VIRGULE_H
#define VIRGULE_H

#include "SymboleSimple.h"


class Virgule : public SymboleSimple
{
    public:
        Virgule(int id) : SymboleSimple(id) {};
		void print() {};
        virtual ~Virgule() {};
    protected:
    private:
};

#endif // VIRGULE_H
