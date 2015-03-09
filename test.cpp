#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

// Show result
void lexical_result (string s, bool b)
{
	if (b){
		cout << "Expression " +s+" correcte" << endl;
	}else{
		cout << "Expression "+s + " incorrecte" << endl ;
	}
}

bool test_declaration(const string &s)
{
	const regex declaration("(var|const) \\w+");
	lexical_result(s,regex_match(s,declaration));

	return regex_match(s, declaration);
}

bool test_affectation(const string &s)
{
	const regex affectation("(var|const) \\w+ = [-+]?[0-9]*\.?[0-9]+$");
	return regex_match(s,affectation);
}

 // verify the validity of multiplication operator 

bool test_opM(const string &s)
{
	const regex opM("(\\*|/)");
	
	 lexical_result(s,regex_match(s,opM));

	return regex_match(s,opM);
}







int main()
{
	const regex opA("(?: +|-)");
	const regex opM("(\\*|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	


	test_opM("*");
	
	cout << "test declaration" << endl;
	
	string declare = "var l";
	cout << test_declaration(declare) << endl;
	
	
	cout << "test affectation" << endl;
	
	string affect = "var hehe = c'est faux";
	cout << test_affectation(affect) << endl;
	
	return 0;
}


