#include <core/meta/Variadic.hxx>

struct TestVariadic 
{
public:
	virtual bool runTests() 
	{
		static_assert( va_contains<int, char, bool, long>::value == false ); 
		static_assert( va_contains<long, char, short, long, char>::value == true );
	}
};


int main() 
{
	TestVariadic tv; 
	tv.runTests(); 
}