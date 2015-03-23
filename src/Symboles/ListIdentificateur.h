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

        void addToList(ListIdentificateur * p_listIdentificateur);
        void addToList(Identificateur * p_Identificateur);
        bool isEmpty();
        void popFront();
        Identificateur * getFront();
        virtual void print();
    protected:
    	list<Identificateur *> m_listIdentificateur;
    private:
};

#endif // LISTIDENTIFICATEUR_H
