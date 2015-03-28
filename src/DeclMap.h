#ifndef DECLMAP_H
#define DECLMAP_H

#include <map>
#include <string>
#include "utils.h"

using namespace std;

class DeclMap
{
    public:
        static DeclMap& Instance();

        int getValue(const string & ident);
        bool getIsConst(const string & ident);
        bool getIsInitialized(const string & ident);

        void clearMap() {m_declMap.clear();};
        void setValue(const string & ident, int val);
        void addIdent(const string & ident, bool isConst, int val = 0);
        bool checkIdent(const string & ident);
        void print();
    protected:
    private:
        DeclMap& operator= (const DeclMap&) {};
        DeclMap (const DeclMap&) {};
        static DeclMap m_instance;
        DeclMap();
        ~DeclMap();


        struct IdentValue
        {
            bool isConst, isInitialized;
            int value;
        };

        map<string,IdentValue> m_declMap;
        map<string,IdentValue>::iterator m_it;
};

#endif // DECLMAP_H
