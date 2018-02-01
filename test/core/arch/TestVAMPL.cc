#include <core/arch/__va_mpl__.hxx>
#include <core/arch/__conditions__.hxx>

using namespace arch;
using namespace arch::__va_mpl__; 

class TestVAMPL
{
private: 
	template <typename ...Args>
	struct TestStruct
	{}; 

	template <typename ...Args>
	class TestClass
	{}; 

	bool testIsInStruct()
	{
		static_assert( is_in<long, TestStruct<> >::value == false ); 
		static_assert( is_in<float, TestStruct< char, int, bool > >::value == false ); 
		static_assert( is_in<char, TestStruct< char, int, float, long > >::value == true ); 
	}

	bool testAddUniqueStruct() 
	{
		using s1 = typename add_unique< float, TestStruct<> >::type; 
		using s2 = typename add_unique< long, TestStruct<char, bool, int> >::type; 
		using s3 = typename add_unique< short, TestStruct<int, float, short> >::type; 

		static_assert( equals<s1, TestStruct<float>>::value ); 
		static_assert( equals<s2, TestStruct<long, char, bool, int>>::value ); 
		static_assert( equals<s3, TestStruct<int, float, short>>::value );
	}

	bool testMakeUniqueStruct()
	{
		using s1 = typename make_unique< TestStruct<> >::type;
		using s2 = typename make_unique< TestStruct<float, char> >::type; 
		using s3 = typename make_unique< TestStruct<long, short, long> >::type; 

		static_assert( equals<s1, TestStruct<>>::value );
		static_assert( equals<s2, TestStruct<float, char>>::value );
		static_assert( equals<s3, TestStruct<short, long>>::value ); 
	}

	bool testIsInClass()
	{
		static_assert( is_in<long, TestClass<> >::value == false ); 
		static_assert( is_in<float, TestClass< char, int, bool > >::value == false ); 
		static_assert( is_in<char, TestClass< char, int, float, long > >::value == true ); 
	}

	bool testAddUniqueClass() 
	{
		using s1 = typename add_unique< float, TestClass<> >::type; 
		using s2 = typename add_unique< long, TestClass<char, bool, int> >::type; 
		using s3 = typename add_unique< short, TestClass<int, float, short> >::type; 

		static_assert( equals<s1, TestClass<float>>::value ); 
		static_assert( equals<s2, TestClass<long, char, bool, int>>::value ); 
		static_assert( equals<s3, TestClass<int, float, short>>::value );
	}

	bool testMakeUniqueClass()
	{
		using s1 = typename make_unique< TestClass<> >::type;
		using s2 = typename make_unique< TestClass<float, char> >::type; 
		using s3 = typename make_unique< TestClass<long, short, long> >::type; 

		static_assert( equals<s1, TestClass<>>::value );
		static_assert( equals<s2, TestClass<float, char>>::value );
		static_assert( equals<s3, TestClass<short, long>>::value ); 
	}

public:	
	bool runTests() 
	{
		testIsInStruct(); 
		testAddUniqueStruct(); 
		testMakeUniqueStruct(); 
		testIsInClass(); 
		testAddUniqueClass(); 
		testMakeUniqueClass(); 
	} 
}; 

int main() 
{
	TestVAMPL tvampl; 
	tvampl.runTests(); 
}