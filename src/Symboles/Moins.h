#ifndef MOINS_H
#define MOINS_H

#include "OpA.h"


class Moins : public OpA
{
    public:
        Moins(int id) : OpA(id) {};
		void print() {};
        virtual ~Moins();
    protected:
    private:
};

#endif // MOINS_H
