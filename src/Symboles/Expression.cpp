#include "Expression.h"

void Expression::print()
{
    if(!m_isTerme)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}

int Expression::eval()
{
    if(!m_isTerme)
    {
        if(m_operateur->getType() == PLUS)
            return m_expGauche->eval() + m_expDroite->eval();
        else if (m_operateur->getType() == MOINS)
            return m_expGauche->eval() - m_expDroite->eval();
    }
    return m_expDroite->eval();
}

void Expression::staticCheck()
{
    if(!m_isTerme)
    {
        m_expGauche->staticCheck();
    }
    m_expDroite->staticCheck();
}

void Expression::transformation()
{
    isConst();
}

bool Expression::isConst()
{
    if(!m_isTerme)
    {
        if(m_expGauche->isConst() && m_expDroite->isConst())
        {
            if(m_operateur->getType() == PLUS)
            {
                m_expDroite->setFacteurVal(m_expGauche->eval() + m_expDroite->eval());
            }
            else if (m_operateur->getType() == MOINS)
            {
                m_expDroite->setFacteurVal(m_expGauche->eval() - m_expDroite->eval());
            }
            m_isTerme = true;
            return true;
        }
        else
        {
            m_isTerme = false;
            return false;
        }
    }
    else
    {
        return m_expDroite->isConst();
    }
}
