#include "../include/core/Atom.hxx"
#include "../test/meta/TestSpiceUtils.hxx"
#include "../test/meta/TestVariadic.hxx"
#include "../test/meta/TestList.hxx"
#include "../test/meta/TestConditions.hxx"

int main()
{
	TestSpiceUtils tsu; 
	TestVariadic tv; 
	TestList tds; 
	TestConditions tc; 
	tsu.runTests(); 
	tv.runTests();
	tds.runTests();
	tc.runTests();

	Atom<int, char, Spice> atom1;
	Atom<char, bool> atom2; 

	std::cout << atom1() << std::endl;
	std::cout << atom2() << std::endl;
	return 0;
}