#ifndef TEST_LIST_HXX
#define TEST_LIST_HXX 

#include "../../include/test/all.hxx"
#include "../../include/meta/all.hxx"

struct TestList : public TestAtom 
{
private: 
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
							typename List<Module>::Tail, 
							NIL
						>::value == true) ); 
	} 

	bool testContains() 
	{
		TEST_ASSERT( (contains<int, List<>>::value == false) ); 
		TEST_ASSERT( (contains<float, List<int, char, bool>>::value == false) ); 
		TEST_ASSERT( (contains<char, List<Atom<>, Module, char, bool>>::value == true) ); 
	}

	using List1 = List<int, char, Module>; 


	template <class Elt, class List = List1, class T = bool>
	typename enable_if_not_contains<Elt, List, T>::type 
	static constexpr testEnableIfNotContains_testF()
	{ 
		return false; 
	}

	template <class Elt, class List = List1, class T = bool>
	typename enable_if_contains<Elt, List, T>::type 
	static constexpr testEnableIfContains_testF() 
	{ 
		return true; 
	}


	bool testEnableIfContains()
	{
		TEST_ASSERT( (testEnableIfNotContains_testF<Atom<>>() == false) );
		TEST_ASSERT( (testEnableIfContains_testF<int>() == true) );
	} 

public: 
	virtual bool runTests() override
	{
		testList(); 
		testContains();
		testEnableIfContains(); 
	}
};

#endif