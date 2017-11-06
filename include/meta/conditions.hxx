#ifndef METACONDITIONS_HXX
#define METACONDITIONS_HXX

#include "base_types.hxx"
#include <type_traits>

template <class ...> 
using void_t = void; 

template <class ...>
struct is_true_type : false_type
{};

template <>
struct is_true_type<true_type> : true_type
{};

template <class ...Args> 
struct is_empty : false_type
{};

template <> 
struct is_empty<> : true_type
{};

template <class T, class U>
struct equals : false_type
{}; 

template <class T>
struct equals<T, T> : true_type
{};

template <bool B, class T, class U = void>
struct conditional
{
	using type = U; 
};

template <class T, class U>
struct conditional<true, T, U>
{
	using type = T; 
};

template <bool Condition, class T = void> 
struct enable_if 
{}; 

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

template <> 
struct meta_and<> : false_type
{};

template <bool ...Vars>
struct meta_or : conditional< ( Vars || ... ),
								true_type, 
								false_type
							>::type
{};

template <>
struct meta_or<> : false_type
{};

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

#endif 