#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "SymboleComplexe.h"
#include "OpA.h"
#include "Terme.h"


class Expression : public SymboleComplexe
{
public:
    Expression(int id) : SymboleComplexe(id) {};
    virtual ~Expression() {};
    virtual void print();
    void setAttribute(OpA * p_opA);
    void setAttribute(Terme * p_terme);
    void setAttribute(Expression * p_expression);
protected:
    OpA * m_opA;
    Terme * m_terme;
    Expression * m_expression;
private:
};

#endif // EXPRESSION
