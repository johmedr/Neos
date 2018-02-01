#ifndef METADATASTRUCTURE_HXX
#define METADATASTRUCTURE_HXX

// #include <core/meta/BaseTypes.hxx>

namespace list
{
	struct NIL 
	{
		using Head = NIL; 
		using Tail = NIL; 
	}; 

	namespace __helpers__ 
	{
		template <class H = NIL, class ...T>
		struct ListType
		{
			using Head = H; 
			using Tail = ListType<T ...>; 
		};

		template <class H> 
		struct ListType<H>
		{
			using Head = H; 
			using Tail = NIL; 
		};

		template <size_t Size, class ...Elt>
		struct ListBuilderHelper 
		{
			using type = ListType<Elt...>;
		};

		template <class ...Elt>
		struct ListBuilderHelper<0u, Elt...>
		{
			using type = NIL; 
		};

	}; 

	template <class ...Elt> 
	using List = typename __helpers__::ListBuilderHelper<sizeof...(Elt), Elt...>::type; 
} 

#endif