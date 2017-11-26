#ifndef COREMODS_HXX
#define COREMODS_HXX

#include "./Module.hxx"

namespace __core__
{
	template <class ...Ms>
	struct __modregistry__ : Module
	{
		using ModuleRegistry = ModList<Ms ...>;

		template <class Mod>
		static constexpr bool __contains__ = contains<
												Mod, 
												ModuleRegistry
											>::value; 

	};



	template <class ...Ms>
	struct  __coremods__ : 
		__modregistry__<Ms...>
	{}; 
}

#endif