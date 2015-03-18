#ifndef IDENTIFICATEUR_H
#define IDENTIFICATEUR_H

#include "SymboleSimple.h"


class Identificateur : public SymboleSimple
{
    public:
        Identificateur(int id) : SymboleSimple(id) {};
        virtual ~Identificateur() {};

        void setName(string name);
        void print();
    protected:
    	string m_name ;
    private:
};

#endif // IDENTIFICATEUR_H
