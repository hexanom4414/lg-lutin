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
        Symbole * depilerSymbole();
        void shift(AbstractEtat * etat, Symbole * s);
        void reduce(unsigned int nbDepil, Symbole * s);

    protected:
        stack <AbstractEtat *> m_pileEtats;
        stack <Symbole *> m_pileSymboles;
    private:
};

#endif // AUTOMATE_H
