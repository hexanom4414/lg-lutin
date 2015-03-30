#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "SymboleComplexe.h"

class Instruction : public SymboleComplexe
{
    public:
        Instruction(int id) : SymboleComplexe(id) { };
		virtual void execute() = 0;
		virtual void print() = 0;
		virtual void staticCheck() =0;
        virtual ~Instruction() {};
    protected:
    private:
};

#endif // INSTRUCTION_H
