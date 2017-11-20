#ifndef METASPICEUTILS_HXX
#define METASPICEUTILS_HXX

#include "../core/all.hxx"
#include "base_types.hxx"
#include "conditions.hxx"

#include <type_traits>

template <class ...M>
struct is_module : conditional<
						are_derived_from<Module, M...>::value, 
						true_type, 
						false_type
					>::type
{};

template <>
struct is_module<> : false_type
{};


#endif