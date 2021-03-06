#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include "Automate.h"
#include "Lexer.h"

using namespace std;
using namespace boost;

bool affichage = false, analyse = false, execution = false, optimisation = false;
string m_file = "";

void help_message()
{
    cout << "lutin.exe file [args]" << endl;
    cout << "affichage : -p" << endl;
    cout << "analyse statique : -a" << endl;
    cout << "execution : -e" << endl;
    cout << "optimisation : -o" << endl;
}

int main(int argc, const char* argv[])
{
    for (int x = 1; x < argc; ++x)
    {
        string arg(argv[x]);
        if(arg.compare("-help") == 0 && x == 1)
        {
            help_message();
            return 0;
        }
        if(arg.compare("-p") == 0)
            affichage = true;
        else if(arg.compare("-a") == 0)
            analyse = true;
        else if(arg.compare("-e") == 0)
            execution = true;
        else if(arg.compare("-o") == 0)
            optimisation = true;
        else if(m_file.compare("") == 0)
            m_file.assign(arg);
        else
        {
            cerr << arg << " : Argument inconnu" << endl;
            cerr << "Use \"Lutin -help\" for help" << endl;
            return 1;
        }
    }



    if(m_file.compare("") == 0)
    {
        cerr << "Need file" << endl;
        cerr << "Use \"Lutin -help\" for help" << endl;
        return 1;
    }

    ifstream fichier(m_file.c_str());
    if(fichier.fail())
    {
        cerr << m_file << " : Fichier inexistant ou non lisible" << endl;

        return 1;
    }

    //// Lancement automate

    Automate * automate = new Automate(m_file);
    if(automate->run() == FINISH)
    {
        if(analyse)
            automate->checkStatic();
        if(execution)
            automate->execute();
        if(optimisation)
            automate->transformation();
        if(affichage)
            automate->printProgram();
    }
    return 0;
}


