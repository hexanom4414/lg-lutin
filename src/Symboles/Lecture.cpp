#include "Lecture.h"
void Lecture::print()
{
    cout << "lire " << m_identificateur << " ;" << endl;
}

void Lecture::staticCheck()
{
    if(!DeclMap::Instance().checkIdent(m_identificateur))
    {
        print();
        cout << ">>>> err : " << m_identificateur << " declaration manquante" << endl;
    }
    else if (DeclMap::Instance().getIsConst(m_identificateur))
    {
        print();
        cout << ">>>> err : lecture sur constante" << endl;
    }
}


void Lecture::execute()
{
	double value;
	// Get the value from the standard input
	cout << "Entrez une valeur pour : " << m_identificateur << endl;
	cin >> value; // Secure input
	cout << "Vous avez entré : " << value << endl;

	
	// Set the value in the map 
	
	if(DeclMap::Instance().checkIdent(m_identificateur)){

	DeclMap::Instance().setValue(m_identificateur, value);
	
	}
}

