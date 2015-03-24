#ifndef LISTINSTRUCTION_H
#define LISTINSTRUCTION_H

#include "SymboleComplexe.h"
#include <list>
#include "Instruction.h"

class ListInstruction : public SymboleComplexe
{
    public:
        ListInstruction(int id) : SymboleComplexe(id) {};
        virtual ~ListInstruction() {};

        void setAttribute(ListInstruction * p_listInstruction);
        void setAttribute(Instruction * p_Instruction);
        bool isEmpty();
        void popFront();
        Instruction * getFront();
        virtual void print();
    protected:
    	list<Instruction *> m_listInstruction;
    private:
};

#endif // LISTINSTRUCTION_H
