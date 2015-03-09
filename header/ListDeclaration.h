#ifndef LISTDECLARATION
#define LISTDECLARATION

#include <SymboleComplexe.h>
#include "Declaration.h"
#include <list>

class ListDeclaration : public SymboleComplexe
{
    public:
        ListDeclaration();
        virtual ~ListDeclaration();
    protected:
    	List<Declaration *> List;
    private:
};

#endif // LISTDECLARATION