#ifndef LISTAFFECTATION_H
#define LISTAFFECTATION_H

#include <list>
#include <utility>

#include "SymboleComplexe.h"

class ListAffectation : public SymboleComplexe
{
    public:
        ListAffectation(int id) : SymboleComplexe(id) {};
        virtual ~ListAffectation() {};

        void print();
        virtual void staticCheck();

        bool isEmpty();
        void popFront();
        pair<string,int> getFront();

        void setAttribute(const string & ident, int value);
        void setAttribute(ListAffectation * p_listAffectation);
    protected:
        list<pair<string,int> > m_listAffectation;
    private:
};

#endif // LISTAFFECTATION_H
