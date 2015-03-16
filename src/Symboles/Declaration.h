#ifndef DECLARATION
#define DECLARATION

#include <SymboleComplexe.h>
#include "ListIdentificateur.h"

class Declaration : public SymboleComplexe
{
    public:
        Declaration() : Symbole(DECLARATION){}
        virtual ~Declaration();
    protected:
    	List<ListIdentificateur *> declaration;
    private:
};

#endif // DECLARATION