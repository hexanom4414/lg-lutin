#ifndef IDENTIFICATEUR_H
#define IDENTIFICATEUR_H

#include "SymboleSimple.h"


class Identificateur : public SymboleSimple
{
    public:
        Identificateur() : Symbole (IDENTIFICATEUR) , name(aName) {}
        virtual ~Identificateur();
    protected:
    	String name ;
    private:
};

#endif // IDENTIFICATEUR_H
