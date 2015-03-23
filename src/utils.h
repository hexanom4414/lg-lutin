#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

enum transition_return
{
    SHIFTED,
    REDUCED,
    ACCEPTED,
    ERROR
};

enum enumSymbole
{
    SYMBAFFECTATION,
    ECRIRE,
    LIRE,
    CONSTANTE,
    SYMBVARIABLE,
    POINTVIRGULE,
    VIRGULE,
    PAROUVRE,
    PARFERME,
    EGAL,
    IDENTIFICATEUR,
    OPERATEUR,
    OPA,
    OPM,
    PLUS,
    MOINS,
    DIV,
    MULT,
    LISTIDENTIFICATEUR,
    DECLARATION,
    INSTRUCTION,
    LECTURE,
    ECRITURE,
    AFFECTATION,
    LISTINSTRUCTION,
    PROGRAMME,
    LISTDECLARATION,
    EXPCOMPLEXE,
    VARIABLE,
    NOMBRE,
    DOLLAR,
    TERME,
    FACTEUR,
    EXPRESSION,
    VALEUR,
    LISTAFFECTATION,
    POINTEGAL
};

#endif // UTILS_H
