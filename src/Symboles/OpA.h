#ifndef OPA_H
#define OPA_H

#include "Operateur.h"


class OpA : public Operateur
{
public:
    OpA(int id) : Operateur(id) {};
    virtual ~OpA() {};

    void print() {};
protected:
private:
};

#endif // OPA_H
