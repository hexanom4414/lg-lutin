#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "SymboleComplexe.h"
#include "ListDeclaration.h"
#include "ListInstruction.h"

class Programme : public SymboleComplexe
{
    public:
        Programme(int id) : SymboleComplexe (id) {};
        virtual ~Programme() {};

        void setListDeclaration(ListDeclaration * ld);
        void setListInstruction(ListInstruction * lins);
        virtual void print();
    protected:
    	ListDeclaration * m_LD;
    	ListInstruction * m_LIns;
    private:
};

#endif // PROGRAMME_H
