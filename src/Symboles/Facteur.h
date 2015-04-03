#ifndef FACTEUR_H
#define FACTEUR_H

#include "SymboleComplexe.h"

class Expression;
class Facteur : public SymboleComplexe
{
    public:
        Facteur(int id) : SymboleComplexe(id), m_isAnExpression(false), m_identificateur(""), m_isAnIdentificateur(false) {};
        virtual ~Facteur();

        void setAttribute(const string & identificateur) {m_identificateur = identificateur; m_isAnIdentificateur = true; m_isAnExpression = false;};
        void setAttribute(double valeur) {m_valeur = valeur; m_isAnExpression = false; m_isAnIdentificateur = false;};
        void setAttribute(Expression * p_expression) {m_expression = p_expression; m_isAnExpression = true; m_isAnIdentificateur = false;};
        void print();
        double eval();
        bool isConst();
        void staticCheck();
        Facteur * elementNeutre();
    protected:
        string m_identificateur;
        double m_valeur;
        Expression * m_expression;
        bool m_isAnExpression;
        bool m_isAnIdentificateur;
    private:
};

#endif // FACTEUR_H
