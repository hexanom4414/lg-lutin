#ifndef PROGRAMME
#define PROGRAMME

#include <SymboleComplexe.h>
#include "ListDeclaration.h"
#include "ListInstruction.h"

class Programme : public SymboleComplexe
{
    public:
        Programme();
        virtual ~Programme();
    protected:
    	ListDeclaration *LD;
    	ListInstruction *LIns;
    private:
};

#endif // PROGRAMME