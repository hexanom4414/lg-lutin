#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "SymboleComplexe.h"
#include "SymboleSimple.h"


class Instruction : public SymboleComplexe
{
    public:
        Instruction(int id) : SymboleComplexe(id) { };
        virtual ~Instruction() {};
    protected:
    private:
};

#endif // INSTRUCTION_H
