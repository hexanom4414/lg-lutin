#ifndef VARIABLE_H
#define VARIABLE_H

#include "Declaration.h"
#include "ListIdentificateur.h"

class Variable : public Declaration
{
    public:
        Variable(int id) : Declaration(id){}
		virtual void print();
		void setAttribute(ListIdentificateur * p_listIdentificateur) {m_listIdentificateur = p_listIdentificateur;};
        virtual ~Variable() {};
    protected:
    private:
        ListIdentificateur * m_listIdentificateur;
};

#endif // VARIABLE_H
