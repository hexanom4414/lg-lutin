#ifndef VARIABLE_H
#define VARIABLE_H

#include <Expression.h>

class Variable : public Expression
{
    public:
        Variable() : Expression(VARIABLE){}
        virtual ~Variable();
    protected:
    private:
};

#endif // VARIABLE_H