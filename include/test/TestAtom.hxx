#ifndef TESTATOM_HXX
#define TESTATOM_HXX 

#include "../core/Atom.hxx"

struct TestAtom : public Atom<>
{
public: 
	virtual bool runTests() = 0; 
};

#endif