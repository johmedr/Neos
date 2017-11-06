#ifndef TESTCONDITIONS_HXX
#define TESTCONDITIONS_HXX

#include "../../include/test/all.hxx"
#include "../../include/meta/all.hxx"

struct TestConditions : public TestAtom 
{
	// bool testMetaAnd() 
	// {
	// 	TEST_ASSERT( (meta_and<>::value == false) ); 
	// 	TEST_ASSERT( (meta_and<true>::value == true) ); 
	// 	TEST_ASSERT( (meta_and<false>::value == false) ); 
	// 	TEST_ASSERT( (meta_and<true, true, true>::value == true) ); 
	// 	TEST_ASSERT( (meta_and<false, false, false>::value == false) );
	// 	TEST_ASSERT( (meta_and<true, true, false, true>::value == false) ); 
	// }

	// bool testMetaOr() 
	// {
	// 	TEST_ASSERT( (meta_or<>::value == false) ); 
	// 	TEST_ASSERT( (meta_or<true>::value == true) ); 
	// 	TEST_ASSERT( (meta_or<false>::value == false) ); 
	// 	TEST_ASSERT( (meta_or<true, true, true>::value == true) ); 
	// 	TEST_ASSERT( (meta_or<false, false, false>::value == false) ); 
	// 	TEST_ASSERT( (meta_or<true, false, false, false>::value == true) ); 
	// }


	bool testAreDerivedFrom() 
	{
		TEST_ASSERT( (are_derived_from<int, float>::value == false) ); 
		TEST_ASSERT( (are_derived_from<Spice, Atom<>>::value == true) ); 
		TEST_ASSERT( (are_derived_from<int, float, char, bool>::value == false) );
		TEST_ASSERT( (are_derived_from<Spice, Atom<>, TestAtom>::value == true) );  
	}

	bool testIsEmpty() 
	{
		TEST_ASSERT( (is_empty<>::value == true) ); 
		TEST_ASSERT( (is_empty<int>::value == false) ); 
		TEST_ASSERT( (is_empty<int, float, char, Spice>::value == false) );
	}

	bool testEquals() 
	{
		TEST_ASSERT( (equals<int, float>::value == false) ); 
		TEST_ASSERT( (equals<Atom<>, Spice>::value == false) ); 
		TEST_ASSERT( (equals<char, char>::value == true) ); 
	}

	virtual bool runTests() override 
	{
		// testMetaAnd(); 
		// testMetaOr(); 
		testAreDerivedFrom(); 
		testIsEmpty(); 
		testEquals(); 
	}
};

#endif