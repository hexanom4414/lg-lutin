#include "Lexer.h"
#include "Symboles/Affectation.h"
#include "Symboles/Constante.h"
#include "Symboles/Declaration.h"
#include "Symboles/Div.h"
#include "Symboles/Ecrire.h"
#include "Symboles/Ecriture.h"
#include "Symboles/Egal.h"
#include "Symboles/ExpComplexe.h"
#include "Symboles/Expression.h"
#include "Symboles/Identificateur.h"
#include "Symboles/Instruction.h"
#include "Symboles/Lecture.h"
#include "Symboles/Lire.h"
#include "Symboles/ListDeclaration.h"
#include "Symboles/ListIdentificateur.h"
#include "Symboles/ListInstruction.h"
#include "Symboles/Moins.h"
#include "Symboles/Mult.h"
#include "Symboles/OpA.h"
#include "Symboles/Operateur.h"
#include "Symboles/OpM.h"
#include "Symboles/ParFerme.h"
#include "Symboles/ParOuvre.h"
#include "Symboles/Plus.h"
#include "Symboles/PointVirgule.h"
#include "Symboles/Programme.h"
#include "Symboles/SymbAffectation.h"
#include "Symboles/SymboleComplexe.h"
#include "Symboles/Symbole.h"
#include "Symboles/SymboleSimple.h"
#include "Symboles/SymbVariable.h"
#include "Symboles/Valeur.h"
#include "Symboles/Variable.h"
#include "Symboles/Virgule.h"


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

bool lexer_const(const string &s)
{
	const regex declaration("const");

	return lexical_result(s,regex_match(s,declaration));
}

bool lexer_var(const string &s)
{
	const regex declaration("var");

	return lexical_result(s,regex_match(s,declaration));
}

bool lexer_valeur(const string &s)
{
	const regex valeur("w+");

	return lexical_result(s,regex_match(s,valeur));
}


bool lexer_num(const string &s)
{
	const regex num("[-+]?[0-9]*\.?[0-9]+$");
	return lexical_result(s,regex_match(s,num));

}


bool lexer_aff_dyn(const string &s)
{
	const regex affectation(":=");
	return lexical_result(s,regex_match(s,affectation));

}

bool lexer_aff_stat(const string &s)
{
	const regex affectation("=");
	return lexical_result(s,regex_match(s,affectation));

}


bool lexer_point_virg(const string &s)
{
	const regex pVirg(";");
	return lexical_result(s,regex_match(s,pVirg));

}


bool lexer_virg(const string &s)
{
	const regex virg(",");
	return lexical_result(s,regex_match(s,virg));

}

bool lexer_parOuvr(const string &s)
{
	const regex parOuvr("(");
	return lexical_result(s,regex_match(s,parOuvr));

}
bool lexer_parFerm(const string &s)
{
	const regex parFerm(")");
	return lexical_result(s,regex_match(s,parFerm));

}

 // verify the validity of multiplication operator 


bool lexer_mult(const string &s)
{
	const regex opM("(\\*)");
	

	return lexical_result(s,regex_match(s,opM));

	
}
bool lexer_div(const string &s)
{
	const regex opM("(/)");
	

	return lexical_result(s,regex_match(s,opM));

	
}
 // verify the validity of addition operator 

bool lexer_plus(const string &s)
{
	const regex opA("+");
	

	return lexical_result(s,regex_match(s,opA));

	
}
bool lexer_moins(const string &s)
{
	const regex opA("-");
	

	return lexical_result(s,regex_match(s,opA));

	
}

bool lexer_ecrire(const string &s)
{
	const regex instruction("(ecrire)");
	

	return lexical_result(s,regex_match(s,instruction));

}
bool lexer_lire(const string &s)
{
	const regex instruction("(lire)");
	

	return lexical_result(s,regex_match(s,instruction));

}


Symbole * lexer (string text)
{
	Symbole * resultat;
	
	cout << text <<endl;
	
	if (lexer_lire(text))
	{
		resultat = new Lire();

	}
	else if(lexer_ecrire(text))
	{
		resultat = new Ecrire(ECRIRE);


	}
	else if(lexer_const(text))
	{
		resultat = new Constante(CONSTANTE);

	}
	else if(lexer_var(text))
	{
		resultat = new SymbVariable(SYMBVARIABLE);

	}
	else if(lexer_valeur(text))
	{	
		resultat = new Identificateur(IDENTIFICATEUR);

	}
	else if(lexer_num(text))
	{
		
		resultat = new Valeur(VALEUR);
	}
	else if(lexer_aff_dyn(text))
	{		
		resultat = new SymbAffectation(SYMBAFFECTATION);
	
	}
	else if(lexer_aff_stat(text))
	{
		resultat = new Egal(EGAL);

	}
	else if(lexer_point_virg(text))
	{
		resultat = new PointVirgule(POINTVIRGULE);

	}
	else if(lexer_virg(text))
	{
		resultat = new Virgule(VIRGULE);

	}
	else if(lexer_plus(text))
	{
		resultat = new Plus(PLUS);

	}	
	else if(lexer_moins(text))
	{
		resultat = new Moins(MOINS);

	}
	else if(lexer_mult(text))
	{
		resultat = new Mult(MULT);

		
	}	
	else if(lexer_div(text))
	{
		resultat = new Div(DIV);

		
	}
	else if(lexer_parOuvr(text))
	{
		resultat = new ParOuvre(PAROUVRE);

		
	}
	else if(lexer_parFerm(text))
	{
		resultat = new ParFerme(PARFERME);

		
	} 
	else
	{
		
		cerr << "syntaxe incorrecte : " <<text << endl;

	}
	
	return resultat;
	
}


void lexer_lecture(char* filename)
{
	ifstream file(filename, ios::in);
	string line;
	string recognize;
	string word ;
	int posDeb = 0;
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
					 
					word = recognize.substr(posDeb);
					lexer(word);
					recognize += "\n";
					posDeb = recognize.find_last_of("\n")+1;
				}
				if((*it) == ';')
				{
					recognize += "\n";
					posDeb = recognize.find_last_of("\n")+1;

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




