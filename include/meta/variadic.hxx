#ifndef VARIADIC_HXX
#define VARIADIC_HXX

#include "base_types.hxx"
#include "conditions.hxx"
#include "spice_utils.hxx"

template <class Elt, class First, class ...Rest>
struct contains
{
	static constexpr bool value = (equals<Elt, First>::value || contains<Elt, Rest...>::value);
}; 

template <class Elt, class Last>
struct contains<Elt, Last>
{
	static constexpr bool value = equals<Elt, Last>::value;
};



#endif