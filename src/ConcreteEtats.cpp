#include "ConcreteEtats.h"

Etat1::Etat1()
{
    //ctor
}

Etat1::~Etat1()
{
    //dtor
}

transition_return Etat1::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case PROGRAMME:
            p_etat = new Etat2();
            automate.shift(p_etat, s);
            return SHIFTED;
        case LISTDECLARATION:
            p_etat = new Etat3();
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

Etat2::Etat2()
{
    //ctor
}

Etat2::~Etat2()
{
    //dtor
}

transition_return Etat2::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case DOLLAR:
            //TODO : acceptation
            return ACCEPTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}


//// end Etat2


Etat3::Etat3()
{
    //ctor
}

Etat3::~Etat3()
{
    //dtor
}

transition_return Etat3::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case LISTINSTRUCTION:
            p_etat = new Etat4();
            automate.shift(p_etat, s);
            return SHIFTED;
        case DECLARATION:
            p_etat = new Etat29();
            automate.shift(p_etat, s);
            return SHIFTED;
        case SYMBVARIABLE:
            p_etat = new Etat30();
            automate.shift(p_etat, s);
            return SHIFTED;
        case CONSTANTE:
            p_etat = new Etat36();
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


Etat4::Etat4()
{
    //ctor
}

Etat4::~Etat4()
{
    //dtor
}

transition_return Etat4::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INSTRUCTION:
            automate.shift(new Etat5(), s);
            return SHIFTED;
        case ECRIRE:
            automate.shift(new Etat6(), s);
            return SHIFTED;
        case LIRE:
            automate.shift(new Etat23(), s);
            return SHIFTED;
        case IDENTIFICATEUR:
            automate.shift(new Etat25(), s);
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
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat4


Etat5::Etat5()
{
    //ctor
}

Etat5::~Etat5()
{
    //dtor
}

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
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat5


Etat6::Etat6()
{
    //ctor
}

Etat6::~Etat6()
{
    //dtor
}

transition_return Etat6::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPCOMPLEXE:
            p_etat = new Etat7();
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19();
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12();
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE: //TODO
            p_etat = new Etat13();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat6


Etat7::Etat7()
{
    //ctor
}

Etat7::~Etat7()
{
    //dtor
}

transition_return Etat7::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPA:
            p_etat = new Etat8();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
            p_etat = new Etat17();
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18();
            automate.shift(p_etat, s);
            return SHIFTED;
        case DOLLAR:
            {
                Ecriture * p_ecriture = new Ecriture(ECRITURE);
                p_ecriture->setExpression((Expression *) automate.depilerSymbole());
                automate.depilerSymbole(true); // delete "écrire"

                automate.reduce(2, p_ecriture);
            }
            return REDUCED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat7


Etat8::Etat8()
{
    //ctor
}

Etat8::~Etat8()
{
    //dtor
}

transition_return Etat8::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case TERME:
            p_etat = new Etat9();
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12();
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat8


Etat9::Etat9()
{
    //ctor
}

Etat9::~Etat9()
{
    //dtor
}

transition_return Etat9::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPM:
            p_etat = new Etat10();
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
            p_etat = new Etat20();
            automate.shift(p_etat, s);
            return SHIFTED;
        case DIV:
            p_etat = new Etat21();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat9


Etat10::Etat10()
{
    //ctor
}

Etat10::~Etat10()
{
    //dtor
}

transition_return Etat10::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case FACTEUR:
            p_etat = new Etat11();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12();
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat10


Etat11::Etat11()
{
    //ctor
}

Etat11::~Etat11()
{
    //dtor
}

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


Etat12::Etat12()
{
    //ctor
}

Etat12::~Etat12()
{
    //dtor
}

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


Etat13::Etat13()
{
    //ctor
}

Etat13::~Etat13()
{
    //dtor
}

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


Etat14::Etat14()
{
    //ctor
}

Etat14::~Etat14()
{
    //dtor
}

transition_return Etat14::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPRESSION:
            p_etat = new Etat15();
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19();
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12();
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}


//// end Etat14


Etat15::Etat15()
{
    //ctor
}

Etat15::~Etat15()
{
    //dtor
}

transition_return Etat15::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPA:
            p_etat = new Etat6();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PLUS:
            p_etat = new Etat17();
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PARFERME:
            p_etat = new Etat16();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat15


Etat16::Etat16()
{
    //ctor
}

Etat16::~Etat16()
{
    //dtor
}

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


Etat17::Etat17()
{
    //ctor
}

Etat17::~Etat17()
{
    //dtor
}

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

Etat18::Etat18()
{
    //ctor
}

Etat18::~Etat18()
{
    //dtor
}

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


Etat19::Etat19()
{
    //ctor
}

Etat19::~Etat19()
{
    //dtor
}

transition_return Etat19::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case OPM:
            p_etat = new Etat10();
            automate.shift(p_etat, s);
            return SHIFTED;
        case MULT:
            p_etat = new Etat20();
            automate.shift(p_etat, s);
            return SHIFTED;
        case DIV:
            p_etat = new Etat21();
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


Etat20::Etat20()
{
    //ctor
}

Etat20::~Etat20()
{
    //dtor
}

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


Etat21::Etat21()
{
    //ctor
}

Etat21::~Etat21()
{
    //dtor
}

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


Etat22::Etat22()
{
    //ctor
}

Etat22::~Etat22()
{
    //dtor
}

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


Etat23::Etat23()
{
    //ctor
}

Etat23::~Etat23()
{
    //dtor
}

transition_return Etat23::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat24();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat23


Etat24::Etat24()
{
    //ctor
}

Etat24::~Etat24()
{
    //dtor
}

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


Etat25::Etat25()
{
    //ctor
}

Etat25::~Etat25()
{
    //dtor
}

transition_return Etat25::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat26();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat25


Etat26::Etat26()
{
    //ctor
}

Etat26::~Etat26()
{
    //dtor
}

transition_return Etat26::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case EXPRESSION:
            p_etat = new Etat27();
            automate.shift(p_etat, s);
            return SHIFTED;
        case TERME:
            p_etat = new Etat19();
            automate.shift(p_etat, s);
            return SHIFTED;
        case FACTEUR:
            p_etat = new Etat22();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat12();
            automate.shift(p_etat, s);
            return SHIFTED;
        case NOMBRE:
            p_etat = new Etat13();
            automate.shift(p_etat, s);
            return SHIFTED;
        case PAROUVRE:
            p_etat = new Etat14();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat26

Etat27::Etat27()
{
    //ctor
}

Etat27::~Etat27()
{
    //dtor
}

transition_return Etat27::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case PLUS:
            p_etat = new Etat17();
            automate.shift(p_etat, s);
            return SHIFTED;
        case MOINS:
            p_etat = new Etat18();
            automate.shift(p_etat, s);
            return SHIFTED;
        case POINTVIRGULE:
            p_etat = new Etat28();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat27

Etat28::Etat28()
{
    //ctor
}

Etat28::~Etat28()
{
    //dtor
}

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

Etat29::Etat29()
{
    //ctor
}

Etat29::~Etat29()
{
    //dtor
}

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

Etat30::Etat30()
{
    //ctor
}

Etat30::~Etat30()
{
    //dtor
}

transition_return Etat30::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat31();
            automate.shift(p_etat, s);
            return SHIFTED;
        case LISTDECLARATION:
            p_etat = new Etat35();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat30

Etat31::Etat31()
{
    //ctor
}

Etat31::~Etat31()
{
    //dtor
}

transition_return Etat31::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTVIRGULE:
            p_etat = new Etat32();
            automate.shift(p_etat, s);
            return SHIFTED;
        case VIRGULE:
            p_etat = new Etat33();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat31

Etat32::Etat32()
{
    //ctor
}

Etat32::~Etat32()
{
    //dtor
}

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

Etat33::Etat33()
{
    //ctor
}

Etat33::~Etat33()
{
    //dtor
}

transition_return Etat33::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat34();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat33

Etat34::Etat34()
{
    //ctor
}

Etat34::~Etat34()
{
    //dtor
}
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

Etat35::Etat35()
{
    //ctor
}

Etat35::~Etat35()
{
    //dtor
}

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

Etat36::Etat36()
{
    //ctor
}

Etat36::~Etat36()
{
    //dtor
}

transition_return Etat36::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case LISTAFFECTATION:
            p_etat = new Etat37();
            automate.shift(p_etat, s);
            return SHIFTED;
        case IDENTIFICATEUR:
            p_etat = new Etat43();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat36

Etat37::Etat37()
{
    //ctor
}

Etat37::~Etat37()
{
    //dtor
}

transition_return Etat37::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTVIRGULE:
            p_etat = new Etat38();
            automate.shift(p_etat, s);
            return SHIFTED;
        case VIRGULE:
            p_etat = new Etat39();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat37

Etat38::Etat38()
{
    //ctor
}

Etat38::~Etat38()
{
    //dtor
}

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

Etat39::Etat39()
{
    //ctor
}

Etat39::~Etat39()
{
    //dtor
}

transition_return Etat39::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case IDENTIFICATEUR:
            p_etat = new Etat40();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }
}

//// end Etat39

Etat40::Etat40()
{
    //ctor
}

Etat40::~Etat40()
{
    //dtor
}

transition_return Etat40::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat41();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat40

Etat41::Etat41()
{
    //ctor
}

Etat41::~Etat41()
{
    //dtor
}

transition_return Etat41::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case NOMBRE:
            p_etat = new Etat42();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat41

Etat42::Etat42()
{
    //ctor
}

Etat42::~Etat42()
{
    //dtor
}

transition_return Etat42::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
        /*
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
            */
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat42

Etat43::Etat43()
{
    //ctor
}

Etat43::~Etat43()
{
    //dtor
}

transition_return Etat43::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case POINTEGAL:
            p_etat = new Etat44();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat43

Etat44::Etat44()
{
    //ctor
}

Etat44::~Etat44()
{
    //dtor
}

transition_return Etat44::transition(Automate & automate, Symbole * s)
{
    AbstractEtat * p_etat;
    switch (*s)
    {
        case NOMBRE:
            p_etat = new Etat45();
            automate.shift(p_etat, s);
            return SHIFTED;
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat44

Etat45::Etat45()
{
    //ctor
}

Etat45::~Etat45()
{
    //dtor
}

transition_return Etat45::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case SYMBVARIABLE:
        case CONSTANTE:
        case POINTVIRGULE:
        case VIRGULE:
        case DOLLAR:
        /*
        {
            ListAffectation * p_ListAffectation = new ListAffectation(LISTAFFECTATION);
            p_ListAffectation->setAttribute((Valeur *) automate.depilerSymbole());
            p_ListAffectation->setAttribute((Egal *) automate.depilerSymbole());
            p_ListAffectation->setAttribute((Identificateur *) automate.depilerSymbole());

            automate.reduce(3,p_ListAffectation);
        }
            return REDUCED;
        */
        default:
            cerr << "err" << endl;
            return ERROR;
    }

}

//// end Etat45
