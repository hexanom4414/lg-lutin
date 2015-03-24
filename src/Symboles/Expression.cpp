#include "Expression.h"

void Expression::print()
{
    if(m_expGauche != NULL)
    {
        cout << endl << "1111111111" << endl;
        m_expGauche->print();
        cout << endl << "2222222222" << endl;
        m_operateur->print();
        cout << endl << "33333333" << endl;
    }
    m_expDroite->print();
    cout << endl << "444444444" << endl;
}
