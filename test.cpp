#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

// Show result


const string ID_REGEX = "\\w+";
const string VAL_REGEX =;

bool lexical_result (string s, bool b)
{
	if (b){
		cout << "Expression " +s+" correcte" << endl;
	}else{
		cout << "Expression "+s + " incorrecte" << endl ;
	}
	
	return b;
}

bool test_declaration(const string &s)
{
	const regex declaration("(var|const) \\w+");

	return lexical_result(s,regex_match(s,declaration));
;
}

bool test_affectation(const string &s)
{
	const regex affectation("(var|const) \\w+ = [-+]?[0-9]*\.?[0-9]+$");
	return lexical_result(s,regex_match(s,affectation));

}

 // verify the validity of multiplication operator 

bool test_opM(const string &s)
{
	const regex opM("(\\*|/)");
	

	return lexical_result(s,regex_match(s,opM));

	
}
 // verify the validity of addition operator 

bool test_opA(const string &s)
{
	const regex opA("(+|-)");
	

	return lexical_result(s,regex_match(s,opA));

	
}

bool test_instruction(const string &s)
{
	const regex instruction("(lire|ecrire) \\w+");
	

	return lexical_result(s,regex_match(s,instruction));

}







int main()
{
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
	
	return 0;
}


