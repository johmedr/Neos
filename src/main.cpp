#include "../include/core/Atom.hxx"
#include "../test/meta/TestAllMeta.hxx"

int main()
{
	Atom<> at; 
	
	std::cout << std::boolalpha;

	TestAllMeta tam; 
	tam.runTests(); 

	return 0;
}