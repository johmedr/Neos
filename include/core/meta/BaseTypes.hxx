#ifndef METABASETYPES_HXX
#define METABASETYPES_HXX

template <bool B> 
struct bool_type 
{
	static constexpr bool value = B; 
};

struct true_type : public bool_type<true>
{};

struct false_type : public bool_type<false>
{};

template <bool B>
struct bool_func 
{
	constexpr bool operator() () 
	{
		return B; 
	}
};

struct true_func : bool_func<true>
{}; 

struct false_func : bool_func<false>
{};

template <class ...>
struct empty_type
{};

template <class T>
struct t_type
{
	using type = T;
};

using size_t = unsigned long;

#endif