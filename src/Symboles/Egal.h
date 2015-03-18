#ifndef EGAL_H
#define EGAL_H

#include "SymboleSimple.h"


class Egal : public SymboleSimple
{
    public:
        Egal(int id) : SymboleSimple(id) {};
		void print() {};
        virtual ~Egal() {};
    protected:
    private:
};

#endif // EGAL_H
