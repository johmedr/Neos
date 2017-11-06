#ifndef METABASETYPES_HXX
#define METABASETYPES_HXX

struct true_type 
{
	static constexpr bool value = true; 
};

struct false_type
{
	static constexpr bool value = false; 
};

template <class ...>
struct empty_type
{};

template <class T>
struct t_type
{
	using type = T;
};

#endif