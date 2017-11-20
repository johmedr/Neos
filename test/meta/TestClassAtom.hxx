#ifndef TESTCLASSATOM_HXX
#define TESTCLASSATOM_HXX

#include "../../include/test/all.hxx"
#include "../../include/core/Atom.hxx"

class TestClassAtom : public TestAtom
{
private: 
	bool testAtomContains() 
	{
		Atom<> a1; 
		Atom<int, char> a2; 
		Atom<Spice, bool, unsigned long> a3; 

		TEST_ASSERT( (a1.__contains__<int>() == false) );

		TEST_ASSERT( (a2.__contains__<int>() == true) );
		TEST_ASSERT( (a2.__contains__<char>() == true) ); 
		TEST_ASSERT( (a2.__contains__<bool>() == false) );

		TEST_ASSERT( (a3.__contains__<Spice>() == true) ); 
		TEST_ASSERT( (a3.__contains__<Atom<>>() == false) ); 
	}

public: 
	virtual bool runTests() override
	{
		testAtomContains(); 
	}
};


#endif