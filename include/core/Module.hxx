#ifndef MODULE_HXX
#define MODULE_HXX

#include "../meta/conditions.hxx"
#include "../meta/list.hxx"


namespace __core__
{
	template <class ...Ms> 
	class __atom__ : public Ms...
	{};
};

using Module = __core__::__atom__<>;

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
						
#endif 