#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Expression.h"
#include "Valeur.h"
#include "Identificateur.h"
#include "../utils.h"

class Affectation : public Instruction
{
    public:
        Affectation(int id) : Instruction(id) {};
        virtual ~Affectation() {};

        void setAttribute(Expression * p_expression) {m_expression = p_expression;};
        void setAttribute(const string & ident) {m_ident = ident;};
		void print();
		void execute();
		virtual void staticCheck();
    protected:
    	string m_ident;
    	Expression * m_expression;
    private:
};

#endif // AFFECTATION_H
