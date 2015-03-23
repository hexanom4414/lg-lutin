#ifndef LECTURE_H
#define LECTURE_H

#include "Instruction.h"
#include "Identificateur.h"

class Lecture : public Instruction
{
    public:
        Lecture(int id) : Instruction (id) {}
        virtual ~Lecture() {};

        void setAttribute(Identificateur * p_identificateur) {m_identificateur = p_identificateur;};
		void print() {};
        //bool do(&idToRead);
    protected:
    	Identificateur * idToRead;
    	Identificateur * m_identificateur;
    private:
};

#endif // LECTURE
