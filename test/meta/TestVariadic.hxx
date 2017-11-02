#ifndef TEST_VARIADIC
#define TEST_VARIADIC

#include "../../include/meta/all.hxx"
#include "../../include/test/all.hxx"

struct TestVariadic : public TestAtom
{
	virtual bool runTests() override
	{
		TEST_ASSERT( (contains<int, char, bool, long>::value == false) ); 
		TEST_ASSERT( (contains<Atom<>, char, Spice, long, Atom<>>::value == true) );
	}
};

#endif