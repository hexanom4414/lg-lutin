#ifndef TERME_H
#define TERME_H

#include "SymboleSimple.h"
#include "OpM.h"
#include "Facteur.h"


class Terme : public SymboleSimple
{
public:
    Terme(int id) : SymboleSimple(id) {};
    virtual ~Terme() {};

    virtual void print();
    void setAttribute(OpM * p_opM) {m_opM = p_opM;};
    void setAttribute(Terme * p_terme) {m_terme = p_terme;};
    void setAttribute(Facteur * p_facteur) {m_facteur = p_facteur;};
protected:
    OpM * m_opM;
    Terme * m_terme;
    Facteur * m_facteur;
private:
};

#endif // TERME_H
