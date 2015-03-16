#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "SymboleComplexe.h"

class Programme : public SymboleComplexe
{
    public:
        Programme();
        virtual ~Programme();
        
        setListDeclaration(ListDeclaration * ld);
        setListInstruction(ListInstruction * lins);
    protected:
    	ListDeclaration * m_LD;
    	ListInstruction * m_LIns;
    private:
};

#endif // PROGRAMME_H
