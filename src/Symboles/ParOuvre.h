#ifndef PAROUVRE_H
#define PAROUVRE_H

#include "SymboleSimple.h"


class ParOuvre : public SymboleSimple
{
    public:
        ParOuvre(int id) : SymboleSimple(id) {};
		void print() {};
        virtual ~ParOuvre();
    protected:
    private:
};

#endif // PAROUVRE_H
