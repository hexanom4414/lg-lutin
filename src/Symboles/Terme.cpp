#include "Terme.h"
#include "Facteur.h"

void Terme::print()
{
    if(!m_isFacteur)
    {
        m_expGauche->print();
        m_operateur->print();
    }
    m_expDroite->print();
}

double Terme::eval()
{
    if(!m_isFacteur)
    {
        if(m_operateur->getType() == MULT)
            return m_expGauche->eval() * m_expDroite->eval();
        else if (m_operateur->getType() == DIV)
            return m_expGauche->eval() / m_expDroite->eval();
    }
    return m_expDroite->eval();
}

void Terme::staticCheck()
{
    if(!m_isFacteur)
    {
        m_expGauche->staticCheck();
    }
    m_expDroite->staticCheck();
}

bool Terme::isConst()
{
    if(!m_isFacteur)
    {
        if(m_expGauche->isConst() && m_expDroite->isConst())
        {
            if(m_operateur->getType() == MULT)
                m_expDroite->setAttribute(m_expGauche->eval() * m_expDroite->eval());
            else if (m_operateur->getType() == DIV)
                m_expDroite->setAttribute(m_expGauche->eval() / m_expDroite->eval());

            m_isFacteur = true;
            return true;
        }
        else
        {
            m_isFacteur = false;
            return false;
        }
    }
    else
    {
        return m_expDroite->isConst();
    }
}

void Terme::setFacteurVal(double val)
{
    m_expDroite->setAttribute(val);
}

void Terme::setFacteurExp(Expression * p_exp)
{
    m_expDroite->setAttribute(p_exp);
}

Terme * Terme::elementNeutre()
{
    if(!m_isFacteur)
    {
        if(m_expGauche->eval() == 1 && m_operateur->getType() == MULT)
        {
            m_isFacteur = true;
            return this;
        }
        if(m_expDroite->eval() == 1)
        {
            return m_expGauche;
        }
    }
    return this;
}
