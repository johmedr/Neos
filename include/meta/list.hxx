#ifndef METADATASTRUCTURE_HXX
#define METADATASTRUCTURE_HXX

#include <core/Module.hxx>
#include <meta/conditions.hxx>
#include <meta/base_types.hxx>

#include <type_traits>

// introduce constraints list 

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

template <class Lst> 
struct list_is_empty : conditional<
							equals< Lst, List<>>::value, 
							true_type, 
							false_type
							>::type 
{}; 

template <class Elt, class Lst>
struct contains : public conditional< (	
									equals< Elt, typename Lst::Head>::value
								 || contains<Elt, typename Lst::Tail>::value
								 ), 
								 true_type, 
								 false_type
								>::type
{};

template <class Elt>
struct contains<Elt, NIL> : public false_type
{};

template <class SubLst, class Lst>
struct is_sublist_of : public conditional< 
										contains<typename SubLst::Head, Lst>::value 
									&&	is_sublist_of<typename SubLst::Tail, Lst>::value, 
									true_type, 
									false_type
									>::type 
{};

template <class Lst>
struct is_sublist_of<NIL, Lst> : public true_type
{};

template <class Lst1, class Lst2>
struct are_disjoint : public conditional< 
										list_is_empty<Lst1>::value 
									||  list_is_empty<Lst2>::value
									||  (
											!(contains<typename Lst1::Head, Lst2>::value)
										&&  are_disjoint<typename Lst1::Tail, Lst2>::value
										), 
									true_type, 
									false_type
									>::type
{};

template <class Lst2>
struct are_disjoint<NIL, Lst2> : public true_type
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