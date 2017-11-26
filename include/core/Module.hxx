#ifndef MODULE_HXX
#define MODULE_HXX

#include "../meta/conditions.hxx"
#include "../meta/list.hxx"

class Module; 

template <class ...M>
struct is_module : conditional<
						are_derived_from<Module, M...>::value, 
						true_type, 
						false_type
					>::type
{};

template <>
struct is_module<> : false_type
{};

template <class ...Ms> 
using ModList = typename enable_if< 
							is_module<Ms...>::value 
							|| is_empty<Ms...>::value, 
							List<Ms...>
						>::type; 

class Module
{
	template <class ...Ms>
	struct __requires__ : ModList<Ms...>
	{}; 

	template <class ...Ms>
	struct __narrows__ : ModList<Ms...>
	{};

	template <class ...Ms> 
	struct __provides__ : ModList<Ms...>
	{}; 
}; 
#endif 