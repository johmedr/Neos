#ifndef MODULE_OPERATIONS_HXX
#define MODULE_OPERATIONS_HXX

#include <meta/list.hxx>
#include <meta/conditions.hxx>

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