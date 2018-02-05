#include <iostream>
#include "../include/core/arch/__atom__.hxx"

class MyClass
{
public: 
	int fdyn() { return 42; }
	static constexpr int  fstat() { return 42 - 2 * 42; }

	short adyn = 112; 
	static const short astat = 12; 
};

class MyMod : arch::Module 
{
public: 
	using class_inst = MyClass; 
	MyClass instance; 
};

using MyAtom = arch::Atom<MyMod>; 

int main()
{
	MyAtom a; 
	std::cout << "fdyn: " << a.instance.fdyn() << std::endl;
	std::cout << "fstat: " << a.instance.fstat() << std::endl; 
	std::cout << "adyn: " << a.instance.adyn << std::endl; 
	std::cout << "astat: " << a.instance.astat << std::endl;
	// std::cout << "b: " << a.b << std::endl;
	// std::cout << "a: " << a.a << std::endl;
}