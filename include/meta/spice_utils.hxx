#ifndef METASPICEUTILS_HXX
#define METASPICEUTILS_HXX

#include "../core/Spice.hxx"
#include "base_types.hxx"
#include <type_traits>

template <class S> 
struct is_spice : std::conditional<
						std::is_base_of<Spice, S>::value, 
						true_type, 
						false_type
						>::type
{};

#endif