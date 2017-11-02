#include "../include/core/Atom.hxx"
#include "../test/meta/TestSpiceUtils.hxx"
#include "../test/meta/TestVariadic.hxx"
#include "../test/meta/TestDataStructure.hxx"

int main()
{
	TestSpiceUtils tsu; 
	TestVariadic tv; 
	TestDataStructure tds; 
	tsu.runTests(); 
	tv.runTests();
	tds.runTests();
	Atom<> atom; 
	return 0;
}