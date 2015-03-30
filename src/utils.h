#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "DeclMap.h"

using namespace std;

enum transition_return
{
    SHIFTED,
    REDUCED,
    ACCEPTED,
    FINISH,
    ERROR,
    RECUP_ERROR
};

enum enumSymbole
{
    SYMBAFFECTATION, // 0
    ECRIRE, // 1
    LIRE, // 2
    CONSTANTE, // 3
    SYMBVARIABLE, // 4
    POINTVIRGULE, // 5
    VIRGULE, // 6
    PAROUVRE, // 7
    PARFERME, // 8
    EGAL, // 9
    IDENTIFICATEUR, // 10
    OPERATEUR, // 11
    OPA, // 12
    OPM, // 13
    PLUS, // 14
    MOINS, // 15
    DIV, // 16
    MULT, // 17
    LISTIDENTIFICATEUR, // 18
    DECLARATION, // 19
    INSTRUCTION, // 20
    LECTURE, // 21
    ECRITURE, // 22
    AFFECTATION, // 23
    LISTINSTRUCTION, // 24
    PROGRAMME, // 25
    LISTDECLARATION, // 26
    DONOTUSE_OLD, // 27
    VARIABLE, // 28
    DOLLAR, // 29
    TERME, // 30
    FACTEUR, // 31
    EXPRESSION, // 32
    VALEUR, // 33
    LISTAFFECTATION, // 34
    SYMBCONST //35
};

#endif // UTILS_H
