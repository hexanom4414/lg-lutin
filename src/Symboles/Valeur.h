#ifndef VALEUR_H
#define VALEUR_H

#include "SymboleSimple.h"

class Valeur : public SymboleSimple
{
    public:
        Valeur(int id) : SymboleSimple(id) {};
        virtual ~Valeur(){};

        void setValue(double value) {m_value = value;};
        double getValue() {return m_value;};
    protected:
        double m_value ;
    private:
};

#endif // VALEUR_H
