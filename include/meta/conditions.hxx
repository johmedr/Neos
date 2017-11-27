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
struct conditional : t_type<U>
{};

template <class T, class U>
struct conditional<true, T, U> : t_type<T>
{};

template <bool B, class T = void> 
struct enable_if : conditional<
						B, 
						t_type<T>, 
						empty_type<>
					>::type 
{}; 

template <class T>
struct enable_if<true, T> : t_type<T>
{};

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