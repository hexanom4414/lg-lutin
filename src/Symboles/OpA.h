#ifndef OPA_H
#define OPA_H

#include "Operateur.h"


class OpA : public Operateur
{
    public:
        OpA(int id) : Operateur(id) {};
        virtual ~OpA() {};

        void setAttribute(int type) {m_type = type;};
        void print();
    protected:
    private:
        int m_type;
};

#endif // OPA_H
