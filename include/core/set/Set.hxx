#ifndef SET_HXX
#define SET_HXX

#include <core/meta/BaseTypes.hxx>

namespace set
{
	template <typename ...TArgs>
	struct set_type
	{}; 

	template <typename TElt, typename TSet> 
	struct is_in : false_type
	{}; 

	template <typename TElt, typename ...TSetTail> 
	struct is_in< TElt, set_type<TElt, TSetTail...> > : true_type
	{}; 

	template <typename TElt, typename TSetHead, typename ...TSetTail>
	struct is_in< TElt, set_type<TSetHead, TSetTail...> > : is_in<TElt, set_type<TSetTail...>>
	{}; 

	template < typename TNewElt, typename TSet, 
				bool TIsIn = is_in<TNewElt, TSet>::value > 
	struct add_unique; 

	template < typename TNewElt, typename ...TSetElts>
	struct add_unique< TNewElt, set_type<TSetElts...>, true >
	{
		using type = set_type<TSetElts...>; 
	}; 

	template < typename TNewElt, typename ...TSetElts>
	struct add_unique< TNewElt, set_type<TSetElts...>, false > 
	{
		using type = set_type<TNewElt, TSetElts...>; 
	};

	template < typename ...TArgs > 
	struct make_unique; 

	///Unpack any variadic struct 
	template < template <typename...> typename TClass, typename ...TClassElts, typename ...TArgs >
	struct make_unique< TClass< TClassElts... >, TArgs... >
	{
		using type = typename make_unique< TClassElts..., TArgs... >::type;
	};

	// Unpack a possible list
	// template < typename ...TSetElts, typename ...TArgs > 
	// struct make_unique< set_type<TSetElts...>, TArgs... >
	// {
	// 	using type = typename make_unique< TSetElts..., TArgs... >::type; 
	// }; 

	// End of recursion
	template <>
	struct make_unique<>
	{
		using type = set_type<>;
	};

	// Recurse and add unique object
	template < typename THead, typename ...TTail >
	struct make_unique< THead, TTail... > 
	{
		using type = typename add_unique< THead, typename make_unique< TTail... >::type >::type;
	};



};

#endif