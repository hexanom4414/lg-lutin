#ifndef SYMBOLE_H
#define SYMBOLE_H


#include "../utils.h"

class Symbole
{
    public:
        Symbole(int id) : ident(id) { }
        virtual ~Symbole() { }

        void print();

        operator int() const { return ident; }

    protected:
    	int ident;
    private:
};

#endif // SYMBOLE
