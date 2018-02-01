#include <core/arch/__atom__.hxx>
#include <core/arch/__conditions__.hxx>

using namespace arch;

class TestClassAtom 
{
private:
	bool testModule()
	{
		static_assert( equals< __core__::__atom__<>, Module >::value );
	}

	bool testAtom()
	{
		static_assert( equals< __core__::__atom__<>, Atom<> >::value ); 
		static_assert( equals< __core__::__atom__<int>, Atom<int> >::value ); 
	}

public: 
	virtual bool runTests()
	{
		testModule(); 
		testAtom(); 
	}
}; 

int main()
{
	TestClassAtom tca;
	tca.runTests(); 
}