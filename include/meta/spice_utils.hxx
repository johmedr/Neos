#ifndef METASPICEUTILS_HXX
#define METASPICEUTILS_HXX

#include "../core/Spice.hxx"
#include "base_types.hxx"

template <class S> 
struct is_spice : false_type
{};

template <> 
struct is_spice<Spice> : true_type
{};

#endif