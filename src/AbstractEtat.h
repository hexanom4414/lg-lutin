#ifndef ABSTRACTETAT_H
#define ABSTRACTETAT_H

#include "utils.h"

#include "Symboles/Symbole.h"
#include "Symboles/Programme.h"
#include "Symboles/Ecriture.h"
#include "Symboles/Lecture.h"
#include "Symboles/Plus.h"
#include "Symboles/Moins.h"
#include "Symboles/Mult.h"
#include "Symboles/Div.h"
#include "Symboles/PointVirgule.h"
#include "Symboles/Variable.h"
#include "Symboles/Virgule.h"
#include "Symboles/Egal.h"
#include "Symboles/SymbConst.h"
#include "Symboles/Constante.h"
#include "Symboles/Affectation.h"


class Automate;

using namespace std;

class AbstractEtat
{
    public:
        AbstractEtat();
        AbstractEtat(const string & name) {m_name = name;};
        virtual ~AbstractEtat() {};

        void print() const {cout << m_name;};

        virtual transition_return transition(Automate & automate, Symbole * s) = 0;

    protected:
        string m_name;
    private:
};

#endif // ABSTRACTETAT_H
