#ifndef ATOM_HXX
#define ATOM_HXX


#include "./Module.hxx"
#include "./CoreMods.hxx"
#include "../meta/all.hxx"

// __atom__ inherit Module, as Ms are Modules (checked below)
// Atom is the interface
template <class ...Ms> 
class Atom : public enable_if<// An Atom inherits __atom__ if Ms are Modules
							(is_module<Ms ...>::value 
							|| is_empty<Ms ...>::value),
							__core__::__atom__<
								__core__::__default__<Ms...>, 
								Ms...
								>
						>::type
{}; 

#endif