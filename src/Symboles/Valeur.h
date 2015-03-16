#ifndef VALEUR_H
#define VALEUR_H

#include "Expression.h"


class Valeur : public Expression
{
    public:
        Valeur() : Expression(VALEUR) {}
		void print() {};
        virtual ~Valeur();
    protected:
    private:
};

#endif // VALEUR_H