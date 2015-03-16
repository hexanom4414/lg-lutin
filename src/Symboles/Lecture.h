#ifndef LECTURE
#define LECTURE

#include <Instruction.h>
#include "Identificateur.h"
#include "utils.h"

class Lecture : public Instruction
{
    public:
        Lecture() : Symbole (LECTURE) {}
        virtual ~Lecture();

        bool do(&idToRead);
    protected:
    	Identificateur* idToRead;
    private:
};

#endif // LECTURE