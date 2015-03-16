#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "SymboleComplexe.h"


class Expression : public SymboleComplexe
{
    public:
        Expression(int id) : SymboleComplexe(id) {};
        virtual ~Expression() {};
    protected:
    private:
};

#endif // EXPRESSION
