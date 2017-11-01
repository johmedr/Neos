#include "../include/core/Atom.hxx"
#include "../test/meta/test_spice_utils.hxx"

int main()
{
	TestSpiceUtils tsu; 
	tsu.runTests(); 
	Atom<> atom; 
	return 0;
}