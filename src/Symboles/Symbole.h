#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "../utils.h"

class Symbole
{
    public:
        Symbole(int id) : ident(id) {};
        virtual ~Symbole() {};

        virtual void print() = 0;
        virtual void staticCheck() {};
        virtual void transformation() {};
        virtual void execute() {};
        virtual string getName() {return "";};
        virtual double getValue() {return -1;};
        virtual void setValue(double value) { };
        virtual void setName(const string & name) {};

        operator int() const { return ident; }

    protected:
    	int ident;
    private:
};

#endif // SYMBOLE
