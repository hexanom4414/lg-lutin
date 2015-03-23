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
bool lexer_declaration(const string &s);
bool lexer_affectation(const string &s);
bool lexer_opM(const string &s);
bool lexer_opA(const string &s);
bool lexer_instruction(const string &s);
void lexer_lecture(char* filename);
Symbole * lexer (string text);
#endif // LEXER_H
