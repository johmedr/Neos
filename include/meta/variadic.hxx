#ifndef VARIADIC_HXX
#define VARIADIC_HXX

#include "base_types.hxx"
#include "conditions.hxx"

template <class Elt, class First, class ...Rest>
struct va_contains : conditional<
						(equals<Elt, First>::value || va_contains<Elt, Rest...>::value), 
						true_type, 
						false_type
						>::type
{}; 

template <class Elt, class Last>
struct va_contains<Elt, Last> : conditional<
										equals<Elt, Last>::value, 
										true_type, 
										false_type
									>::type
{};

#endif