#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Declaration.h"
#include "ListAffectation.h"


class Constante : public Declaration
{
    public:
        Constante(int id) : Declaration(id) {};
        void setAttribute(ListAffectation * p_listAffectation) {m_listAffectation = p_listAffectation;};
		void print();
        virtual ~Constante() {};
    protected:
    private:
        ListAffectation * m_listAffectation;
};

#endif // CONSTANTE_H
