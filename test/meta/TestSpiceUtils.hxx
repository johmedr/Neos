#ifndef TESTSPICEUTILS_HXX
#define TESTSPICEUTILS_HXX

#include "../../include/core/all.hxx"
#include "../../include/meta/all.hxx"
#include "../../include/test/all.hxx"

#include <iostream>

struct TestSpiceUtils : public TestAtom
{
	virtual bool runTests() override
	{
		TEST_ASSERT(is_spice<>::value == false); 
		TEST_ASSERT(is_spice<int>::value == false); 
		TEST_ASSERT(is_spice<Atom<>>::value == true); 
		TEST_ASSERT(is_spice<Spice>::value == true); 
		TEST_ASSERT( (is_spice<Spice, Spice, int, Spice>::value == false) );
		TEST_ASSERT( (is_spice<Spice, Spice, Spice>::value == true) ); 
		TEST_ASSERT( (is_spice<Spice, Atom<>, Atom<>>::value == true) ); 
	}
};

#endif