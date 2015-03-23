#include "ConcreteEtats.h"

transition_return Etat1::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case PROGRAMME:
            p_etat = new Etat2("Etat 2");
            automate.shift(p_etat, s);
            return SHIFTED;
        case LISTDECLARATION:
            p_etat = new Etat3("Etat 3");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            {
                ListDeclaration * p_listDeclaration = new ListDeclaration(LISTDECLARATION);
                automate.reduce(0, p_listDeclaration);
            }
            return REDUCED;
    }
}

//// end Etat1

transition_return Etat2::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case DOLLAR:
            //TODO : acceptation
            return ACCEPTED;
        default:
            cerr << "err2" << endl;
            return ERROR;
    }
}


//// end Etat2

transition_return Etat3::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case LISTINSTRUCTION:
            p_etat = new Etat4("Etat 4");
            automate.shift(p_etat, s);
            return SHIFTED;
        case DECLARATION:
            p_etat = new Etat29("Etat 29");
            automate.shift(p_etat, s);
            return SHIFTED;
        case SYMBVARIABLE:
            p_etat = new Etat30("Etat 30");
            automate.shift(p_etat, s);
            return SHIFTED;
        case CONSTANTE:
            p_etat = new Etat36("Etat 36");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            {
                ListInstruction * p_listInstruction = new ListInstruction(LISTINSTRUCTION);
                automate.reduce(0, p_listInstruction);
            }
            return REDUCED;
    }
}

//// end Etat3

transition_return Etat4::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INSTRUCTION:
            automate.shift(new Etat5("Etat 5"), s);
            return SHIFTED;
        case ECRIRE:
            automate.shift(new Etat6("Etat 6"), s);
            return SHIFTED;
        case LIRE:
            automate.shift(new Etat23("Etat 23"), s);
            return SHIFTED;
        case IDENTIFICATEUR:
            automate.shift(new Etat25("Etat 25"), s);
            return SHIFTED;
        case DOLLAR:
            {
                Programme * p_programme = new Programme(PROGRAMME);

                p_programme->setListInstruction((ListInstruction *) automate.depilerSymbole());
                p_programme->setListDeclaration((ListDeclaration *) automate.depilerSymbole());

                automate.reduce(2, p_programme);
            }
            return REDUCED;
        default:
            cerr << "err4" << endl;
            return ERROR;
    }
}

//// end Etat4

transition_return Etat5::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case DOLLAR:
            {
                ListInstruction * p_listInstruction = new ListInstruction(LISTINSTRUCTION);
                p_listInstruction->addToList((Instruction *) automate.depilerSymbole());
                p_listInstruction->addToList((ListInstruction *) automate.depilerSymbole());

                automate.reduce(2, p_listInstruction);
            }
            return REDUCED;
        default:
            cerr << "err5" << endl;
            return ERROR;
    }
}

//// end Etat5


transition_return Etat6::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPCOMPLEXE:
            p_etat = new Etat7("Etat 7");
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19("Etat 19");
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22("Etat 22");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12("Etat 12");
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE: //TODO
            p_etat = new Etat13("Etat 13");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14("Etat 14");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err6" << endl;
            return ERROR;
    }
}

//// end Etat6

transition_return Etat7::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPA:
            p_etat = new Etat8("Etat 8");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
            p_etat = new Etat17("Etat 17");
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18("Etat 18");
            automate.shift(p_etat, s);
            return SHIFTED;
        case DOLLAR:
            {
                Ecriture * p_ecriture = new Ecriture(ECRITURE);
                p_ecriture->setExpression((Expression *) automate.depilerSymbole());
                automate.depilerSymbole(true); // delete "�crire"

                automate.reduce(2, p_ecriture);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat7

transition_return Etat8::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case TERME:
            p_etat = new Etat9("Etat 9");
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22("Etat 22");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12("Etat 12");
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13("Etat 13");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14("Etat 14");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat8

transition_return Etat9::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPM:
            p_etat = new Etat10("Etat 10");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
        case MOINS:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Expression * p_expression = new Expression(EXPRESSION);
                p_expression->setAttribute((Terme *) automate.depilerSymbole());
                p_expression->setAttribute((OpA *) automate.depilerSymbole());
                p_expression->setAttribute((Expression *) automate.depilerSymbole());

                automate.reduce(3, p_expression);
            }
            return REDUCED;
        case MULT:
            p_etat = new Etat20("Etat 20");
            automate.shift(p_etat, s);
            return SHIFTED;
        case DIV:
            p_etat = new Etat21("Etat 21");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat9

transition_return Etat10::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case FACTEUR:
            p_etat = new Etat11("Etat 11");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12("Etat 12");
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13("Etat 13");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14("Etat 14");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat10

transition_return Etat11::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MOINS:
        case MULT:
        case DIV:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Terme * p_terme = new Terme(TERME);
                p_terme->setAttribute((Facteur *) automate.depilerSymbole());
                p_terme->setAttribute((OpM *) automate.depilerSymbole());
                p_terme->setAttribute((Terme *) automate.depilerSymbole());

                automate.reduce(3,p_terme);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat11


transition_return Etat12::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MOINS:
        case MULT:
        case DIV:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Facteur * p_facteur = new Facteur(FACTEUR);
                p_facteur->setAttribute((Identificateur *) automate.depilerSymbole());

                automate.reduce(1,p_facteur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat12

transition_return Etat13::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MOINS:
        case MULT:
        case DIV:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Facteur * p_facteur = new Facteur(FACTEUR);
                p_facteur->setAttribute((Valeur *) automate.depilerSymbole());

                automate.reduce(1,p_facteur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat13

transition_return Etat14::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPRESSION:
            p_etat = new Etat15("Etat 15");
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19("Etat 19");
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22("Etat 22");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12("Etat 12");
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13("Etat 13");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14("Etat 14");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat14

transition_return Etat15::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPA:
            p_etat = new Etat6("Etat 6");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
            p_etat = new Etat17("Etat 17");
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18("Etat 18");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PARFERME:
            p_etat = new Etat16("Etat 16");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat15

transition_return Etat16::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case MOINS:
        case PLUS:
        case MULT:
        case DIV:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Facteur * p_facteur = new Facteur(FACTEUR);
                p_facteur->setAttribute((ParFerme *) automate.depilerSymbole());
                p_facteur->setAttribute((Expression *) automate.depilerSymbole());
                p_facteur->setAttribute((ParOuvre *) automate.depilerSymbole());

                automate.reduce(3,p_facteur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat16

transition_return Etat17::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case IDENTIFICATEUR:
        case NOMBRE:
        case PAROUVRE:
            {
                OpA * p_opA = new OpA(OPA);
                p_opA = (Plus *) automate.depilerSymbole();

                automate.reduce(1,p_opA);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat17

transition_return Etat18::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case IDENTIFICATEUR:
        case NOMBRE:
        case PAROUVRE:
            {
                OpA * p_opA = new OpA(OPA);
                p_opA = (Moins *) automate.depilerSymbole();

                automate.reduce(1,p_opA);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat18

transition_return Etat19::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPM:
            p_etat = new Etat10("Etat 10");
            automate.shift(p_etat, s);
            return SHIFTED;
        case MULT:
            p_etat = new Etat20("Etat 20");
            automate.shift(p_etat, s);
            return SHIFTED;
        case DIV:
            p_etat = new Etat21("Etat 21");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
        case MOINS:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Expression * p_expression = new Expression(EXPRESSION);
                p_expression->setAttribute((Terme *) automate.depilerSymbole());

                automate.reduce(1,p_expression);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat19

transition_return Etat20::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case MULT:
        case DIV:
            {
                OpM * p_opM = new OpM(OPM);
                p_opM = (Mult *) automate.depilerSymbole();

                automate.reduce(1,p_opM);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat20

transition_return Etat21::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case MULT:
        case DIV:
            {
                OpM * p_opM = new OpM(OPM);
                p_opM = (Div *) automate.depilerSymbole();

                automate.reduce(1,p_opM);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat21

transition_return Etat22::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MOINS:
        case MULT:
        case DIV:
        case PARFERME:
        case POINTVIRGULE:
        case DOLLAR:
            {
                Terme * p_terme = new Terme (TERME);
                p_terme->setAttribute((Facteur *) automate.depilerSymbole());

                automate.reduce(1,p_terme);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat22

transition_return Etat23::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat24("Etat 24");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat23

transition_return Etat24::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case DOLLAR:
            {
                Lecture * p_lecture = new Lecture(LECTURE);
                p_lecture->setAttribute((Identificateur *) automate.depilerSymbole());
                automate.depilerSymbole(true);

                automate.reduce(2,p_lecture);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat24

transition_return Etat25::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat26("Etat 26");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat25

transition_return Etat26::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPRESSION:
            p_etat = new Etat27("Etat 27");
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19("Etat 19");
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22("Etat 22");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12("Etat 12");
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13("Etat 13");
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14("Etat 14");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat26

transition_return Etat27::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case PLUS:
            p_etat = new Etat17("Etat 17");
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18("Etat 18");
            automate.shift(p_etat, s);
            return SHIFTED;
        case POINTVIRGULE:
            p_etat = new Etat28("Etat 28");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat27

transition_return Etat28::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case DOLLAR:
            {
                Facteur * p_facteur = new Facteur(FACTEUR);
                p_facteur->setAttribute((Valeur *) automate.depilerSymbole());

                automate.reduce(4,p_facteur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat28

transition_return Etat29::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case DOLLAR:
            {
                ListDeclaration * p_listDeclaration = new ListDeclaration(LISTDECLARATION);
                p_listDeclaration->addToList((Declaration *) automate.depilerSymbole());
                p_listDeclaration->addToList((ListDeclaration *) automate.depilerSymbole());

                automate.reduce(2,p_listDeclaration);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat29

transition_return Etat30::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat35("Etat 35");
            automate.shift(p_etat, s);
            return SHIFTED;
        case LISTIDENTIFICATEUR:
            p_etat = new Etat31("Etat 31");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err30" << endl;
            return ERROR;
    }

}
//// end Etat30

transition_return Etat31::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTVIRGULE:
            p_etat = new Etat32("Etat 32");
            automate.shift(p_etat, s);
            return SHIFTED;
        case VIRGULE:
            p_etat = new Etat33("Etat 33");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat31

transition_return Etat32::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case DOLLAR:
            {
                Declaration * p_declaration = new Declaration(DECLARATION);
                p_declaration->setAttribute((PointVirgule *) automate.depilerSymbole());
                p_declaration->setAttribute((ListIdentificateur *) automate.depilerSymbole());
                p_declaration->setAttribute((Variable *) automate.depilerSymbole());

                automate.reduce(3,p_declaration);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat32

transition_return Etat33::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat34("Etat 34");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat33

transition_return Etat34::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
            {
                ListIdentificateur * p_ListIdentificateur = new ListIdentificateur(LISTIDENTIFICATEUR);
                p_ListIdentificateur->addToList((Identificateur *) automate.depilerSymbole());
                automate.depilerSymbole(true); //remove virgule
                p_ListIdentificateur->addToList((ListIdentificateur *) automate.depilerSymbole());

                automate.reduce(3,p_ListIdentificateur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat34

transition_return Etat35::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
            {
                ListIdentificateur * p_ListIdentificateur = new ListIdentificateur(LISTIDENTIFICATEUR);
                p_ListIdentificateur->addToList((Identificateur *) automate.depilerSymbole());
                automate.reduce(1,p_ListIdentificateur);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat35

transition_return Etat36::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case LISTAFFECTATION:
            p_etat = new Etat37("Etat 37");
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat43("Etat 43");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat36

transition_return Etat37::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTVIRGULE:
            p_etat = new Etat38("Etat 38");
            automate.shift(p_etat, s);
            return SHIFTED;
        case VIRGULE:
            p_etat = new Etat39("Etat 39");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat37

transition_return Etat38::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case DOLLAR:
            {
                Declaration * p_declaration = new Declaration(DECLARATION);
                p_declaration->setAttribute((PointVirgule *) automate.depilerSymbole());
                p_declaration->setAttribute((ListAffectation *) automate.depilerSymbole());
                p_declaration->setAttribute((Constante *) automate.depilerSymbole());

                automate.reduce(3,p_declaration);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat38

transition_return Etat39::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat40("Etat 40");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}
//// end Etat39

transition_return Etat40::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat41("Etat 41");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat40

transition_return Etat41::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case NOMBRE:
            p_etat = new Etat42("Etat 42");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat41

transition_return Etat42::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
            {
                ListAffectation * p_ListAffectation = new ListAffectation(LISTAFFECTATION);
                p_ListAffectation->setAttribute((Valeur *) automate.depilerSymbole());
                p_ListAffectation->setAttribute((Egal *) automate.depilerSymbole());
                p_ListAffectation->setAttribute((Identificateur *) automate.depilerSymbole());
                p_ListAffectation->setAttribute((Virgule *) automate.depilerSymbole());
                p_ListAffectation->addToList((ListAffectation *) automate.depilerSymbole());

                automate.reduce(5,p_ListAffectation);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat42

transition_return Etat43::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat44("Etat 44");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat43

transition_return Etat44::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case NOMBRE:
            p_etat = new Etat45("Etat 45");
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat44

transition_return Etat45::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
            {
                ListAffectation * p_ListAffectation = new ListAffectation(LISTAFFECTATION);
                p_ListAffectation->setAttribute((Valeur *) automate.depilerSymbole());
                p_ListAffectation->setAttribute((Egal *) automate.depilerSymbole());
                p_ListAffectation->setAttribute((Identificateur *) automate.depilerSymbole());

                automate.reduce(3,p_ListAffectation);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}
//// end Etat45
