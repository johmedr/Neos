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
struct contains : 	conditional< (	equals< Elt, typename Lst::Head>:: value
								 || contains<Elt, typename Lst::Tail>::value
								 ), 
								 true_type, 
								 false_type
								>::type
{};

template <class Elt>
struct contains<Elt, NIL> : false_type
{};


template <class Elt, class Lst, class T = void>
using enable_if_contains = typename conditional< contains<Elt, Lst>::value, 
												 t_type<T>, 
												 empty_type<T>
												>::type ; 

template <class Elt, class Lst, class T = void>
using enable_if_not_contains = typename conditional< contains<Elt, Lst>::value, 
													 empty_type<T>,
													 t_type<T>
													>::type; 


#endif