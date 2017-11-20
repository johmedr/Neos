#ifndef TEST_VARIADIC
#define TEST_VARIADIC

#include "../../include/meta/all.hxx"
#include "../../include/test/all.hxx"

struct TestVariadic : public TestAtom
{
public:
	virtual bool runTests() override
	{
		TEST_ASSERT( (va_contains<int, char, bool, long>::value == false) ); 
		TEST_ASSERT( (va_contains<Atom<>, char, Module, long, Atom<>>::value == true) );
	}
};

#endif