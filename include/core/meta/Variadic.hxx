#ifndef VARIADIC_HXX
#define VARIADIC_HXX

#include <core/arch/__types__.hxx>
#include <core/arch/__conditions__.hxx>

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