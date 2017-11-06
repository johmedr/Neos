#ifndef VARIADIC_HXX
#define VARIADIC_HXX

#include "base_types.hxx"
#include "conditions.hxx"
#include "spice_utils.hxx"

template <class Elt, class First, class ...Rest>
struct va_contains
{
	static constexpr bool value = (equals<Elt, First>::value || va_contains<Elt, Rest...>::value);
}; 

template <class Elt, class Last>
struct va_contains<Elt, Last>
{
	static constexpr bool value = equals<Elt, Last>::value;
};



#endif