#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include "src/Automate.h"
#include "src/Lexer.h"

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
            cout << arg << " : Argument inconnu" << endl;
            cout << "Use \"Lutin -help\" for help" << endl;
            return 0;
        }
    }



    if(m_file.compare("") == 0)
    {
        cout << "Need file" << endl;
        cout << "Use \"Lutin -help\" for help" << endl;
        return 0;
    }

    ifstream fichier(m_file.c_str());
    if(fichier.fail())
    {
        cout << m_file << " : Fichier inexistant ou non lisible" << endl;
    }

    //// Lancement automate
    Automate * automate = new Automate(m_file, true);
    if(automate->run() == FINISH)
    {
        if(affichage)
            automate->printProgram();
        if(analyse)
            automate->checkStatic();
        if(optimisation)
            automate->transformation();
    }
    return 0;
}


