#ifndef LISTDECLARATION_H
#define LISTDECLARATION_H

#include "SymboleComplexe.h"
#include "Declaration.h"
#include <list>

class ListDeclaration : public SymboleComplexe
{
    public:
        ListDeclaration() : SymboleComplexe(LISTDECLARATION) {}
        virtual ~ListDeclaration();
    protected:
    	list<Declaration *> m_listDeclaration;
    private:
};

#endif // LISTDECLARATION_H
