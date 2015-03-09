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

bool test_opA(const string &s)
{
	const regex opA("(+|-)");
	lexical_result(s,regex_match(s,opA));

	return regex_match(s,opA);
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
	const regex affectation("\\v[:=]\\val|(?: var|const) \\v[=]\\val");
	const regex opA("(?: +|-)");
	const regex opM("(\\*|/)");
	const regex expression("(?: expression|\\v)(?: opM|opA)(?: expression|\\v)");
	const regex priority("(\expression)");
	


	test_opM("*");
	
	
	return 0;
}


