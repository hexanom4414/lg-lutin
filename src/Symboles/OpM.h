#ifndef OPM_H
#define OPM_H

#include "Operateur.h"


class OpM : public Operateur
{
    public:
        OpM(int id) : Operateur(id) {};
        virtual ~OpM();

        void print();
    protected:
    private:
};

#endif // OPM_H
