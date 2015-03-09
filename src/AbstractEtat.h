#ifndef ABSTRACTETAT_H
#define ABSTRACTETAT_H

#include <iostream>

using namespace std;

class AbstractEtat
{
    public:
        AbstractEtat();
        AbstractEtat(string name);
        virtual ~AbstractEtat();

        void print() const;
        //virtual bool transition(Automate & automate, Symbole * s) = 0;

    protected:
        string m_name;
    private:
};

#endif // ABSTRACTETAT_H
