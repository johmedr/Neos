#include <core/arch/__conditions__.hxx>

using namespace arch;

struct TestConditions 
{
private: 
	bool testConditional()
	{
		using ConditionalResult1 = typename conditional<false, true_type, false_type>::type; 
		using ConditionalResult2 = typename conditional<true, true_type, false_type>::type; 

		static_assert( ConditionalResult1::value == false);
		static_assert( ConditionalResult2::value == true); 
	}

	struct Base
	{}; 
	struct Son : Base
	{}; 
	struct Other
	{}; 
	struct GrandSon : Son 
	{}; 

	bool testAreDerivedFrom() 
	{
		static_assert( are_derived_from<int, float>::value == false); 
		static_assert( are_derived_from<int, float, char, bool>::value == false);
		static_assert( are_derived_from<Base, Son, Other>::value == false );
		static_assert( are_derived_from<Base, Son>::value == true); 
		static_assert( are_derived_from<Base, Son, GrandSon>::value == true);  
	}

	bool testIsEmpty() 
	{
		static_assert( is_empty<>::value == true); 
		static_assert( is_empty<int>::value == false); 
		static_assert( is_empty<int, float, char, bool>::value == false);
	}

	bool testEquals() 
	{
		static_assert( equals<int, float>::value == false); 
		static_assert( equals<short, char>::value == false); 
		static_assert( equals<char, char>::value == true); 
	}

public:
	virtual bool runTests() 
	{
		testConditional();
		testAreDerivedFrom(); 
		testIsEmpty(); 
		testEquals(); 
	}
};

int main()
{
	TestConditions tc; 
	tc.runTests(); 
}