#ifndef UTILS_H
#define UTILS_H

#define SYMBAFFECTATION 0
#define ECRIRE 1
#define LIRE 2
#define CONSTANTE 3
#define SYMBVARIABLE 4
#define POINTVIRGULE 5
#define VIRGULE 6
#define PAROUVRE 7
#define PARFERME 8
#define EGAL 9
#define IDENTIFICATEUR 10
#define OPERATEUR 11
#define OPA 12
#define OPM 13
#define PLUS 14
#define MOINS 15
#define DIV 16
#define MULT 17
#define LISTIDENTIFICATEUR 18
#define DECLARATION 19
#define INSTRUCTION 20
#define LECTURE 21 //
#define ECRITURE 22 //
#define AFFECTATION 23
#define LISTINSTRUCTION 24
#define PROGRAMME 25
#define LISTDECLARATION 26
#define EXPCOMPLEXE 28 //
#define VARIABLE 29
#define NOMBRE 30 //
#define DOLLAR 31
#define TERME 32 //TODO
#define FACTEUR 33 //TODO

enum transition_return
{
    SHIFTED,
    REDUCED,
    ACCEPTED,
    ERROR
};


#endif // UTILS_H
