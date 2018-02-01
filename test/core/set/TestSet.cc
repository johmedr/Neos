#include <core/set/Set.hxx>
#include <core/meta/Conditions.hxx>

using namespace set; 

class TestSet
{
private: 
	bool testIsIn()
	{
		static_assert( is_in<long, set_type<> >::value == false ); 
		static_assert( is_in<float, set_type< char, int, bool > >::value == false ); 
		static_assert( is_in<char, set_type< char, int, float, long > >::value == true ); 
	}

	bool testAddUnique() 
	{
		using s1 = typename add_unique< float, set_type<> >::type; 
		using s2 = typename add_unique< long, set_type<char, bool, int> >::type; 
		using s3 = typename add_unique< short, set_type<int, float, short> >::type; 

		static_assert( equals<s1, set_type<float>>::value ); 
		static_assert( equals<s2, set_type<long, char, bool, int>>::value ); 
		static_assert( equals<s3, set_type<int, float, short>>::value );
	}

	bool testMakeUnique()
	{
		using s1 = typename make_unique< set_type<> >::type;
		using s2 = typename make_unique< set_type<float, char> >::type; 
		using s3 = typename make_unique< set_type<long, short, long> >::type; 

		static_assert( equals<s1, set_type<>>::value );
		static_assert( equals<s2, set_type<float, char>>::value );
		static_assert( equals<s3, set_type<short, long>>::value ); 
	}


public:	
	bool runTests() 
	{
		testIsIn(); 
		testAddUnique(); 
		testMakeUnique(); 
	} 
}; 

int main() 
{
	TestSet ts; 
	ts.runTests(); 
}