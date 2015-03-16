#ifndef LISTIDENTIFICATEUR_H
#define LISTIDENTIFICATEUR_H

#include <SymboleComplexe.h>


class ListIdentificateur : public SymboleComplexe
{
    public:
        ListIdentificateur();
        virtual ~ListIdentificateur();
    protected:
    	List<Identificateur *> list;
    private:
};

#endif // LISTIDENTIFICATEUR_H