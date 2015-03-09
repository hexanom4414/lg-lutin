#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

bool test_declaration(const string &s)
{
	const regex declaration("(var|const) \\w+");
	return regex_match(s,declaration);
}

bool test_affectation(const string &s)
{
	const regex affectation("(var|const) \\w+ = [-+]?[0-9]*\.?[0-9]+$");
	return regex_match(s,affectation);
}

int main()
{
	const regex opA("(?: +|-)");
	const regex opM("(?: *|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	

	cout << "test declaration" << endl;
	
	string declare = "var l";
	cout << test_declaration(declare) << endl;
	
	
	cout << "test affectation" << endl;
	
	string affect = "var hehe = c'est faux";
	cout << test_affectation(affect) << endl;
	
	return 0;
}


