#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>
#include <stack>
#include "AbstractEtat.h"
#include "Symboles/Symbole.h"

using namespace std;

class Automate
{
    public:
        Automate();
        Automate ( const Automate & unAutomate );
        virtual ~Automate();

        void lecture();

    protected:
        stack <AbstractEtat *> pileEtats;
        stack <Symbole *> pileSymboles;
    private:
};

#endif // AUTOMATE_H
