#include "Expression.h"

Expression::~Expression()
{
    /* delete m_expDroite;
    delete m_expGauche;
    delete m_operateur; */
}

void Expression::print()
{
    if(!m_isTerme)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}

double Expression::eval()
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

bool Expression::isConst()
{
    if(!m_isTerme)
    {
        bool g = m_expGauche->isConst();
        bool d = m_expDroite->isConst();
        if(g && d)
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

Expression * Expression::elementNeutre()
{
    m_expDroite = m_expDroite->elementNeutre();
    if(!m_isTerme)
    {
        if(m_expGauche->eval() == 0 && m_operateur->getType() == PLUS)
        {
            m_isTerme = true;
            return this;
        }
        if(m_expDroite->eval() == 0)
        {
            return m_expGauche;
        }
    }
    return this;
}
