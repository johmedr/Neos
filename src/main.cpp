#include "../include/core/Atom.hxx"
#include "../test/meta/TestSpiceUtils.hxx"
#include "../test/meta/TestVariadic.hxx"

int main()
{
	TestSpiceUtils tsu; 
	TestVariadic tv; 
	tsu.runTests(); 
	tv.runTests();
	Atom<> atom; 
	return 0;
}