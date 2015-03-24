#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "utils.h"
#include "AbstractEtat.h"
#include <stack>
#include "ConcreteEtats.h"
#include "Symboles/Symbole.h"
#include "Symboles/Dollar.h"
#include "Lexer.h"
#include "DeclMap.h"

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
    void printSymbole(int symbole);
protected:
    stack <AbstractEtat *> m_pileEtats;
    stack <Symbole *> m_pileSymboles;
    Lexer * m_lexer;
    DeclMap * m_declMap;

    void printEtatStack();
    void printSymboleStack();
    void printDeclMap();
private:
};

#endif // AUTOMATE_H
