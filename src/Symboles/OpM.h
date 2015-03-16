#ifndef OPM_H
#define OPM_H

#include "Operateur.h"


class OpM : public Operateur
{
    public:
        OpM() : Symbole(OPM){}
        virtual ~OpM();
    protected:
    private:
};

#endif // OPM_H
