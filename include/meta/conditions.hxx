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

#endif 