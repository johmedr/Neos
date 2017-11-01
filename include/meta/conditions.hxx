#ifndef METACONDITIONS_HXX
#define METACONDITIONS_HXX

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

#endif 