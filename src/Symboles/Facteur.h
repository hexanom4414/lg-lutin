#ifndef FACTEUR_H
#define FACTEUR_H

#include "SymboleSimple.h"
#include "Identificateur.h"
#include "Valeur.h"


class Facteur : public SymboleSimple
{
    public:
        Facteur(int id) : SymboleSimple(id), m_valIsValid(false) {};
        virtual ~Facteur() {};

        void setAttribute(Identificateur * p_identificateur) {m_identificateur = p_identificateur;};
        void setAttribute(Valeur * p_valeur);
        void print();
    protected:
        Identificateur * m_identificateur;
        bool m_valIsValid;
        int m_val;
    private:
};

#endif // FACTEUR_H
