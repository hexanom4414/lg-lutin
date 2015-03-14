#ifndef ABSTRACTETAT_H
#define ABSTRACTETAT_H

#include "utils.h"
#include <iostream>
#include "Symboles/Symbole.h"

class Automate;

using namespace std;

class AbstractEtat
{
    public:
        AbstractEtat();
        AbstractEtat(string name);
        virtual ~AbstractEtat();

        void print() const;
        virtual transition_return transition(Automate & automate, Symbole * s) = 0;

    protected:
        string m_name;
    private:
};

#endif // ABSTRACTETAT_H
