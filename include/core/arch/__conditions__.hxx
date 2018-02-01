#ifndef __CONDITIONS__HXX
#define __CONDITIONS__HXX

#include <core/arch/__types__.hxx>

namespace arch
{
	template <class ...> 
	using void_t = void; 

	template <class ...Args> 
	struct is_empty : 
		false_type
	{};

	template <> 
	struct is_empty<> : 
		true_type
	{};

	template <class T, class U>
	struct equals : 
		false_type
	{}; 

	template <class T>
	struct equals<T, T> : 
		true_type
	{};

	template <bool B, class T, class U = void>
	struct conditional : 
		t_type<U>
	{};

	template <class T, class U>
	struct conditional<true, T, U> : 
		t_type<T>
	{};

	template <bool B, class T = void> 
	struct enable_if : 
		conditional< B, t_type<T>, empty_type<> >::type 
	{}; 

	template <class T>
	struct enable_if<true, T> : 
		t_type<T>
	{};
};

#endif