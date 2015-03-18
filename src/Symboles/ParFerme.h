#ifndef PARFERME_H
#define PARFERME_H

#include "SymboleSimple.h"


class ParFerme : public SymboleSimple
{
    public:
        ParFerme(int id) : SymboleSimple(id) {}
		void print() {};
        virtual ~ParFerme() {};
    protected:
    private:
};

#endif // PARFERME_H
