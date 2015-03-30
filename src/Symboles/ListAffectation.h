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
        virtual void transformation();
        virtual void execute();

        bool isEmpty();
        void popFront();
        pair<string,double> getFront();

        void setAttribute(const string & ident, double value);
        void setAttribute(ListAffectation * p_listAffectation);
    protected:
        list<pair<string,double> > m_listAffectation;
    private:
};

#endif // LISTAFFECTATION_H
