#include "ConcreteEtats.h"
#include "Automate.h"

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
            cout << "err" << endl;
            return ERROR;
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
            cout << "err" << endl;
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
            cout << "err" << endl;
            return ERROR;
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
    AbstractEtat * p_etat;
    Symbole * p_programme;
    Symbole * p_ld;
    Symbole * p_lins;
    
    switch (*s)
    {
        case INSTRUCTION:
            p_etat = new Etat5();
            automate.shift(p_etat, s);
            return SHIFTED;
        case ECRIRE:
            p_etat = new Etat6();
            automate.shift(p_etat, s);
            return SHIFTED;
		case LIRE:
            p_etat = new Etat23();
            automate.shift(p_etat, s);
            return SHIFTED;
		case IDENTIFICATEUR:
            p_etat = new Etat25();
            automate.shift(p_etat, s);
            return SHIFTED;
		case DOLLAR:
			p_lins = automate.depilerSymbole();		
			p_ld = automate.depilerSymbole();
			p_programme = new Programme();
			p_programme->setsetListInstruction(p_lins);
			p_programme->setsetListDeclaration(p_ld);
			automate.reduce(2, p_programme);
			return REDUCED;
        default:
            cout << "err" << endl;
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
    AbstractEtat * p_etat;
    switch (*s)
    {
		case DOLLAR:
			automate.reduce(2);
			return REDUCED;
        default:
            cout << "err" << endl;
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
            cout << "err" << endl;
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
			automate.reduce(2);
			return REDUCED;
        default:
            cout << "err" << endl;
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
            cout << "err" << endl;
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
			automate.reduce(3);
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
            cout << "err" << endl;
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
            cout << "err" << endl;
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
}

//// end Etat45
