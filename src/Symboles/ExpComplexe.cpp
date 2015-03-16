#include "ExpComplexe.h"

Egal::~Egal()
{
    //dtor
}

Egal::print()
{
	String toPrint =  this.expG.print() + " " +this.op.print() + " " +this.expD.print();
	System.out.println(toPrint);
}