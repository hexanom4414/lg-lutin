#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "../utils.h"

class Symbole
{
    public:
        Symbole(int id) : ident(id) {};
        virtual ~Symbole() {};

        virtual void print() = 0;
        virtual string getName() {return "";};
        virtual int getValue() {return -1;};
        virtual void setValue(int value) { };
        virtual void setName(const string & name) {};

        operator int() const { return ident; }

    protected:
    	int ident;
    private:
};

#endif // SYMBOLE
