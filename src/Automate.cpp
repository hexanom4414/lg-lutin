#include "Automate.h"

Automate::Automate(const string & p_file)
{
    // Initialize on state 1
    m_pileEtats.push(new Etat1("Etat 1"));
    m_lexer = new Lexer(p_file);
}

transition_return Automate::run()
{
    Symbole * t_symb;
    transition_return ret_val = REDUCED;
    while((t_symb = m_lexer->getSymbole()) != (Symbole *) -1)
    {
        ret_val = REDUCED;
        while(ret_val == REDUCED || ret_val == ACCEPTED || ret_val == RECUP_ERROR)
        {
            ret_val = m_pileEtats.top()->transition(*this, t_symb);

            if(ret_val == RECUP_ERROR)
            {
                cerr << ">>>> RECUP_ERROR <<<<" << endl;
            }
        }

        if(ret_val == ERROR)
        {
            cerr << ">>>> ERROR <<<<" << endl;
            cerr << "symbole : ";
            printSymbole((int) *t_symb);
            cerr << endl;
            cerr << "etat : ";
            m_pileEtats.top()->print();
            cerr << endl;
            break;
        }
    }
    if(ret_val == FINISH)
    {
        //cout << "Program Accepted !" << endl;
    }

    return ret_val;
}

Symbole * Automate::depilerSymbole(bool toDelete)
{
    Symbole * p_symbole = m_pileSymboles.top();
    if(toDelete)
        delete p_symbole;
    m_pileSymboles.pop();
    return p_symbole;
}

void Automate::empilerSymbole(Symbole * s)
{
    m_pileSymboles.push(s);
}

void Automate::shift(AbstractEtat * etat, Symbole * s)
{

    m_pileEtats.push(etat);
    m_pileSymboles.push(s);
    return;
}

void Automate::reduce(unsigned int nbDepil, Symbole * s)
{
    for(unsigned int i = 0 ; i < nbDepil ; i++)
    {
        delete m_pileEtats.top();
        m_pileEtats.pop();
    }

    m_pileEtats.top()->transition(* this, s);
    return;
}

void Automate::printProgram()
{
    cout << "Affichage du programme :" << endl;
    m_pileSymboles.top()->print();
    cout << endl;
}

void Automate::checkStatic()
{
    DeclMap::Instance().clearMap();
    cout << "Analyse statique du programme :" << endl;
    m_pileSymboles.top()->staticCheck();
    DeclMap::Instance().staticCheck();
    cout << endl;
    DeclMap::Instance().clearMap();
    cout << endl;
}

void Automate::transformation()
{
    cout << "Transformation du programme :" << endl;
    m_pileSymboles.top()->transformation();
    cout << endl;
    //printDeclMap();
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
    DeclMap::Instance().print();
}


void Automate::execute()
{
    DeclMap::Instance().clearMap();
    m_pileSymboles.top()->execute();
    // printDeclMap();
    DeclMap::Instance().clearMap();
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
