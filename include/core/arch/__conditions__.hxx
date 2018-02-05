#ifndef __CONDITIONS__HXX
#define __CONDITIONS__HXX

#include <core/arch/__types__.hxx>
#include <type_traits>

template <typename ...> 
using void_t = void; 

template <typename ...Args> 
struct is_empty : 
	false_type
{};

template <> 
struct is_empty<> : 
	true_type
{};

template <typename T, typename U>
struct equals : 
	false_type
{}; 

template <typename T>
struct equals<T, T> : 
	true_type
{};

template <bool B, typename T, typename U = void>
struct conditional : 
	t_type<U>
{};

template <typename T, typename U>
struct conditional<true, T, U> : 
	t_type<T>
{};

template <bool B, typename T = void> 
struct enable_if : 
	conditional< B, t_type<T>, empty_type<> >::type 
{}; 

template <typename T>
struct enable_if<true, T> : 
	t_type<T>
{};

template <typename Base, typename ...Args>
struct are_derived_from
{};

template <typename Base, typename FirstSon, typename ...Sons>
struct are_derived_from<Base, FirstSon, Sons...> : 
	conditional<(std::is_base_of<Base, FirstSon>::value 
		&& are_derived_from<Base, Sons...>::value), 
			true_type, false_type >::type
{}; 

template <typename Base, typename LastSon>
struct are_derived_from<Base, LastSon> : 
	conditional<(std::is_base_of<Base, LastSon>::value), 
		true_type, false_type >::type
{};

template <typename Base>
struct are_derived_from<Base> : 
	false_type
{};

struct __assert__{};

template <bool B, typename _A = __assert__> 
struct assert 
{
    using result = typename _A::fail;
};

template <> 
struct assert<true> 
{
	using result = true_type; 
};

namespace __helper__ 
{
	struct __build_error__{};
};

template <bool B, typename T, typename _Build = __helper__::__build_error__>
struct build_if : 
	t_type< typename _Build::fail >
{};

template <typename T>
struct build_if<true, T> :
	t_type< T >
{};

#endif