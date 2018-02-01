#ifndef __ARCH__HXX
#define __ARCH__HXX

#include <core/arch/Module.hxx>
#include <core/arch/__config__.hxx>

namespace arch
{
	namespace __core__ 
	{
		/*
		 *
		 */ 
		template <class ...Ms> 
		class __arch__ : CORE_MODS_ARCH_VIRTUALITY CORE_MODS_ARCH_INHERITANCE Module 
		{
		CORE_MODS_DEFAULT_SCOPE: 
			using __registry__ = ModList<Ms...>; 
			
			// To move ??? 
			// template <class M> 
			// static const bool __contains__ = contains<M, __registry__>::value; 
		};
	}
}


#endif