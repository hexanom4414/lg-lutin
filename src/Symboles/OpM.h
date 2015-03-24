#ifndef OPM_H
#define OPM_H

#include "Operateur.h"


class OpM : public Operateur
{
    public:
        OpM(int id) : Operateur(id) {};
        virtual ~OpM() {};
        void setAttribute(int type) {m_type = type;};
        void print();
    protected:
    private:
        int m_type;
};

#endif // OPM_H
