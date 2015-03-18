#include "test.h"
#include "src/Symboles/Affectation.h"
#include "src/Symboles/Constante.h"
#include "src/Symboles/Declaration.h"
#include "src/Symboles/Div.h"
#include "src/Symboles/Ecrire.h"
#include "src/Symboles/Ecriture.h"
#include "src/Symboles/Egal.h"
#include "src/Symboles/ExpComplexe.h"
#include "src/Symboles/Expression.h"
#include "src/Symboles/Identificateur.h"
#include "src/Symboles/Instruction.h"
#include "src/Symboles/Lecture.h"
#include "src/Symboles/Lire.h"
#include "src/Symboles/ListDeclaration.h"
#include "src/Symboles/ListIdentificateur.h"
#include "src/Symboles/ListInstruction.h"
#include "src/Symboles/Moins.h"
#include "src/Symboles/Mult.h"
#include "src/Symboles/OpA.h"
#include "src/Symboles/Operateur.h"
#include "src/Symboles/OpM.h"
#include "src/Symboles/ParFerme.h"
#include "src/Symboles/ParOuvre.h"
#include "src/Symboles/Plus.h"
#include "src/Symboles/PointVirgule.h"
#include "src/Symboles/Programme.h"
#include "src/Symboles/SymbAffectation.h"
#include "src/Symboles/SymboleComplexe.h"
#include "src/Symboles/Symbole.h"
#include "src/Symboles/SymboleSimple.h"
#include "src/Symboles/SymbVariable.h"
#include "src/Symboles/Valeur.h"
#include "src/Symboles/Variable.h"
#include "src/Symboles/Virgule.h"


// Show result


//const string ID_REGEX = "\\w+";
//const string VAL_REGEX =;

bool lexical_result (string s, bool b)
{
	if (b){
		cout << "Expression " +s+" correcte" << endl;
	}else{
		cout << "Expression "+s + " incorrecte" << endl ;
	}
	
	return b;
}

bool test_const(const string &s)
{
	const regex declaration("const");

	return lexical_result(s,regex_match(s,declaration));
}

bool test_var(const string &s)
{
	const regex declaration("var");

	return lexical_result(s,regex_match(s,declaration));
}

bool test_valeur(const string &s)
{
	const regex valeur("w+");

	return lexical_result(s,regex_match(s,valeur));
}


bool test_num(const string &s)
{
	const regex num("[-+]?[0-9]*\.?[0-9]+$");
	return lexical_result(s,regex_match(s,num));

}


bool test_aff_dyn(const string &s)
{
	const regex affectation(":=");
	return lexical_result(s,regex_match(s,affectation));

}

bool test_aff_stat(const string &s)
{
	const regex affectation("=");
	return lexical_result(s,regex_match(s,affectation));

}


bool test_point_virg(const string &s)
{
	const regex pVirg(";");
	return lexical_result(s,regex_match(s,pVirg));

}


bool test_virg(const string &s)
{
	const regex virg(",");
	return lexical_result(s,regex_match(s,virg));

}

bool test_parOuvr(const string &s)
{
	const regex parOuvr("(");
	return lexical_result(s,regex_match(s,parOuvr));

}
bool test_parFerm(const string &s)
{
	const regex parFerm(")");
	return lexical_result(s,regex_match(s,parFerm));

}

 // verify the validity of multiplication operator 


bool test_mult(const string &s)
{
	const regex opM("(\\*)");
	

	return lexical_result(s,regex_match(s,opM));

	
}
bool test_div(const string &s)
{
	const regex opM("(/)");
	

	return lexical_result(s,regex_match(s,opM));

	
}
 // verify the validity of addition operator 

bool test_plus(const string &s)
{
	const regex opA("+");
	

	return lexical_result(s,regex_match(s,opA));

	
}
bool test_moins(const string &s)
{
	const regex opA("-");
	

	return lexical_result(s,regex_match(s,opA));

	
}

bool test_ecrire(const string &s)
{
	const regex instruction("(ecrire)");
	

	return lexical_result(s,regex_match(s,instruction));

}
bool test_lire(const string &s)
{
	const regex instruction("(lire)");
	

	return lexical_result(s,regex_match(s,instruction));

}


Symbole * test_lexer (string text)
{
	Symbole * resultat;
	
	if (test_lire(text))
	{
		resultat = new Lire();

	}
	else if(test_ecrire(text))
	{
		resultat = new Ecrire(ECRIRE);


	}
	else if(test_const(text))
	{
		resultat = new Constante(CONSTANTE);

	}
	else if(test_var(text))
	{
		resultat = new SymbVariable(SYMBVARIABLE);

	}
	else if(test_valeur(text))
	{	
		resultat = new Identificateur(IDENTIFICATEUR);

	}
	else if(test_num(text))
	{
		
		
	}
	else if(test_aff_dyn(text))
	{		
		resultat = new SymbAffectation(SYMBAFFECTATION);
	
	}
	else if(test_aff_stat(text))
	{
		resultat = new Egal(EGAL);

	}
	else if(test_point_virg(text))
	{
		resultat = new PointVirgule(POINTVIRGULE);

	}
	else if(test_virg(text))
	{
		resultat = new Virgule(VIRGULE);

	}
	else if(test_plus(text))
	{
		resultat = new Plus(PLUS);

	}	
	else if(test_moins(text))
	{
		resultat = new Moins(MOINS);

	}
	else if(test_mult(text))
	{
		resultat = new Mult(MULT);

		
	}	
	else if(test_div(text))
	{
		resultat = new Div(DIV);

		
	}
	else if(test_parOuvr(text))
	{
		resultat = new ParOuvre(PAROUVRE);

		
	}
	else if(test_parFerm(text))
	{
		resultat = new ParFerme(PARFERME);

		
	} 
	else
	{
		
		cerr << "syntaxe incorrecte : " <<text << endl;

	}
	
	return resultat;
	
}


void test_lecture(char* filename)
{
	ifstream file(filename, ios::in);
	string line;
	string recognize;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			for(string::iterator it = line.begin(); it != line.end(); it++)
			{
				if(!(isspace(*it)))
				{
					recognize += (*it);
				}
				else
				{
					recognize += "\n";
				}
				if((*it) == ';')
				{
					recognize += "\n";
				}

			}
		}
		cout << recognize << endl;
		file.close();
	}
	else
	{
		cerr << "fichier erroné" << endl;
	}
}




