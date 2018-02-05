#ifndef TEST_VAMPL_HXX
#define TEST_VAMPL_HXX

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

	bool testPushFront() 
	{
		using s0 = typename push_back< TestClass<> >::type; 
		using s1 = typename push_front< TestClass<>, float >::type; 
		using s2 = typename push_front< TestClass<double>, long, int >::type; 
		using s3 = typename push_front< TestClass<short, int, float>, char, short >::type;

		static_assert( equals<s0, TestClass<>>::value );
		static_assert( equals<s1, TestClass<float>>::value );
		static_assert( equals<s2, TestClass<long, int, double>>::value );
		static_assert( equals<s3, TestClass<char, short, short, int, float>>::value );
	}

	bool testPushBack() 
	{
		using s0 = typename push_back< TestClass<> >::type; 
		using s1 = typename push_back< TestClass<>, float >::type; 
		using s2 = typename push_back< TestClass<double>, long, int >::type; 
		using s3 = typename push_back< TestClass<short, int, float>, char, short >::type;

		static_assert( equals<s0, TestClass<>>::value );
		static_assert( equals<s1, TestClass<float>>::value );
		static_assert( equals<s2, TestClass<double, long, int>>::value );
		static_assert( equals<s3, TestClass<short, int, float, char, short>>::value );
	}


	bool testUnpackFirstOrderVArgs()
	{
		using s1 = typename unpack_first_order_vargs< TestClass >::type; 
		using s2 = typename unpack_first_order_vargs< TestClass, float, char >::type; 
		using s3 = typename unpack_first_order_vargs< TestClass, TestClass<float>, char >::type; 
		using s4 = typename unpack_first_order_vargs< TestClass, bool, TestClass<TestClass<long>, char> >::type; 

		static_assert( equals<s1, TestClass<>>::value );
		static_assert( equals<s2, TestClass<float, char>>::value ); 
		static_assert( equals<s3, TestClass<float, char>>::value );
		static_assert( equals<s4, TestClass<bool, TestClass<long>, char>>::value );
	}

	bool testUnpackNOrderVArgs()
	{
		using s1 = typename unpack_n_order_vargs< TestClass >::type; 
		using s2 = typename unpack_n_order_vargs< TestClass, float, char >::type; 
		using s3 = typename unpack_n_order_vargs< TestClass, TestClass<float>, char >::type; 
		using s4 = typename unpack_n_order_vargs< TestClass, bool, TestClass<TestClass<long>, char> >::type; 

		static_assert( equals<s1, TestClass<>>::value );
		static_assert( equals<s2, TestClass<float, char>>::value ); 
		static_assert( equals<s3, TestClass<float, char>>::value );
		static_assert( equals<s4, TestClass<bool, long, char>>::value );
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

#endif