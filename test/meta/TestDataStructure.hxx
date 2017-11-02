#ifndef TEST_DATA_STRUCTURE_HXX
#define TEST_DATA_STRUCTURE_HXX 

#include "../../include/test/all.hxx"
#include "../../include/meta/all.hxx"

struct TestDataStructure : public TestAtom 
{
	bool testList() 
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
							List<char, long, float>
						>::value == true) );
		TEST_ASSERT( (equals<
							typename List<Spice>::Tail, 
							NIL
						>::value == true) ); 
	} 

	bool testFind() 
	{
		TEST_ASSERT( (find<int, List<>>::value == false) ); 
		TEST_ASSERT( (find<float, List<int, char, bool>>::value == false) ); 
		TEST_ASSERT( (find<char, List<Atom<>, Spice, char, bool>>::value == true) ); 
	}

	bool testEnableIfFound() 
	{ // TODO
	}

	virtual bool runTests() override
	{
		testList(); 
		testFind();
	}
};

#endif