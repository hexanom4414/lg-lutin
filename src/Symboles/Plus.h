#ifndef PLUS_H
#define PLUS_H

#include "OpA.h"


class Plus : public OpA
{
    public:
        Plus(int id) : OpA(id) {}
        virtual ~Plus();
    protected:
    private:
};

#endif // PLUS_H
