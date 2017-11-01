#ifndef METACONDITIONS_HXX
#define METACONDITIONS_HXX

#include <type_traits>
#include "base_types.hxx"

template <class ...> 
using void_t = void; 

template <bool Condition, class T = void> 
struct enable_if {}; 

template <class T>
struct enable_if<true, T>
{
	using type = T;  
};

template <bool ...Vars>
struct meta_and
{
	static constexpr bool value = (Vars && ...); 
};

template <bool ...Vars>
struct meta_or
{
	static constexpr bool value = (Vars || ...); 
};

template <class Base, class FirstSon, class ...Sons>
struct are_derived_from
{
	static constexpr bool value = std::is_base_of<Base, FirstSon>::value 
								&& are_derived_from<Base, Sons...>::value; 
}; 

template <class Base, class LastSon>
struct are_derived_from<Base, LastSon>
{
	static constexpr bool value = std::is_base_of<Base, LastSon>::value; 
};

template <class ...Args> 
struct is_empty : false_type
{};

template <> 
struct is_empty<> : true_type
{};

#endif 