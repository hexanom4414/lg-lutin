#ifndef LISTDECLARATION_H
#define LISTDECLARATION_H

#include "SymboleComplexe.h"
#include "Declaration.h"
#include <list>

class ListDeclaration : public SymboleComplexe
{
    public:
        ListDeclaration(int id) : SymboleComplexe(id) {};
        virtual ~ListDeclaration() { };

		void print();
		void addToList(ListDeclaration * p_listDeclaration);
        void addToList(Declaration * p_Declaration);
        bool isEmpty();
        void popFront();
        Declaration * getFront();
    protected:
    	list<Declaration *> m_listDeclaration;
    private:
};

#endif // LISTDECLARATION_H
