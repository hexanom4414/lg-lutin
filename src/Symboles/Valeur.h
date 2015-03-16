#ifndef VALEUR_H
#define VALEUR_H

#include "SymboleSimple.h"

class Valeur : public SymboleSimple
{
    public:
        Valeur(int id) : SymboleSimple(id) {};
        virtual ~Valeur();

        void setValue(int value) {m_value = value;};
        int getValue() {return m_value;};
        void print() {cout << m_value << " ";};
    protected:
        int m_value;
    private:
};

#endif // VALEUR_H
