#ifndef ATOM_HXX
#define ATOM_HXX

#include <core/arch/__atom__.hxx>
#include <core/arch/Module.hxx>
#include <core/arch/CoreMods.hxx>
#include <meta/all.hxx>


namespace core
{
	// __atom__ inherit Module, as Ms are Modules (checked below)
	// Atom is the interface
	template <class ...Ms> 
	class Atom : ATOM_VIRTUALITY ATOM_INHERITANCE enable_if<
								// An Atom inherits __atom__ if Ms are Modules
								(is_module<Ms ...>::value
								// Or if Ms is empty
								|| is_empty<Ms ...>::value),

								// It inherits from a __core__::__atom__
								__core__::__atom__<
									// Initializated with the __core__::__default__ module list
									// It is important to pass modules as an argument for __default__, 
									// because it loads a big part of atoms features
									__core__::__default__<Ms...>, 

									// Then the atom is built with inheritance from the 
									// other modules. 
									Ms...
									>
							>::type
	{}; 
};


#endif