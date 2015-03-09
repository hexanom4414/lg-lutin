#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

bool test_declaration(string s)
{
	const regex declaration("(?: var|const) \\v");
	return regex_match(s,declaration);
}

int main()
{
	const regex affectation("\\v[:=]\\val|(?: var|const) \\v[=]\\val");
	const regex opA("(?: +|-)");
	const regex opM("(?: *|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	

	
	string declare = "const y";
	cout << test_declaration(declare) << endl;
	
	return 0;
}


