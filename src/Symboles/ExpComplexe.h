#ifndef EXPCOMPLEXE
#define EXPCOMPLEXE

#include <Expression.h>
#include "Operateur.h"

class ExpComplexe : public Expression
{
    public:
        ExpComplexe();
        virtual ~ExpComplexe();
    protected:
    	Expression *expG;
    	Expression *expD;
    	Operateur *op;
    private:
};

#endif // EXPCOMPLEXE