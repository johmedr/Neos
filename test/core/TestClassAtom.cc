#include <test/all.hxx>
#include <core/all.hxx>

class TestClassAtom : public TestAtom
{
private: 
	struct a_mod : Module
	{
		static const bool a = true; 
	};

	struct abis_mod : Module
	{
		static const bool a = false; 
	};

	struct b_mod : Module 
	{	
		static constexpr bool f() 
		{
			return true; 
		}
	};

	struct c_mod : Module 
	{
		struct c_mod_conf
		{
			int c_val; 
			bool c_func()
			{
				return true; 
			}
		};

		c_mod_conf c; 
	};

	bool testAtomStatic()
	{
		using a1 = Atom<a_mod>;
		using a2 = Atom<a_mod, abis_mod>; 
		using b = Atom<b_mod>; 

		TEST_ASSERT( (a1::a == true) );
		TEST_ASSERT( (a2::a_mod::a == true) );
		TEST_ASSERT( (a2::abis_mod::a == false) );
		TEST_ASSERT( (b::f() == true) ); 
	}

	bool testAtomDynamic()
	{
		Atom<c_mod> atc;
		atc.c.c_val = 5;  
		TEST_ASSERT( (atc.c.c_val == 5) ); 
		TEST_ASSERT( (atc.c.c_func() == true) ); 
	}

	bool testAtomicModuleOverlay()
	{
		using at = Atom<a_mod, abis_mod>; 
		TEST_ASSERT( (at::a_mod::a == true) );
		TEST_ASSERT( (at::abis_mod::a == false) );
	}

public: 
	virtual bool runTests() override
	{
		testAtomStatic(); 
		testAtomDynamic();
		testAtomicModuleOverlay(); 
	}
};

int main() 
{
	TestClassAtom tca; 
	tca.runTests(); 
}