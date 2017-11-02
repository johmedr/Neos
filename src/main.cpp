#include "../include/core/Atom.hxx"
#include "../test/meta/TestSpiceUtils.hxx"
#include "../test/meta/TestVariadic.hxx"
#include "../test/meta/TestDataStructure.hxx"
#include "../test/meta/TestConditions.hxx"

int main()
{
	TestSpiceUtils tsu; 
	TestVariadic tv; 
	TestDataStructure tds; 
	TestConditions tc; 
	tsu.runTests(); 
	tv.runTests();
	tds.runTests();
	tc.runTests();

	Atom<> atom; 
	return 0;
}