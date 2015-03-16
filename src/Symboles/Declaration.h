#ifndef DECLARATION_H
#define DECLARATION_H

#include "SymboleComplexe.h"
#include "ListIdentificateur.h"

class Declaration : public SymboleComplexe
{
    public:
        Declaration() : SymboleComplexe(DECLARATION){}
        virtual ~Declaration();
    protected:
    	list<ListIdentificateur *> m_listIdentificateur;
    private:
};

#endif // DECLARATION_H
