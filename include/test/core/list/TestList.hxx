#ifndef TEST_LIST_HXX
#define TEST_LIST_HXX

#include <core/list/List.hxx>
#include <core/arch/__conditions__.hxx>

using namespace list;

class TestClassList
{
private: 
	bool testNIL() 
	{
		static_assert( equals<typename NIL::Head, NIL>::value ); 
		static_assert( equals<typename NIL::Tail, NIL>::value ); 
	}

	bool testEmptyList()
	{
		static_assert( equals<List<>, NIL>::value ); 
	}	

	bool testOneEltList()
	{
		static_assert( equals<typename List<char>::Head, char>::value ); 
		static_assert( equals<typename List<char>::Tail, NIL>::value );
	}

	bool testMultipleEltList() 
	{
		using l1 = List<int, char>; 
		using l2 = List<List<>, bool, l1>;

		static_assert( equals<typename l1::Head, int>::value ); 
		static_assert( equals<typename l1::Tail, List<char>>::value );

		static_assert( equals<typename l2::Head, NIL>::value ); 
		static_assert( equals<typename l2::Tail, List<bool, l1>>::value );
	}

public: 
	bool runTests() 
	{
		testNIL(); 
		testEmptyList(); 
		testOneEltList(); 
		testMultipleEltList(); 
	}
};


#endif