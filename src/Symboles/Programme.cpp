#include "Programme.h"

void Programme::setListDeclaration(ListDeclaration * ld)
{
	m_LD = ld;
}

void Programme::setListInstruction(ListInstruction * lins)
{
	m_LIns = lins;
}

void Programme::print()
{
    m_LD->print();
    m_LIns->print();
}
