#ifndef METADATASTRUCTURE_HXX
#define METADATASTRUCTURE_HXX

#include "./conditions.hxx"
#include "./base_types.hxx"
#include <type_traits>

struct NIL 
{
	using Head = NIL; 
	using Tail = NIL; 
}; 

template <class H = NIL, class ...T>
struct List
{
	using Head = H; 
	using Tail = List<T ...>; 
};

template <class H> 
struct List<H>
{
	using Head = H; 
	using Tail = NIL; 
};

template <class Elt, class Lst>
struct find : std::conditional< meta_or< 
										equals< 
											Elt, 
											typename Lst::Head
										>:: value, 
										find<Elt, 
											typename Lst::Tail
										>::value
								>::value, 
								true_type, 
								false_type
						>::type
{};

template <class Elt>
struct find<Elt, NIL> : false_type
{};

template <class Elt, class Lst, class Type = void>
struct enable_if_found : enable_if< find<Elt, Lst>::value, Type >::type
{};

#endif