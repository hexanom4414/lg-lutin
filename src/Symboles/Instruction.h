#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "SymboleComplexe.h"


class Instruction : public SymboleComplexe
{
    public:
        Instruction() : SymboleComplexe(INSTRUCTION) { };
        virtual ~Instruction();
    protected:
    private:
};

#endif // INSTRUCTION_H
