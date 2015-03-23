#ifndef FACTEUR_H
#define FACTEUR_H

#include "SymboleSimple.h"
#include "Identificateur.h"
#include "Valeur.h"
#include "ParFerme.h"
#include "ParOuvre.h"

class Expression;
class Facteur : public SymboleSimple
{
    public:
        Facteur(int id) : SymboleSimple(id), m_valIsValid(false) {};
        virtual ~Facteur() {};

        void setAttribute(Identificateur * p_identificateur) {m_identificateur = p_identificateur;};
        void setAttribute(Valeur * p_valeur);
        void setAttribute(ParFerme * p_parFerme) {m_parFerme = p_parFerme;};
        void setAttribute(Expression * p_expression) {m_expression = p_expression;};
        void setAttribute(ParOuvre * p_parOuvre) {m_parOuvre = p_parOuvre;};
        void print();
    protected:
        Identificateur * m_identificateur;
        ParOuvre * m_parOuvre;
        Expression * m_expression;
        ParFerme * m_parFerme;
        bool m_valIsValid;
        int m_val;
    private:
};

#endif // FACTEUR_H
