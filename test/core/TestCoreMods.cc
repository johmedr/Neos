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
		using a4 = Atom<a_mod, b_mod, a3>; 

		TEST_ASSERT( (equals<a1::__registry__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__registry__, ModList<a_mod, b_mod>>::value == true) );
		TEST_ASSERT( (equals<a3::__registry__, ModList<a_mod, b_mod, c_mod>>::value == true) );
		TEST_ASSERT( (equals<a4::__registry__, ModList<a_mod, b_mod, c_mod>>::value == true) ); 
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

	bool testAtomRequires() 
	{
		using a1 = Atom<requires<>>; 
		using a2 = Atom<requires<a_mod, b_mod>, a_mod, b_mod>; 
		using a3 = Atom<requires<a_mod, b_mod, c_mod>, a_mod, b_mod, c_mod>; 

		TEST_ASSERT( (equals<a1::__requires__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__requires__, ModList<a_mod, b_mod>>::value == true) ); 
		TEST_ASSERT( (equals<a3::__requires__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

	bool testAtomRestricts()
	{
		using a1 = Atom<restricts<>>; 
		using a2 = Atom<restricts<a_mod, b_mod>>; 
		using a3 = Atom<restricts<a_mod, b_mod, c_mod>>; 

		TEST_ASSERT( (equals<a1::__restricts__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__restricts__, ModList<a_mod, b_mod>>::value == true) ); 
		TEST_ASSERT( (equals<a3::__restricts__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

	bool testAtomProvides() 
	{
		using a1 = Atom<provides<>>; 
		using a2 = Atom<provides<a_mod, b_mod>>; 
		using a3 = Atom<provides<a_mod, b_mod, c_mod>>; 

		TEST_ASSERT( (equals<a1::__provides__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__provides__, ModList<a_mod, b_mod>>::value == true) ); 
		TEST_ASSERT( (equals<a3::__provides__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

	bool testAtomInputs()
	{
		using a1 = Atom<inputs<>>; 
		using a2 = Atom<inputs<a_mod, b_mod>>; 
		using a3 = Atom<inputs<a_mod, b_mod, c_mod>>; 

		TEST_ASSERT( (equals<a1::__inputs__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__inputs__, ModList<a_mod, b_mod>>::value == true) ); 
		TEST_ASSERT( (equals<a3::__inputs__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

	bool testAtomOutputs() 
	{
		using a1 = Atom<outputs<>>; 
		using a2 = Atom<outputs<a_mod, b_mod>>; 
		using a3 = Atom<outputs<a_mod, b_mod, c_mod>>; 

		TEST_ASSERT( (equals<a1::__outputs__, ModList<>>::value == true) );
		TEST_ASSERT( (equals<a2::__outputs__, ModList<a_mod, b_mod>>::value == true) ); 
		TEST_ASSERT( (equals<a3::__outputs__, ModList<a_mod, b_mod, c_mod>>::value == true) );
	}

public:
	virtual bool runTests() override 
	{
		testAtomRegisty();
		testAtomContains();
		testAtomRequires(); 
		testAtomRestricts(); 
		testAtomProvides(); 
		testAtomInputs(); 
		testAtomOutputs(); 
	}
};

int main() 
{
	TestCoreMods tcm; 
	tcm.runTests(); 
}
