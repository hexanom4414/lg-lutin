#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "../utils.h"

class Symbole
{
    public:
        Symbole(int id) : ident(id) {};
        virtual ~Symbole() {};

        virtual void print() = 0;

        operator int() const { return ident; }

    protected:
    	int ident;
    private:
};

#endif // SYMBOLE
