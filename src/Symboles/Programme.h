#ifndef PROGRAMME_H
#define PROGRAMME_H

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

#endif // PROGRAMME_H
