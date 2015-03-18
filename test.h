#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

bool lexical_result (string s, bool b);
bool test_declaration(const string &s);
bool test_affectation(const string &s);
bool test_opM(const string &s);
bool test_opA(const string &s);
bool test_instruction(const string &s);
void test_lecture(char* filename);

#endif // TEST_H
