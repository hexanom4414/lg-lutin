#include "Automate.h"

Automate::Automate(const string & p_file)
{
    m_pileEtats.push(new Etat1("Etat 1"));
    cout << "Automate created & initialized" << endl;

    m_lexer = new Lexer(p_file);
}

void Automate::run()
{
    cout << endl << "////////////////// Run //////////////////"  << endl;
    Symbole * t_symb;
    while((int)(t_symb = m_lexer->getSymbole()) != -1)
    {
        transition_return ret_val = REDUCED;
        while(ret_val == REDUCED)
        {
            ret_val = m_pileEtats.top()->transition(*this, t_symb);
        }
    }
    cout << "//////////////// End Run ////////////////" << endl << endl;
    printEtatStack();
    cout << endl << endl;
    printSymboleStack();
}


Symbole * Automate::depilerSymbole(bool toDelete)
{
    Symbole * p_symbole = m_pileSymboles.top();
    if(toDelete)
        delete p_symbole;
    m_pileSymboles.pop();
    return p_symbole;
}

void Automate::shift(AbstractEtat * etat, Symbole * s)
{
    cout << "Decalage vers l'";
    etat->print();
    cout << " par le symbole : " << (int) *s << endl;

    m_pileEtats.push(etat);
    m_pileSymboles.push(s);
    return;
}

void Automate::reduce(unsigned int nbDepil, Symbole * s)
{
    cout << "Reduction de " << nbDepil << " symboles par le symbole : " << (int) *s << endl;
    for(unsigned int i = 0 ; i < nbDepil ; i++)
    {
        delete m_pileEtats.top();
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
        cout << (int) *m_pileSymboles.top() << endl;
        m_pileSymboles.pop();
    }
}
