#include <iostream>

#include <type_traits>
 
struct Module
{};

template <class M1 = Module, class ...Mn>
// M, C 
struct Atom : std::enable_if<std::is_base_of<Module, M1>::value, M1>::type, Atom<Mn...>
{}; 

template <class M> 
struct Atom<M> : std::enable_if<std::is_base_of<Module, M>::value, M>::type  
{}; 

struct a_mod : Module
{
	static const bool a= true; 
};

struct b_mod : Module
{
	static const bool b = true; 
};

struct abis_mod : Module 
{
	static const bool a = false; 
}; 

int main() 
{
	std::cout << std::boolalpha; 
	Atom<> at; 
	std::cout << Atom<a_mod>::a << std::endl; 
	std::cout << Atom<b_mod>::b << std::endl; 
	std::cout << Atom<a_mod, b_mod>::a << Atom<a_mod, b_mod>::b << std::endl;
}