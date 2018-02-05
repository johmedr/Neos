#ifndef __TYPES__HXX
#define __TYPES__HXX

namespace arch 
{	
	template <typename ...>
	struct empty_type
	{};

	template <typename T>
	struct t_type
	{
		using type = T;
	};

	using size_t = unsigned long;

	template <typename T, T V>
	struct valued_type
	{
		static constexpr T value = V;
	};

	template <bool B> 
	struct bool_type : 
		valued_type<bool, B>
	{};

	struct true_type : 
		bool_type<true>
	{};

	struct false_type : 
		bool_type<false>
	{};	
};

#endif