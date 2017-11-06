#ifndef ATOM_HXX
#define ATOM_HXX

#include "../meta/all.hxx"
#include "./Spice.hxx"

template <class ...Spices> 
class Atom : public enable_if<
							(is_spice<Spices ...>::value 
							|| is_empty<Spices ...>::value),
							Spice
						>::type
{ 
	using Masala = List<Spices ...>;

	template <class S, class T>
	using IfMasalaContains = enable_if_contains<S, Masala, T>; 

	template <class S, class T>
	using IfMasalaNotContains = enable_if_not_contains<S, Masala, T>; 
	
	template <class...>
	typename IfMasalaNotContains<int, bool>::type
	operator() 
	{
		return false; 
	}

	template <class...>
	typename IfMasalaContains<int, bool>::type
	operator()
	{
		return true; 
	}
}; 

#endif