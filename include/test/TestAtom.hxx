#ifndef TESTATOM_HXX
#define TESTATOM_HXX 

#include "../core/Atom.hxx"

struct TestAtom
{
	virtual bool runTests() = 0; 
};

#endif