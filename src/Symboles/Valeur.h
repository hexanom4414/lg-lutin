#ifndef VALEUR
#define VALEUR

#include <Expression.h>


class Valeur : public Expression
{
    public:
        Valeur() : Symbole(VALEUR) {}
        virtual ~Valeur();
    protected:
    private:
};

#endif // VALEUR