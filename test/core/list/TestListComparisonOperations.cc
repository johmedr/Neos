#include <core/list/List.hxx>
#include <core/list/ListComparisonOperations.hxx>

using namespace list;

class TestListComparisonOperations
{
private:
	bool testContains() 
	{
		static_assert( contains<int, List<>>::value == false ); 
		static_assert( contains<float, List<int, char, bool>>::value == false ); 
		static_assert( contains<char, List<long, short, char, bool>>::value == true ); 
	}

	bool testIsSubsetOf()
	{
		static_assert( is_sublist_of<List<int, float, char>, List<>>::value == false ); 
		static_assert( is_sublist_of<List<int, float, char>, List<float, char, bool, bool>>::value == false ); 
		static_assert( is_sublist_of<List<int, float, char>, List<float, char, int, bool>>::value == true ); 
	}

	bool testAreDisjoint() 
	{
		static_assert( are_disjoint<List<int, float, char>, List<>>::value == true );
		static_assert( are_disjoint<List<>, List<int, float, char>>::value == true );
		static_assert( are_disjoint<List<int, float, char>, List<float, char, bool, bool>>::value == false ); 
		static_assert( are_disjoint<List<int, float, char>, List<long, double, bool>>::value == true ); 
	}

	using List1 = List<int, char, short>; 


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
		static_assert( testEnableIfNotContains_testF<long>() == false );
		static_assert( testEnableIfContains_testF<int>() == true );
	} 


public: 
	bool runTests() 
	{
		testContains();
		testIsSubsetOf(); 
		testAreDisjoint(); 
		testEnableIfContains(); 
	}
};


int main()
{
	TestListComparisonOperations tlco;
	tlco.runTests(); 
}