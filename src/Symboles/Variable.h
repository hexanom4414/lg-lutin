#ifndef VARIABLE
#define VARIABLE

#include <Expression.h>

class Variable : public Expression
{
    public:
        Variable() : Symbole (VARIABLE){}
        virtual ~Variable();
    protected:
    private:
};

#endif // VARIABLE