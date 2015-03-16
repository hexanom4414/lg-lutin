#ifndef LISTINSTRUCTION_H
#define LISTINSTRUCTION_H

#include "SymboleComplexe.h"
#include <list>
#include "Instruction.h"

class ListInstruction : public SymboleComplexe
{
    public:
        ListInstruction() : SymboleComplexe(LISTINSTRUCTION) {}
        virtual ~ListInstruction();

        void addToList(ListInstruction * p_listInstruction);
        void addToList(Instruction * p_Instruction);
    protected:
    	list<Instruction *> m_listInstruction;
    private:
};

#endif // LISTINSTRUCTION_H
