#include "Lexer.h"

// Show result


//const string ID_REGEX = "\\w+";
//const string VAL_REGEX =;

Lexer::Lexer(const string & p_file) : file(p_file.c_str(), ios_base::in)
{
    cout << "Lexer created" << endl;
    resultat = 0;
}

bool Lexer::lexical_result (string s, bool b)
{
    //if (b){
    ////cout << "Expression " +s+" correcte" << endl;
    //}else{
    ////cout << "Expression "+s + " incorrecte" << endl ;
    //}

    return b;
}

bool Lexer::lexer_const(const string &s)
{
    const regex declaration("const");
    return lexical_result(s,regex_match(s,declaration));
}

bool Lexer::lexer_var(const string &s)
{
    const regex declaration("var");
    return lexical_result(s,regex_match(s,declaration));
}

bool Lexer::lexer_identificateur(const string &s)
{
    const regex valeur("[a-z]+[a-zA-Z0-9]*");
    return lexical_result(s,regex_match(s,valeur));
}


bool Lexer::lexer_num(const string &s)
{
    const regex num("-?[0-9]*\\.?[0-9]*");
    return lexical_result(s,regex_match(s,num));
}


bool Lexer::lexer_aff_dyn(const string &s)
{
    const regex affectation(":=");
    return lexical_result(s,regex_match(s,affectation));
}

bool Lexer::lexer_aff_stat(const string &s)
{
    const regex affectation("=");
    return lexical_result(s,regex_match(s,affectation));
}

bool Lexer::lexer_point_virg(const string &s)
{
    const regex pVirg(";");
    return lexical_result(s,regex_match(s,pVirg));
}

bool Lexer::lexer_virg(const string &s)
{
    const regex virg(",");
    return lexical_result(s,regex_match(s,virg));
}

bool Lexer::lexer_parOuvr(const string &s)
{
    const regex parOuvr("(");
    return lexical_result(s,regex_match(s,parOuvr));
}

bool Lexer::lexer_parFerm(const string &s)
{
    const regex parFerm(")");
    return lexical_result(s,regex_match(s,parFerm));
}

// verify the validity of multiplication operator
bool Lexer::lexer_mult(const string &s)
{
    const regex opM("(\\*)");
    return lexical_result(s,regex_match(s,opM));
}

bool Lexer::lexer_div(const string &s)
{
    const regex opM("(/)");
    return lexical_result(s,regex_match(s,opM));
}

// verify the validity of addition operator
bool Lexer::lexer_plus(const string &s)
{
    const regex opA("\\+");
    return lexical_result(s,regex_match(s,opA));
}

bool Lexer::lexer_moins(const string &s)
{
    const regex opA("-");
    return lexical_result(s,regex_match(s,opA));
}

bool Lexer::lexer_ecrire(const string &s)
{
    const regex instruction("(ecrire)");
    return lexical_result(s,regex_match(s,instruction));
}

bool Lexer::lexer_lire(const string &s)
{
    const regex instruction("(lire)");
    return lexical_result(s,regex_match(s,instruction));
}

Symbole * Lexer::getSymbole ()
{
    if(file.is_open())
    {
        if (file.eof())
        {
            cout << "........................." << endl;
            cout << "LU : EoF" << endl;
            resultat = new Dollar(DOLLAR);
            file.close();
            return resultat;
        }

        if(resultat != 0)
        {
            if((int) * resultat == POINTVIRGULE)
            {
                resultat = new Dollar(DOLLAR);
                cout << "........................." << endl;
                cout << "LU : "<< "$" << endl;
                return resultat;
            }
        }

        string word;
        if(file >> word)
        {
            cout << "........................." << endl;
            cout << "LU : "<< word << endl;

            if (lexer_lire(word))
            {
                resultat = new Lire(LIRE);
            }
            else if(lexer_ecrire(word))
            {
                resultat = new Ecrire(ECRIRE);
            }
            else if(lexer_const(word))
            {
                resultat = new SymbConst(SYMBCONST);
            }
            else if(lexer_var(word))
            {
                resultat = new SymbVariable(SYMBVARIABLE);
            }
            else if(lexer_identificateur(word))
            {
                resultat = new Identificateur(IDENTIFICATEUR);
                resultat->setName(word);
            }
            else if(lexer_num(word))
            {
                resultat = new Valeur(VALEUR);
            }
            else if(lexer_aff_dyn(word))
            {
                resultat = new SymbAffectation(SYMBAFFECTATION);
            }
            else if(lexer_aff_stat(word))
            {
                resultat = new Egal(EGAL);
            }
            else if(lexer_point_virg(word))
            {
                resultat = new PointVirgule(POINTVIRGULE);
            }
            else if(lexer_virg(word))
            {
                resultat = new Virgule(VIRGULE);
            }
            else if(lexer_plus(word))
            {
                resultat = new Plus(PLUS);
            }
            else if(lexer_moins(word))
            {
                resultat = new Moins(MOINS);
            }
            else if(lexer_mult(word))
            {
                resultat = new Mult(MULT);
            }
            else if(lexer_div(word))
            {
                resultat = new Div(DIV);
            }
            else if(lexer_parOuvr(word))
            {
                resultat = new ParOuvre(PAROUVRE);
            }
            else if(lexer_parFerm(word))
            {
                resultat = new ParFerme(PARFERME);
            }
            else
            {
                cerr << "syntaxe incorrecte : " << word << endl;
            }
        }
        return resultat;
    }
    else
    {
        resultat = (Symbole *) -1;
        return resultat;
    }
}
