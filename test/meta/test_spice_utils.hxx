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
		std::cout << "is_spice <int> = " << is_spice<int>::value << std::endl; 
		std::cout << "is_spice <Atom> = " << is_spice<Atom<>>::value << std::endl; 
		std::cout << "is_spice <Spice> = " << is_spice<Spice>::value << std::endl; 
		return is_spice<int>::value && is_spice<Atom<>>::value && is_spice<Spice>::value; 
	}

	static const bool runTests()
	{
		return runTestIsSpice(); 
	}
};

#endif