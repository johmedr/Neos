#include <core/list/List.hxx>
#include <core/meta/Conditions.hxx>
#include <test/macro.hxx>

using namespace list;

class TestClassList
{
private: 
	void testNIL() 
	{
		static_assert( equals<typename NIL::Head, NIL>::value ); 
		static_assert( equals<typename NIL::Tail, NIL>::value ); 
	}

	void testEmptyList()
	{
		static_assert( equals<List<>, NIL>::value ); 
	}	

	void testOneEltList()
	{
		static_assert( equals<typename List<char>::Head, char>::value ); 
		static_assert( equals<typename List<char>::Tail, NIL>::value );
	}

	void testMultipleEltList() 
	{
		using l1 = List<int, char>; 
		using l2 = List<List<>, bool, l1>;

		static_assert( equals<typename l1::Head, int>::value ); 
		static_assert( equals<typename l1::Tail, List<char>>::value );

		static_assert( equals<typename l2::Head, NIL>::value ); 
		static_assert( equals<typename l2::Tail, List<bool, l1>>::value );
	}

public: 
	void runTests() 
	{
		testNIL(); 
		testEmptyList(); 
		testOneEltList(); 
		testMultipleEltList(); 
	}
};


int main() 
{
	TestClassList tcl;
	tcl.runTests(); 
}

