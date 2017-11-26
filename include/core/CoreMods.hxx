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
	struct arch : Module 
	{
	protected: 
		using __registry__ = ModList<Ms...>; 
		
		template <class M> 
		using __contains__ = contains<M, __registry__>; 
	};

	template <class ...M>
	struct core : Module
	{
	protected:
		template <class ...Ms>
		struct requires : Module 
		{
			using __requirements__ = ModList<Ms...>; 
		};

		template <class ...Ms>
		struct restricts : Module 
		{
			using __restrictions__ = ModList<Ms...>; 
		};

		template <class ...Ms>
		struct provides : Module
		{
			using __provisions__ = ModList<Ms...>;
		};
	};

	template <class ...Ms>
	struct  __default__ : 
		arch<Ms...>,
		core<Ms...>
	{}; 
}

#endif