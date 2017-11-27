#ifndef COREMODS_HXX
#define COREMODS_HXX

#include "./Module.hxx"

namespace __core__
{
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
		template <class ...Ms>
		struct requires : Module 
		{
		protected:
			using __requires__ = ModList<Ms...>; 
		};

		template <class ...Ms>
		struct restricts : Module 
		{
		protected:
			using __restricts__ = ModList<Ms...>; 
		};

		template <class ...Ms>
		struct provides : Module
		{
		protected:
			using __provides__ = ModList<Ms...>;
		};

		// template <class ...Args>
		// struct variable : Module
		// {
			
		// };

		template <class ...Args>
		struct inputs : Module
		{
		protected:
			using __inputs__ = ModList<Ms...>; 
		};

		template <class ...Args> 
		struct outputs : Module
		{
		protected: 
			using __outputs__ = ModList<Ms...>;
		};


	};

	template <class ...M>
	struct test : Module
	{

	};

	template <class ...Ms>
	struct  __default__ : 
		arch<Ms...>,
		core<Ms...>
	{}; 
}

#endif