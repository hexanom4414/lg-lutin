#ifndef LECTURE
#define LECTURE

#include <Instruction.h>
#include "Identificateur.h"

class Lecture : public Instruction
{
    public:
        Lecture();
        virtual ~Lecture();
    protected:
    	Identificateur* idToRead;
    private:
};

#endif // LECTURE