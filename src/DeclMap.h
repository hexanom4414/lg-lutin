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
    void addIdent(const string & ident, bool isConst, int val = 0);
    void print();
protected:
private:
    struct IdentValue {
        bool isConst, isInitialized;
        int value;
    };

    map<string,IdentValue> m_declMap;
    map<string,IdentValue>::iterator m_it;

    bool checkIdent(const string & ident);
};

#endif // DECLMAP_H
