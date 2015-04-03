#ifndef SYMBOLESIMPLE_H
#define SYMBOLESIMPLE_H

#include "Symbole.h"


class SymboleSimple : public Symbole
{
    public:
        SymboleSimple(int id) : Symbole(id) {};
        void print() {};
        virtual string getName() {return "";};
        virtual void setName(const string & name) {};
        virtual double getValue() {return -1;};
        virtual ~SymboleSimple() {};
    protected:
    private:
};

#endif // SYMBOLESIMPLE_H
