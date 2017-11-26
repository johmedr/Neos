#ifndef ATOM_HXX
#define ATOM_HXX

#include "../meta/all.hxx"
#include "./Module.hxx"
#include "./CoreMods.hxx"

// __atom__ inherit Module, as Ms are Modules (checked below)
namespace __core__
{
	template <class ...Ms> 
	class __atom__ : public __coremods__<Ms...>, public Ms...
	{};
};

// Atom is the interface
template <class ...Ms> 
class Atom : public enable_if<// An Atom inherits __atom__ if Ms are Modules
							(is_module<Ms ...>::value 
							|| is_empty<Ms ...>::value),
							__core__::__atom__<Ms...>
						>::type
{}; 

#endif