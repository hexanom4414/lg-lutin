/*************************************************************************
                           Automate  -  description
                             -------------------
    début                : 09/03/2015
    copyright            : (C) 2015 par hexanom4414
*************************************************************************/

//---------- Interface de la classe <Automate> (fichier Automate.h) ------
#ifndef Automate_H
#define Automate_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>
#include "Etat.h"
#include "Symbole.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Automate>
//
//
//------------------------------------------------------------------------

class Automate
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void lecture();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Automate ( const Automate & unAutomate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Automate ( );
    virtual ~Automate ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    stack <Etat> pileEtats;
    stack <Symbole> pileSymboles;

};

//--------------------------- Autres définitions dépendantes de <Automate>

#endif // AUTOMATE_H

