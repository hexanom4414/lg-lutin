#ifndef DIV_H
#define DIV_H

#include "OpM.h"


class Div : public OpM
{
    public:
        Div(int id) : OpM(id) {};
        virtual ~Div();

        void print();
    protected:
    private:
};

#endif // DIV_H
