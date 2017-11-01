#ifndef METASPICEUTILS_HXX
#define METASPICEUTILS_HXX

#include "../core/Spice.hxx"
#include "base_types.hxx"
#include "conditions.hxx"

#include <type_traits>

template <class ...S>
struct is_spice : std::conditional<
						are_derived_from<Spice, S...>::value, 
						true_type, 
						false_type
						>::type
{};

template <>
struct is_spice<> : true_type
{};

#endif