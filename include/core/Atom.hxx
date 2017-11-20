#ifndef ATOM_HXX
#define ATOM_HXX

#include "../meta/all.hxx"
#include "./Module.hxx"

template <class ...Modules> 
class Atom : public enable_if<true, 
							// (is_module<Modules ...>::value 
							// || is_empty<Modules ...>::value),
							Module
						>::type
{ 
public:  
	using ModuleRegistry = List<Modules ...>;

	template <class M, class T>
	using IfContainsModule_t = typename enable_if_contains<M, ModuleRegistry, T>::type; 

	template <class M, class T>
	using IfNotContainsModule_t = typename enable_if_not_contains<M, ModuleRegistry, T>::type; 

	template <class T> 
	IfContainsModule_t<T, bool> 
	__contains__() 
	{
		return true; 
	}

	template <class T>
	IfNotContainsModule_t<T, bool>
	__contains__() 
	{
		return false;
	}

}; 

#endif