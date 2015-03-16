#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Variable : public Expression
{
    public:
        Variable() : Expression(VARIABLE){}
		void print() {};
        virtual ~Variable();
    protected:
    private:
};

#endif // VARIABLE_H