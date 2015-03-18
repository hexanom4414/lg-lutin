#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>
#include "src/Automate.h"
#include "test.h"

using namespace std;
using namespace boost;

bool affichage = false, analyse = false, execution = false, optimisation = false;
string m_file = "";

void help_message()
{
	cout << "lutin.exe file [args]" << endl;
	cout << "affichage : -p" << endl;
	cout << "analyse statique : -a" << endl;
	cout << "execution : -e" << endl;
	cout << "optimisation : -o" << endl;
}

int main(int argc, const char* argv[])
{
    cout << "Hello" << endl;

    // argc test
    //cout << "Nombre d'arguments : " << argc << endl;
	if(argc < 2)
	{
		//cout << "Arguments manquants" << endl;
		//help_message();
		return 0;
	}
	
    // argv treatment
    for (int x = 1; x < argc; ++x)
    {
		string arg(argv[x]); 
        if(arg.compare("-help") == 0) 
			help_message();	
        if(arg.compare("-p") == 0)
			affichage = true;
		else if(arg.compare("-a") == 0)
			analyse = true;
		else if(arg.compare("-e") == 0)
			execution = true;
        else if(arg.compare("-o") == 0)
			optimisation = true;
		else if(m_file.compare("") == 0)
			m_file.assign(arg);
		else
			cout << "Argument inconnu" << endl;
    }
	

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

	char* fichier_test = "lutin-test.txt";
	test_lecture(fichier_test);
	
	return 0;
}


