#ifndef LISTIDENTIFICATEUR_H
#define LISTIDENTIFICATEUR_H

#include "SymboleComplexe.h"
#include "Identificateur.h"
#include <list>

class ListIdentificateur : public SymboleComplexe
{
    public:
        ListIdentificateur(int id): SymboleComplexe(id) {};
        virtual ~ListIdentificateur() {};

        void setAttribute(ListIdentificateur * p_listIdentificateur);
        void setAttribute(const string & identificateur);
        bool isEmpty();
        void popFront();
        string getFront();
        virtual void execute();
        virtual void print();
        virtual void staticCheck();
    protected:
    	list<string> m_listIdentificateur;
    private:
};

#endif // LISTIDENTIFICATEUR_H
