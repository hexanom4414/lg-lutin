#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>
#include <stack>
#include "AbstractEtat.h"
#include "ConcreteEtats.h"
#include "Symboles/Symbole.h"
#include "Lexer.h"

using namespace std;

class Automate
{
public:
    Automate(const string & p_file);
    virtual ~Automate() {};

    void run();
    Symbole * depilerSymbole(bool toDelete = false);
    void shift(AbstractEtat * etat, Symbole * s);
    void reduce(unsigned int nbDepil, Symbole * s);

protected:
    stack <AbstractEtat *> m_pileEtats;
    stack <Symbole *> m_pileSymboles;
    Lexer * m_lexer;

    void printEtatStack();
    void printSymboleStack();
private:
};

#endif // AUTOMATE_H
