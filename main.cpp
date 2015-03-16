#include <iostream>
#include <boost/regex.hpp>
#include "src/Automate.h"

using namespace std;

int main(int argc, const char* argv[])
{
    cout << "Hello" << endl;

    // argc test
    cout << "Nombre d'arguments : " << argc << endl;

    // argv treatment
    for (int x = 0; x < argc; ++x)
    {
        cout << "Argument " << x << " : " << argv[x] << endl;
    }

    return 0;
}
