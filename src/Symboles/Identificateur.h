#ifndef IDENTIFICATEUR_H
#define IDENTIFICATEUR_H

#include "SymboleSimple.h"

class Identificateur : public SymboleSimple
{
public:
    Identificateur(int id) : SymboleSimple(id) {};
    virtual ~Identificateur() {};
    string getName() {return m_name;};
    void setName(const string & name) {m_name.assign(name);};
protected:
    string m_name;
private:
};

#endif // IDENTIFICATEUR_H
