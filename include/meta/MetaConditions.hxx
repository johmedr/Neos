#ifndef METACONDITIONS_HXX
#define METACONDITIONS_HXX


template <class ...> 
using void_t = void; 

template <bool Condition, class T = void> 
struct Mxx_enable_if {}; 

template <class T>
struct Mxx_enable_if<true>
{
	using type = T;  
};




#endif 