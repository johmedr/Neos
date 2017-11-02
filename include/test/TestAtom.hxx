#ifndef TESTATOM_HXX
#define TESTATOM_HXX 

#include "../core/Atom.hxx"

struct TestAtom : public Atom<>
{
	virtual bool runTests() = 0; 
};

#endif