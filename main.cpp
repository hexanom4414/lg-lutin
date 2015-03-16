#include <iostream>
#include "src/Automate.h"
#include "test.h"
#include <fstream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

int main()
{/*
	const regex opA("(+|-)");
	const regex opM("(\\*|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	
	test_opM("*");
	
	cout << "test declaration" << endl;
	
	string affect = "var l";
	 test_declaration(affect) ;
	
	cout << "test affectation" << endl;
	
	 affect = "var hehe = c'est faux";
	test_affectation(affect);
	
		cout << "test instruction" << endl;
	
	 affect = "lire hehe";
	test_instruction(affect);
*/	
	char* fichier_test = "lutin-test.txt";
	test_lecture(fichier_test);
	
	return 0;
}


