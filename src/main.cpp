#include "../include/core/Atom.hxx"
#include "../test/meta/TestAllMeta.hxx"

int main()
{
	TestAllMeta tam; 
	tam.runTests(); 

	// TestSpiceUtils tsu; 
	// TestVariadic tv; 
	// TestList tds; 
	// TestConditions tc; 
	// tsu.runTests(); 
	// tv.runTests();
	// tds.runTests();
	// tc.runTests();

	// Atom<int, char, Spice> atom1;
	// Atom<char, bool> atom2; 

	// std::cout << std::boolalpha; 
	// std::cout << atom1() << std::endl;
	// std::cout << atom2() << std::endl;
	return 0;
}