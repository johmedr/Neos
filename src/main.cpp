#include "../include/core/Atom.hxx"
#include "../test/meta/TestAllMeta.hxx"

int main()
{
	Atom<> at; 

	TestAllMeta tam; 
	tam.runTests(); 

	return 0;
}