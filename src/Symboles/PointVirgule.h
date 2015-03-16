#ifndef POINTVIRGULE_H
#define POINTVIRGULE_H

#include "SymboleSimple.h"

class PointVirgule : public SymboleSimple
{
    public:
        PointVirgule(int id) : SymboleSimple(id) {};
		void print() {};
        virtual ~PointVirgule();
    protected:
    private:
};

#endif // POINTVIRGULE_H
