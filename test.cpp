#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

bool test_declaration(const string &s)
{
	const regex declaration("(var|const) \\w+");
	return regex_match(s, declaration);
}

bool test_opA(const string &s)
{
	const regex opA("(?: +|-)");
	return regex_match
}

int main()
{
	const regex affectation("\\v[:=]\\val|(?: var|const) \\v[=]\\val");
	const regex opA("(?: +|-)");
	const regex opM("(?: *|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	

	cout << "test 1" << endl;
	
	string declare = "var lol";
	cout << test_declaration(declare) << endl;
	
	return 0;
}


