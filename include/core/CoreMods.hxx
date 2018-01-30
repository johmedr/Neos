#ifndef COREMODS_HXX
#define COREMODS_HXX

#include <core/CoreMetaDefaultConfig.hxx>
#include <core/Module.hxx>
#include <core/ModuleOperations.hxx>

namespace __core__
{
	template <class ...Ms> 
	struct __arch__ : CORE_MODS_ARCH_VIRTUALITY CORE_MODS_ARCH_INHERITANCE Module 
	{
	CORE_MODS_DEFAULT_SCOPE: 
		using __registry__ = ModList<Ms...>; 
		
		template <class M> 
		static const bool __contains__ = contains<M, __registry__>::value; 

	};

	// Create a namespace coremods inside the class using the virtual public inherit
	template <class ...M>
	struct __coremods__ : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module
	{
		template <class ...Ms>
		struct requires : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module 
		{
		CORE_MODS_DEFAULT_SCOPE:
			using __requires__ = ModList<Ms...>; 
		};
		
		template <class ...Ms>
		struct restricts : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module 
		{
		CORE_MODS_DEFAULT_SCOPE:
			using __restricts__ = ModList<Ms...>; 
		};

		template <class ...Ms>
		struct provides : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module
		{
		CORE_MODS_DEFAULT_SCOPE:
			using __provides__ = ModList<Ms...>;
		};

		// template <class ...Args>
		// struct variable : Module
		// {
			
		// };

		template <class ...Ms>
		struct inputs : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module
		{
		CORE_MODS_DEFAULT_SCOPE:
			using __inputs__ = ModList<Ms...>; 
		};

		template <class ...Ms> 
		struct outputs : CORE_MODS_DEFAULT_VIRTUALITY CORE_MODS_DEFAULT_INHERITANCE Module
		{
		CORE_MODS_DEFAULT_SCOPE: 
			using __outputs__ = ModList<Ms...>;
		};


	};

	template <class ...Ms>
	struct __default__ : 
		__arch__<Ms...>, 
		__coremods__<Ms...>
		{}; 
}

#endif