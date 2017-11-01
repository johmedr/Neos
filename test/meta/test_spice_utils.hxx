#ifndef TESTSPICEUTILS_HXX
#define TESTSPICEUTILS_HXX

#include "../../include/core/all.hxx"
#include "../../include/meta/all.hxx"
#include <iostream>
struct TestSpiceUtils
{
	template <class S>
	struct test_is_spice : is_spice<S>
	{};

	static const bool runTestIsSpice()
	{
		std::cout << std::boolalpha;
		std::cout << "is_spice <> = " << is_spice<>::value << std::endl;
		std::cout << "is_spice <int> = " << is_spice<int>::value << std::endl; 
		std::cout << "is_spice <Atom<>> = " << is_spice<Atom<>>::value << std::endl; 
		std::cout << "is_spice <Spice> = " << is_spice<Spice>::value << std::endl; 
		std::cout << "is_spice <bool> = " << is_spice<int>::value << std::endl; 
		std::cout << "is_spice <Spice, Spice, int, Spice> = " << is_spice<Spice, Spice, int, Spice>::value << std::endl; 
		std::cout << "is_spice <Spice, Spice, Spice> = " << is_spice<Spice, Spice, Spice>::value << std::endl; 
		std::cout << "is_spice <Spice, Atom<>, Atom<>> = " << is_spice<Spice, Atom<>, Atom<>>::value << std::endl; 
	}

	static const bool runTests()
	{
		return runTestIsSpice(); 
	}
};

#endif