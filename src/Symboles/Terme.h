#ifndef TERME_H
#define TERME_H

#include "SymboleSimple.h"


class Terme : public SymboleSimple
{
    public:
        Terme(int id);
		void print() {};
        virtual ~Terme();
    protected:
    private:
};

#endif // TERME_H
