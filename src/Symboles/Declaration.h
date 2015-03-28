#ifndef DECLARATION_H
#define DECLARATION_H

#include "SymboleComplexe.h"

class Declaration : public SymboleComplexe
{
public:
    Declaration(int id) : SymboleComplexe(id) {};
    virtual ~Declaration() {};

    virtual void print() = 0;
    virtual void staticCheck() {};
protected:
private:
};

#endif // DECLARATION_H
