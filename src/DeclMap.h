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

        double getValue(const string & ident);
        bool getIsConst(const string & ident);
        bool getIsInitialized(const string & ident);
        bool getVarIsReaded(const string & ident);

        void clearMap() {m_declMap.clear();};
        void setValue(const string & ident, double val);
        void setUsed(const string & ident);
        void setInitialized(const string & ident);
        void setVarIsReaded(const string & ident);
        void addIdent(const string & ident, bool isConst, double val = 0);
        bool checkIdent(const string & ident);
        void print();
        void staticCheck();
    protected:
    private:
        DeclMap& operator= (const DeclMap&) {};
        DeclMap (const DeclMap&) {};
        static DeclMap m_instance;
        DeclMap();
        ~DeclMap();

        struct IdentValue
        {
            bool isConst, isInitialized, isUsed, varIsReaded;
            double value;
        };

        map<string,IdentValue> m_declMap;
        map<string,IdentValue>::iterator m_it;
};

#endif // DECLMAP_H
