#ifndef DECLMAP_H
#define DECLMAP_H

#include <map>
#include <string>
#include "utils.h"

using namespace std;

class DeclMap
{
public:
    DeclMap();
    virtual ~DeclMap();

    int getValue(const string & ident);
    void setValue(const string & ident, int val);
    void addIdent(const string & ident);
    void print();
protected:
private:
    map<string,pair<int,bool> > m_declMap;
    map<string,pair<int,bool> >::iterator m_it;

    bool checkIdent(const string & ident);
};

#endif // DECLMAP_H
