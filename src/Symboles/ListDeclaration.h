#ifndef LISTDECLARATION
#define LISTDECLARATION

#include "SymboleComplexe.h"
#include "Declaration.h"
#include <list>

class ListDeclaration : public SymboleComplexe
{
    public:
        ListDeclaration() : Symbole(LISTDECLARATION) {}
        virtual ~ListDeclaration();
    protected:
    	List<Declaration *> list;
    private:
};

#endif // LISTDECLARATION
