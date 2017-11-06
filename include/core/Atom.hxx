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
}; 

#endif