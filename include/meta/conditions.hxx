#ifndef METACONDITIONS_HXX
#define METACONDITIONS_HXX

#include "base_types.hxx"
#include <type_traits>

template <class ...> 
using void_t = void; 

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

// template <bool ...Vars>
// struct meta_and : conditional< (Vars && ...), 
// 								true_type, 
// 								false_type
// 							>::type
// {};

// template <> 
// struct meta_and<> : false_type
// {};

// template <bool ...Vars>
// struct meta_or : conditional< ( Vars || ... ),
// 								true_type, 
// 								false_type
// 							>::type
// {};

// template <>
// struct meta_or<> : false_type
// {};

template <class Base, class FirstSon, class ...Sons>
struct are_derived_from : conditional<
								(std::is_base_of<Base, FirstSon>::value 
								&& are_derived_from<Base, Sons...>::value), 
								true_type, 
								false_type
							>::type
{}; 

template <class Base, class LastSon>
struct are_derived_from<Base, LastSon> : conditional<
												(std::is_base_of<Base, LastSon>::value), 
												true_type, 
												false_type
											>::type
{};

#endif 