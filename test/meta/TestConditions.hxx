#ifndef TESTCONDITIONS_HXX
#define TESTCONDITIONS_HXX

#include "../../include/core/all.hxx"
#include "../../include/test/all.hxx"
#include "../../include/meta/all.hxx"

struct TestConditions : public TestAtom 
{
private: 
	bool testConditional()
	{
		using ConditionalResult1 = typename conditional<false, true_type, false_type>::type; 
		using ConditionalResult2 = typename conditional<true, true_type, false_type>::type; 

		TEST_ASSERT( (ConditionalResult1::value == false) );
		TEST_ASSERT( (ConditionalResult2::value == true) ); 
	}

	bool testAreDerivedFrom() 
	{
		TEST_ASSERT( (are_derived_from<int, float>::value == false) ); 
		TEST_ASSERT( (are_derived_from<Module, Atom<>>::value == true) ); 
		TEST_ASSERT( (are_derived_from<int, float, char, bool>::value == false) );
		TEST_ASSERT( (are_derived_from<Module, Atom<>, TestAtom>::value == true) );  
	}

	bool testIsEmpty() 
	{
		TEST_ASSERT( (is_empty<>::value == true) ); 
		TEST_ASSERT( (is_empty<int>::value == false) ); 
		TEST_ASSERT( (is_empty<int, float, char, Module>::value == false) );
	}

	bool testEquals() 
	{
		TEST_ASSERT( (equals<int, float>::value == false) ); 
		TEST_ASSERT( (equals<Atom<>, Module>::value == false) ); 
		TEST_ASSERT( (equals<char, char>::value == true) ); 
	}

public:
	virtual bool runTests() override 
	{
		// testMetaAnd(); 
		// testMetaOr(); 
		testConditional();
		testAreDerivedFrom(); 
		testIsEmpty(); 
		testEquals(); 
	}
};

#endif