#ifndef METADATASTRUCTURE_HXX
#define METADATASTRUCTURE_HXX

struct NIL 
{
	using Head = NIL; 
	using Tail = NIL; 
}; 

template <class H = NIL, class ...T>
struct List
{
	using Head = H; 
	using Tail = typename List<T ...>::Head; 
};

template <class H> 
struct List<H>
{
	using Head = H; 
	using Tail = NIL; 
};

#endif