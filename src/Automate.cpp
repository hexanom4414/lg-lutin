#include "Automate.h"

Automate::Automate()
{
    cout << "Automate created" << endl;
    

/*
    lire fichier
    {
		Symbole * s = lexer.getNextSymbole()
		m_pileEtats.top()->transition(s)
	}
*/

    
}

Automate::~Automate()
{
    //dtor
}

symbole * Automate::depilerSymbole()
{
	Symbole * p_symbole = m_pileSymboles.top();
	m_pileSymboles.pop();
	return p_symbole;
}

void Automate::shift(AbstractEtat * etat, Symbole * s)
{
    m_pileEtats.push(etat);
    m_pileSymboles.push(s);
}

void Automate::reduce(unsigned int nbDepil, Symbole * s)
{
	for(unsigned int i = 0 ; i < nbDepil ; i++)
	{
		delete m_pileEtats.top();
		m_pileEtats.pop();
	}
	
	m_pileEtats.top()->transition(* this, s);	
}
