#ifndef DOLLAR_H
#define DOLLAR_H

#include "SymboleSimple.h"

class Dollar : public SymboleSimple
{
    public:
        Dollar(int id) : SymboleSimple(id) {};
        virtual ~Dollar() {};
    protected:
    private:
};

#endif // DOLLAR_H
