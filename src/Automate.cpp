#include "Automate.h"

Automate::Automate(const string & p_file)
{
    m_pileEtats.push(new Etat1("Etat 1"));
    cout << "Automate created & initialized" << endl;

    m_lexer = new Lexer(p_file);
    global_declMap = new DeclMap();
}

void Automate::run()
{
    cout << endl << "////////////////// Run //////////////////"  << endl;
    Symbole * t_symb;
    transition_return ret_val = REDUCED;
    while((int)*(t_symb = m_lexer->getSymbole()) != -1)
    {
        cout << "RECU : ";
        printSymbole((int) * t_symb);
        cout << endl << endl;

        ret_val = REDUCED;
        while(ret_val == REDUCED || ret_val == ACCEPTED)
        {
            ret_val = m_pileEtats.top()->transition(*this, t_symb);
        }
    }
    if(ret_val == FINISH)
    {
        cout << "Program Accepted !" << endl;
    }

    cout << "//////////////// End Run ////////////////" << endl << endl;
    cout << "Affichage du programme :" << endl;
    m_pileSymboles.top()->print();
    cout << endl << endl;
    printEtatStack();
    cout << endl << endl;
    printSymboleStack();
    cout << endl << endl;
    printDeclMap();
}


Symbole * Automate::depilerSymbole(bool toDelete)
{
    Symbole * p_symbole = m_pileSymboles.top();
    //if(toDelete)
    //delete p_symbole;
    m_pileSymboles.pop();
    return p_symbole;
}

void Automate::shift(AbstractEtat * etat, Symbole * s)
{
    cout << "Decalage vers l'";
    etat->print();
    cout << " par le symbole : ";
    printSymbole((int) *s);
    cout << endl;

    m_pileEtats.push(etat);
    m_pileSymboles.push(s);
    return;
}

void Automate::reduce(unsigned int nbDepil, Symbole * s)
{
    cout << "Reduction de " << nbDepil << " symboles par le symbole : ";
    printSymbole((int) *s);
    cout << endl;

    for(unsigned int i = 0 ; i < nbDepil ; i++)
    {
//        delete m_pileEtats.top();
        m_pileEtats.pop();
    }

    m_pileEtats.top()->transition(* this, s);
    return;
}

void Automate::printEtatStack()
{
    cout << "Pile d'etats :" << endl;
    while(!m_pileEtats.empty())
    {
        m_pileEtats.top()->print();
        cout << endl;
        m_pileEtats.pop();
    }
}

void Automate::printSymboleStack()
{
    cout << "Pile de symboles :" << endl;
    while(!m_pileSymboles.empty())
    {
        printSymbole((int) *m_pileSymboles.top());
        cout << endl;
        m_pileSymboles.pop();
    }
}

void Automate::printDeclMap()
{
    cout << "Map des variables :" << endl;
    global_declMap->print();
}

void Automate::printSymbole(int symbole)
{
    switch(symbole)
    {
        case SYMBAFFECTATION :
            cout << "symbaffectation";
            break;
        case ECRIRE :
            cout << "ecrire";
            break;
        case LIRE :
            cout << "lire";
            break;
        case CONSTANTE :
            cout << "constante";
            break;
        case SYMBVARIABLE :
            cout << "symbvariable";
            break;
        case POINTVIRGULE :
            cout << "pointvirgule";
            break;
        case VIRGULE :
            cout << "virgule";
            break;
        case PAROUVRE :
            cout << "parouvre";
            break;
        case PARFERME :
            cout << "parferme";
            break;
        case EGAL :
            cout << "egal";
            break;
        case IDENTIFICATEUR :
            cout << "identificateur";
            break;
        case OPERATEUR :
            cout << "operateur";
            break;
        case OPA :
            cout << "opa";
            break;
        case OPM :
            cout << "opm";
            break;
        case PLUS :
            cout << "plus";
            break;
        case MOINS :
            cout << "moins";
            break;
        case DIV :
            cout << "div";
            break;
        case MULT :
            cout << "mult";
            break;
        case LISTIDENTIFICATEUR :
            cout << "listidentificateur";
            break;
        case DECLARATION :
            cout << "declaration";
            break;
        case INSTRUCTION :
            cout << "instruction";
            break;
        case LECTURE :
            cout << "lecture";
            break;
        case ECRITURE :
            cout << "ecriture";
            break;
        case AFFECTATION :
            cout << "affectation";
            break;
        case LISTINSTRUCTION :
            cout << "listinstruction";
            break;
        case PROGRAMME :
            cout << "programme";
            break;
        case LISTDECLARATION :
            cout << "listdeclaration";
            break;
        case VARIABLE :
            cout << "variable";
            break;
        case DOLLAR :
            cout << "dollar";
            break;
        case TERME :
            cout << "terme";
            break;
        case FACTEUR :
            cout << "facteur";
            break;
        case EXPRESSION :
            cout << "expression";
            break;
        case VALEUR :
            cout << "valeur";
            break;
        case LISTAFFECTATION :
            cout << "listaffectation";
            break;
        case SYMBCONST :
            cout << "symbconst";
            break;
        default:
            cout << symbole;
    }
}
