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

        void setAttribute(ListDeclaration * p_listDeclaration) {m_listDeclaration = p_listDeclaration;};
        void setAttribute(ListInstruction * p_listInstruction) {m_listInstruction = p_listInstruction;};
        void print();
    protected:
    private:
        ListDeclaration * m_listDeclaration;
    	ListInstruction * m_listInstruction;
};

#endif // PROGRAMME_H
