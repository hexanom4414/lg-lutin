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
            automate.shift(p_etat);
            return SHIFTED;
        case LISTDECLARATION:
            p_etat = new Etat3();
            automate.shift(p_etat);
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

//// end Etat4


Etat5::Etat5()
{
    //ctor
}

Etat5::~Etat5()
{
    //dtor
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

//// end Etat6


Etat7::Etat7()
{
    //ctor
}

Etat7::~Etat7()
{
    //dtor
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

//// end Etat8


Etat9::Etat9()
{
    //ctor
}

Etat9::~Etat9()
{
    //dtor
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

//// end Etat10


Etat11::Etat11()
{
    //ctor
}

Etat11::~Etat11()
{
    //dtor
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

//// end Etat12


Etat13::Etat13()
{
    //ctor
}

Etat13::~Etat13()
{
    //dtor
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

//// end Etat14


Etat15::Etat15()
{
    //ctor
}

Etat15::~Etat15()
{
    //dtor
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

//// end Etat16


Etat17::Etat17()
{
    //ctor
}

Etat17::~Etat17()
{
    //dtor
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

//// end Etat18


Etat19::Etat19()
{
    //ctor
}

Etat19::~Etat19()
{
    //dtor
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

//// end Etat20


Etat21::Etat21()
{
    //ctor
}

Etat21::~Etat21()
{
    //dtor
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

//// end Etat22


Etat23::Etat23()
{
    //ctor
}

Etat23::~Etat23()
{
    //dtor
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

//// end Etat24


Etat25::Etat25()
{
    //ctor
}

Etat25::~Etat25()
{
    //dtor
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

//// end Etat26

Etat27::Etat27()
{
    //ctor
}

Etat27::~Etat27()
{
    //dtor
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

//// end Etat28

Etat29::Etat29()
{
    //ctor
}

Etat29::~Etat29()
{
    //dtor
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

//// end Etat30

Etat31::Etat31()
{
    //ctor
}

Etat31::~Etat31()
{
    //dtor
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

//// end Etat32

Etat33::Etat33()
{
    //ctor
}

Etat33::~Etat33()
{
    //dtor
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

//// end Etat34

Etat35::Etat35()
{
    //ctor
}

Etat35::~Etat35()
{
    //dtor
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

//// end Etat36

Etat37::Etat37()
{
    //ctor
}

Etat37::~Etat37()
{
    //dtor
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

//// end Etat38

Etat39::Etat39()
{
    //ctor
}

Etat39::~Etat39()
{
    //dtor
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

//// end Etat40

Etat41::Etat41()
{
    //ctor
}

Etat41::~Etat41()
{
    //dtor
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

//// end Etat42

Etat43::Etat43()
{
    //ctor
}

Etat43::~Etat43()
{
    //dtor
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

//// end Etat44

Etat45::Etat45()
{
    //ctor
}

Etat45::~Etat45()
{
    //dtor
}

//// end Etat45
