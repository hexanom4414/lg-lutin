#ifndef IDENTIFICATEUR_H
#define IDENTIFICATEUR_H

#include "SymboleSimple.h"


class Identificateur : public SymboleSimple
{
    public:
        Identificateur(int id);
        virtual ~Identificateur();
    protected:
    private:
};

#endif // IDENTIFICATEUR_H
