#ifndef LISTINSTRUCTION
#define LISTINSTRUCTION

#include <SymboleComplexe.h>
#include <list>
#include "Instruction.h"

class ListInstruction : public SymboleComplexe
{
    public:
        ListInstruction() : Symbole(LISTINSTRUCTION) {}
        virtual ~ListInstruction();
    protected:
    	List<Instruction *> list;
    private:
};

#endif // LISTINSTRUCTION