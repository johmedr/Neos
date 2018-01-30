#include <core/Atom.hxx>
#include <meta/conditions.hxx>
#include <test/all.hxx>

class TestCoreMods : TestAtom
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

	bool testAtomRegisty()
	{
		using a1 = Atom<>; 
		using a2 = Atom<a_mod, b_mod>; 
		using a3 = Atom<a_mod, b_mod, c_mod>;

		TEST_ASSERT( (equals<a1::__registry__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__registry__, ModList<a_mod, b_mod>>::value == true) );
		TEST_ASSERT( (equals<a3::__registry__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

	bool testAtomContains() 
	{
		Atom<> a1;
		Atom<a_mod, b_mod> a2;
		Atom<a_mod, b_mod, c_mod> a3;

		TEST_ASSERT( (a1.__contains__<a_mod> == false) );

		TEST_ASSERT( (a2.__contains__<a_mod> == true) );
		TEST_ASSERT( (a2.__contains__<b_mod> == true) ); 
		TEST_ASSERT( (a2.__contains__<c_mod> == false) );

		TEST_ASSERT( (a3.__contains__<a_mod> == true) ); 
		TEST_ASSERT( (a3.__contains__<Atom<>> == false) ); 
	}


public:
	virtual bool runTests() override 
	{
		testAtomContains();
		testAtomRegisty();
	}
};

int main() 
{
	TestCoreMods tcm; 
	tcm.runTests(); 
}
