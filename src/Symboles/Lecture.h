#ifndef LECTURE_H
#define LECTURE_H

#include "Instruction.h"
#include "Identificateur.h"

class Lecture : public Instruction
{
    public:
        Lecture(int id) : Instruction (id) {}
        virtual ~Lecture();
		void print() {};
        //bool do(&idToRead);
    protected:
    	Identificateur* idToRead;
    private:
};

#endif // LECTURE