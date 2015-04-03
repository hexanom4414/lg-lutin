#include "Lexer.h"

Lexer::Lexer(const string & p_file) : file(p_file.c_str(), ios_base::in)
{
    resultat = 0;
}

bool Lexer::symbolExist(const string &s)
{
    if (lexer_lire(s))
    {
        return true;
    }
    else if(lexer_ecrire(s))
    {
        return true;
    }
    else if(lexer_const(s))
    {
        return true;
    }
    else if(lexer_var(s))
    {
        return true;
    }
    else if(lexer_identificateur(s))
    {
        return true;
    }
    else if(lexer_num(s))
    {
        return true;
    }
    else if(lexer_aff_dyn(s))
    {
        return true;
    }
    else if(lexer_aff_stat(s))
    {
        return true;
    }
    else if(lexer_point_virg(s))
    {
        return true;
    }
    else if(lexer_virg(s))
    {
        return true;
    }
    else if(lexer_plus(s))
    {
        return true;
    }
    else if(lexer_moins(s))
    {
        return true;
    }
    else if(lexer_mult(s))
    {
        return true;
    }
    else if(lexer_div(s))
    {
        return true;
    }
    else if(lexer_parOuvr(s))
    {
        return true;
    }
    else if(lexer_parFerm(s))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Lexer::lexer_const(const string &s)
{
    const regex declaration("const");
    return regex_match(s,declaration);
}

bool Lexer::lexer_var(const string &s)
{
    const regex declaration("var");
    return regex_match(s,declaration);
}

bool Lexer::lexer_identificateur(const string &s)
{
    const regex valeur("[a-z]+[a-zA-Z0-9]*");
    return regex_match(s,valeur);
}


bool Lexer::lexer_num(const string &s)
{
    const regex num("[0-9]+\\.?[0-9]*");
    return regex_match(s,num);
}


bool Lexer::lexer_aff_dyn(const string &s)
{
    const regex affectation(":=");
    return regex_match(s,affectation);
}

bool Lexer::lexer_aff_stat(const string &s)
{
    const regex affectation("=");
    return regex_match(s,affectation);
}

bool Lexer::lexer_point_virg(const string &s)
{
    const regex pVirg(";");
    return regex_match(s,pVirg);
}

bool Lexer::lexer_virg(const string &s)
{
    const regex virg(",");
    return regex_match(s,virg);
}

bool Lexer::lexer_parOuvr(const string &s)
{
    const regex parOuvr("\\(");
    return regex_match(s,parOuvr);
}

bool Lexer::lexer_parFerm(const string &s)
{
    const regex parFerm("\\)");
    return regex_match(s,parFerm);
}

bool Lexer::lexer_mult(const string &s)
{
    const regex opM("(\\*)");
    return regex_match(s,opM);
}

bool Lexer::lexer_div(const string &s)
{
    const regex opM("(/)");
    return regex_match(s,opM);
}

bool Lexer::lexer_plus(const string &s)
{
    const regex opA("\\+");
    return regex_match(s,opA);
}

bool Lexer::lexer_moins(const string &s)
{
    const regex opA("-");
    return regex_match(s,opA);
}

bool Lexer::lexer_ecrire(const string &s)
{
    const regex instruction("(ecrire)");
    return regex_match(s,instruction);
}

bool Lexer::lexer_lire(const string &s)
{
    const regex instruction("(lire)");
    return regex_match(s,instruction);
}

// Retourne le symbole lu ou -1 si fin du fichier
Symbole * Lexer::getSymbole ()
{
    if(file.is_open())
    {
        string word = "";
        char c;

        file.get(c); // read one char
        if(file.gcount() == 0) // detect end of file
        {
            resultat = new Dollar(DOLLAR);
            file.close();
            return resultat;
        }
        while(c == ' ' || c == '\n' || c == '\t'||c=='\r') // skip space, tab, endline
        {
            file.get(c); // get while skip char
            if(file.gcount() == 0) // detect end of file
            {
                resultat = new Dollar(DOLLAR);
                file.close();
                return resultat;
            }
        }

        word += c; // add to string
        // while word is a symbole, try next char
        // check := (two-char symbole)
        // sometime get() return -1 on end of file.
        while((symbolExist(word) && (int) c != -1) || word.compare(":") == 0)
        {
            c = file.get();
            if((int) c != -1)
                word += c;
        }

        if ((int) c == -1)
        {
            file.close();
        }
        else
        {
            file.unget(); // unget the last char which is not part of the symbol
            word = word.substr(0, word.size()-1); // remove last char to get the good word
        }

        if(word.size() == 0) // if size == 0, the char is not authorized
        {
            cerr << "char non autorise : " << (int) file.get() << endl;

            return getSymbole();
        }
        else // get the symbol
        {
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
                resultat->setValue(atoi(word.c_str()));
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
            return resultat;
        }
    }
    else
    {
        if((int) * resultat != DOLLAR) // security check
        {
            resultat = new Dollar(DOLLAR);
            return resultat;
        }
        else
        {
            resultat = (Symbole *) -1; // automate stop reading
            return resultat;
        }
    }
}
