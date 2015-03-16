#include "Identificateur.h"

Identificateur::Identificateur(int id) : SymboleSimple(id)
{
    //ctor
}

Identificateur::~Identificateur()
{
    //dtor
}

Identificateur::print()
{
	System.out.println(this.name);
}
