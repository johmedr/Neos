#ifndef ATOM_HXX
#define ATOM_HXX

#include "../meta/all.hxx"
#include "./Module.hxx"

// __atom__ inherit Module, as Ms are Modules (checked below)
template <class ...Ms> 
class __atom__ : public Ms...
{};

template <>
class __atom__<> : public Module
{};

// Atom is the interface
template <class ...Ms> 
class Atom : public enable_if<// An Atom inherits __atom__ if Ms are Modules
							(is_module<Ms ...>::value 
							|| is_empty<Ms ...>::value),
							__atom__<Ms...>
						>::type
{ 
public:  
	using ModuleRegistry = List<Ms ...>;

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