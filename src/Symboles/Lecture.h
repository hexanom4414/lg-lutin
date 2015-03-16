#ifndef LECTURE
#define LECTURE

#include <Instruction.h>
#include "Identificateur.h"

class Lecture : public Instruction
{
    public:
        Lecture();
        virtual ~Lecture();

        bool do(&idToRead);
    protected:
    	Identificateur* idToRead;
    private:
};

#endif // LECTURE