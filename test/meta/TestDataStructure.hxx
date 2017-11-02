#ifndef TEST_DATA_STRUCTURE_HXX
#define TEST_DATA_STRUCTURE_HXX 

#include "../../include/test/all.hxx"
#include "../../include/meta/all.hxx"

struct TestDataStructure : public TestAtom 
{
	virtual bool runTests() override
	{
		TEST_ASSERT( (equals<
							typename List<>::Head, 
							NIL
						>::value == true) ); 
		TEST_ASSERT( (equals<
							typename List<int, float, bool>::Head, 
							int
						>::value == true) );
		TEST_ASSERT( (equals<
							typename List<bool, char, long, float>::Tail, 
							typename List<char, long, float>::Head
						>::value == true) );
		TEST_ASSERT( (equals<
							typename List<Spice>::Tail, 
							NIL
						>::value == true) ); 
	}
};

#endif