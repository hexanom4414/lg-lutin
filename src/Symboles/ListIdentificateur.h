#ifndef LISTIDENTIFICATEUR_H
#define LISTIDENTIFICATEUR_H

#include "SymboleComplexe.h"
#include "Identificateur.h"
#include <list>

class ListIdentificateur : public SymboleComplexe
{
    public:
        ListIdentificateur(): SymboleComplexe(LISTIDENTIFICATEUR) {}
		void print() {};
        virtual ~ListIdentificateur();
    protected:
    	list<Identificateur *> m_listIdentificateur;
    private:
};

#endif // LISTIDENTIFICATEUR_H
