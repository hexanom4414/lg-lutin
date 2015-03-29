#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>
#include "utils.h"
#include "Symboles/Symbole.h"
#include "Symboles/Affectation.h"
#include "Symboles/SymbConst.h"
#include "Symboles/Declaration.h"
#include "Symboles/Div.h"
#include "Symboles/Dollar.h"
#include "Symboles/Ecrire.h"
#include "Symboles/Ecriture.h"
#include "Symboles/Egal.h"
#include "Symboles/Expression.h"
#include "Symboles/Identificateur.h"
#include "Symboles/Instruction.h"
#include "Symboles/Lecture.h"
#include "Symboles/Lire.h"
#include "Symboles/ListDeclaration.h"
#include "Symboles/ListIdentificateur.h"
#include "Symboles/ListInstruction.h"
#include "Symboles/Moins.h"
#include "Symboles/Mult.h"
#include "Symboles/OpA.h"
#include "Symboles/Operateur.h"
#include "Symboles/OpM.h"
#include "Symboles/ParFerme.h"
#include "Symboles/ParOuvre.h"
#include "Symboles/Plus.h"
#include "Symboles/PointVirgule.h"
#include "Symboles/Programme.h"
#include "Symboles/SymbAffectation.h"
#include "Symboles/SymboleComplexe.h"
#include "Symboles/Symbole.h"
#include "Symboles/SymboleSimple.h"
#include "Symboles/SymbVariable.h"
#include "Symboles/Valeur.h"
#include "Symboles/Variable.h"
#include "Symboles/Virgule.h"

using namespace std;
using namespace boost;

class Lexer
{
public:
    Lexer(const string & p_file, bool skipErrChar);
    virtual ~Lexer() {};

    Symbole * getSymbole ();

protected:

private:
    ifstream file;
    bool m_skipErrChar;
    Symbole * resultat;

    bool symbolExist(const string &s);

    bool lexical_result(string s, bool b);
    bool lexer_const(const string &s);
    bool lexer_var(const string &s);
    bool lexer_identificateur(const string &s);
    bool lexer_num(const string &s);
    bool lexer_aff_dyn(const string &s);
    bool lexer_aff_stat(const string &s);
    bool lexer_point_virg(const string &s);
    bool lexer_virg(const string &s);
    bool lexer_parOuvr(const string &s);
    bool lexer_parFerm(const string &s);
    bool lexer_mult(const string &s);
    bool lexer_div(const string &s);
    bool lexer_plus(const string &s);
    bool lexer_moins(const string &s);
    bool lexer_ecrire(const string &s);
    bool lexer_lire(const string &s);

    bool lexer_declaration(const string &s);
    bool lexer_affectation(const string &s);
    bool lexer_opM(const string &s);
    bool lexer_opA(const string &s);
    bool lexer_instruction(const string &s);
};

#endif // LEXER_H
