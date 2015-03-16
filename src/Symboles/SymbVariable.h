#ifndef SYMBVARIABLE_H
#define SYMBVARIABLE_H

#include "SymboleSimple.h"


class SymbVariable : public SymboleSimple
{
    public:
        SymbVariable(int id) : SymboleSimple(id) {};
		void print() {};
        virtual ~SymbVariable();
    protected:
    private:
};

#endif // SYMBVARIABLE_H
