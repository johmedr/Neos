#ifndef ATOM_HXX
#define ATOM_HXX

#include "../meta/all.hxx"
#include "./Spice.hxx"

template <class ...Spice> 
class Atom : public enable_if<
							(is_spice<Spices ...>::value 
							|| is_empty<Spices ...>::value),
							Spice
						>::type
{ 
public:  
	using Masala = List<Spices ...>;

	template <class S, class T>
	using IfMasalaContains_t = typename enable_if_contains<S, Masala, T>::type; 

	template <class S, class T>
	using IfMasalaNotContains_t = typename enable_if_not_contains<S, Masala, T>::type; 

	template <class T> 
	IfMasalaContains_t<T, bool> 
	__contains__() 
	{
		return true; 
	}

	template <class T>
	IfMasalaNotContains_t<T, bool>
	__contains__() 
	{
		return false;
	}

}; 

#endif