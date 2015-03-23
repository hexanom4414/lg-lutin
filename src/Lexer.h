#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>
#include "utils.h"
#include "Symboles/Symbole.h"
using namespace std;
using namespace boost;

bool lexical_result (string s, bool b);
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
void lexer_lecture(char* filename);
Symbole * lexer (string text);
#endif // LEXER_H
