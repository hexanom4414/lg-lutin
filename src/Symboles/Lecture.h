#ifndef LECTURE_H
#define LECTURE_H

#include "Instruction.h"
#include "Identificateur.h"

class Lecture : public Instruction
{
    public:
        Lecture(int id) : Instruction (id) {}
        virtual ~Lecture() {};
        void setAttribute(const string & identificateur) {m_identificateur.assign(identificateur);};
        virtual void execute();
		void print();
		virtual void staticCheck();
    protected:
    	string m_identificateur;
    private:
};

#endif // LECTURE
